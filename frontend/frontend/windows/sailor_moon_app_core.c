/* Original target adapter. Generic frontend structure comes from Starter SNES;
 * all machine execution goes through the current opaque Sailor Moon API. */
#include "sailor_moon_app_core.h"
#include "sailor_moon_core.h"
#include <windows.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { SM_APP_FIFO=8192u, SM_APP_CHUNK=1024u };
struct SailorMoonRecomp {
    SmCore *core;
    SmCoreOptions options;
    uint8_t *rom;
    uint32_t pixels[SAILOR_MOON_RECOMP_FRAME_WIDTH*SAILOR_MOON_RECOMP_FRAME_HEIGHT];
    uint16_t raw[SM_CORE_PIXELS];
    uint8_t known[SM_CORE_FRAME_KNOWN_BYTES];
    uint16_t width,height;
    uint64_t sequence;
    int16_t fifo[SM_APP_FIFO*2u];
    size_t read_index,write_index,count;
    uint64_t dropped,unknown_pcm,observed_pcm;
    uint64_t last_exported_generation,acked_generation;
    int overflow,failed,force_sram_dirty;
    char error[384];
};

static void sm_app_error(char *out,size_t cap,const char *format,...) {
    va_list args;
    if(out==NULL||cap==0u)return;
    va_start(args,format);(void)vsnprintf(out,cap,format,args);va_end(args);
    out[cap-1u]='\0';
}
static int sm_app_wide(const char *path,wchar_t out[4096]) {
    return path!=NULL&&MultiByteToWideChar(CP_UTF8,MB_ERR_INVALID_CHARS,path,-1,out,4096)>0;
}
static void sm_app_fail(SailorMoonRecomp *a,const char *detail) {
    SmCoreDiagnostic d;
    a->failed=1;
    if(sm_core_diagnostic(a->core,&d))
        sm_app_error(a->error,sizeof(a->error),"%s; status=%u owner=%u address=%06X context=%08X reason=%s",
          detail,(unsigned)d.status,d.failure_owner,d.failure_address,d.scpu_context,d.failure_reason);
    else sm_app_error(a->error,sizeof(a->error),"%s",detail);
}
static int sm_app_capture(SailorMoonRecomp *a) {
    uint64_t sequence;uint16_t width,height;size_t i;
    if(!sm_core_copy_frame(a->core,a->raw,SM_CORE_PIXELS,a->known,SM_CORE_FRAME_KNOWN_BYTES,
                           &width,&height,&sequence))return 0;
    if(width!=SM_CORE_WIDTH||height!=SM_CORE_HEIGHT)return 0;
    a->width=width;a->height=height;a->sequence=sequence;
    for(i=0u;i<SM_CORE_PIXELS;++i){
        uint32_t p=a->raw[i],r=p&31u,g=(p>>5u)&31u,b=(p>>10u)&31u;
        r=(r<<3u)|(r>>2u);g=(g<<3u)|(g>>2u);b=(b<<3u)|(b>>2u);
        a->pixels[i]=(r<<16u)|(g<<8u)|b;
    }
    return 1;
}
static void sm_app_collect(SailorMoonRecomp *a) {
    int16_t samples[SM_APP_CHUNK*2u];uint8_t tags[SM_APP_CHUNK];uint32_t n,i;
    while((n=sm_core_pcm_drain(a->core,samples,tags,SM_APP_CHUNK))!=0u){
        for(i=0u;i<n;++i){
            /* Match the other SNES frontends: the core's signed 16-bit
             * stereo output is the audio authority. Knownness remains a
             * diagnostic counter; it must not punch silent holes into the
             * continuous PCM stream. */
            if(a->count==SM_APP_FIFO){
                a->read_index=(a->read_index+1u)%SM_APP_FIFO;--a->count;
                ++a->dropped;a->overflow=1;
            }
            a->fifo[a->write_index*2u]=samples[i*2u];
            a->fifo[a->write_index*2u+1u]=samples[i*2u+1u];
            a->write_index=(a->write_index+1u)%SM_APP_FIFO;++a->count;
            ++a->observed_pcm;if(tags[i]==0u)++a->unknown_pcm;
        }
    }
}
static void sm_app_clear_output(SailorMoonRecomp *a) {
    a->read_index=0u;a->write_index=0u;a->count=0u;
    a->dropped=0u;a->overflow=0;a->observed_pcm=0u;a->unknown_pcm=0u;
    a->sequence=0u;a->width=SM_CORE_WIDTH;a->height=SM_CORE_HEIGHT;
    memset(a->pixels,0,sizeof(a->pixels));memset(a->known,0,sizeof(a->known));
}
int sailor_moon_recomp_create(SailorMoonRecomp **out,const uint8_t *rom,size_t size,
                              char *error,size_t cap) {
    SailorMoonRecomp *a;SmCoreStatus status;
    if(out==NULL||rom==NULL||size!=SM_CORE_ROM_BYTES){
        sm_app_error(error,cap,"The exact 4,194,304-byte English-patched Sailor Moon ROM is required.");return 0;
    }
    a=calloc(1u,sizeof(*a));
    if(a==NULL){sm_app_error(error,cap,"Cannot allocate frontend adapter.");return 0;}
    a->rom=malloc(size);
    if(a->rom==NULL){free(a);sm_app_error(error,cap,"Cannot retain immutable ROM input.");return 0;}
    memcpy(a->rom,rom,size);sm_core_options_deterministic_zero_storage_apuio_v1(&a->options);
    a->core=sm_core_create(a->rom,size,NULL,0u,&a->options,&status);
    if(a->core==NULL){free(a->rom);free(a);sm_app_error(error,cap,"Core create rejected ROM/profile (status %u).",(unsigned)status);return 0;}
    sm_app_clear_output(a);*out=a;return 1;
}
void sailor_moon_recomp_destroy(SailorMoonRecomp *a) {
    if(a==NULL)return;
    sm_core_destroy(a->core);free(a->rom);free(a);
}
int sailor_moon_recomp_reset(SailorMoonRecomp *a,char *error,size_t cap) {
    SmCoreStatus status;
    if(a==NULL){sm_app_error(error,cap,"No game is loaded.");return 0;}
    status=sm_core_cold_restart(a->core);
    if(status!=SM_CORE_OK){sm_app_error(error,cap,"Cold restart failed (status %u).",(unsigned)status);return 0;}
    (void)sm_core_set_pad(a->core,0u,0u,0xffffu);
    (void)sm_core_set_pad(a->core,1u,0u,0xffffu);
    sm_app_clear_output(a);a->failed=0;a->error[0]='\0';a->force_sram_dirty=1;
    a->last_exported_generation=0u;a->acked_generation=0u;return 1;
}
static int sm_app_advance(SailorMoonRecomp *a,uint16_t input,uint32_t frames,
    SailorMoonRecompAudioProgressCallback progress,void *context,SailorMoonRecompFrameResult *result) {
    uint32_t i;SmCoreDiagnostic d;
    if(result!=NULL)memset(result,0,sizeof(*result));
    if(a==NULL||a->failed)return 0;
    if(result!=NULL){result->start_frame=(uint32_t)a->sequence;result->input_mask=input;}
    if(sm_core_set_pad(a->core,0u,input,0xffffu)!=SM_CORE_OK){sm_app_fail(a,"Controller report rejected");return 0;}
    for(i=0u;i<frames;++i){
        uint64_t steps=0u;
        /*
         * Mesen, Gundam Wing and Rock n' Roll Racing hand one accumulated
         * frame block to the speaker path.  Calling DirectSound for every
         * 128 native frames made its protected write cursor overtake and
         * realign the producer several times inside one Sailor Moon frame.
         * The DSP FIFO holds well over one natural frame, so collect once at
         * the frame boundary and retain the existing callback there.
         */
        SmCoreRunResult run=sm_core_run_to_frame(a->core,2000000u,10000000u,&steps,NULL,NULL);
        sm_app_collect(a);
        if(run!=SM_CORE_FRAME_READY){sm_app_fail(a,run==SM_CORE_BUDGET?"Natural frame budget exhausted":"Machine owner stopped");break;}
        if(!sm_app_capture(a)){sm_app_fail(a,"Published frame unavailable or invalid geometry");break;}
        if(progress!=NULL)progress(a,context);
    }
    if(result!=NULL){
        result->end_frame=(uint32_t)a->sequence;result->route_continued=(uint8_t)!a->failed;
        result->frame_rendered=(uint8_t)(result->end_frame!=result->start_frame);
        if(a->failed)sm_app_error(result->renderer_error,sizeof(result->renderer_error),"%s",a->error);
    }
    if(sm_core_diagnostic(a->core,&d)&&d.status!=SM_CORE_OK)a->failed=1;
    return !a->failed;
}
int sailor_moon_recomp_advance(SailorMoonRecomp *a,uint16_t input,uint32_t n,SailorMoonRecompFrameResult *r){return sm_app_advance(a,input,n,NULL,NULL,r);}
int sailor_moon_recomp_advance_streamed(SailorMoonRecomp *a,uint16_t input,uint32_t n,SailorMoonRecompAudioProgressCallback p,void *ctx,SailorMoonRecompFrameResult *r){return sm_app_advance(a,input,n,p,ctx,r);}
const uint32_t *sailor_moon_recomp_frame_bgra(const SailorMoonRecomp *a){return a!=NULL?a->pixels:NULL;}
uint32_t sailor_moon_recomp_frame_width(const SailorMoonRecomp *a){return a!=NULL?a->width:SM_CORE_WIDTH;}
uint32_t sailor_moon_recomp_current_frame(const SailorMoonRecomp *a){return a!=NULL?(uint32_t)a->sequence:0u;}
uint64_t sailor_moon_recomp_instruction_count(const SailorMoonRecomp *a){SmCoreDiagnostic d;return a!=NULL&&sm_core_diagnostic(a->core,&d)?d.scpu_instructions:0u;}
int sailor_moon_recomp_failed(const SailorMoonRecomp *a){SmCoreDiagnostic d;return a==NULL||a->failed||(sm_core_diagnostic(a->core,&d)&&d.status!=SM_CORE_OK);}
const char *sailor_moon_recomp_last_error(const SailorMoonRecomp *a){return a!=NULL?a->error:"No game loaded";}
size_t sailor_moon_recomp_audio_available(const SailorMoonRecomp *a){return a!=NULL?a->count:0u;}
size_t sailor_moon_recomp_audio_read(SailorMoonRecomp *a,int16_t *out,size_t capacity){
    size_t n,i;if(a==NULL||out==NULL)return 0u;n=capacity<a->count?capacity:a->count;
    for(i=0u;i<n;++i){out[i*2u]=a->fifo[a->read_index*2u];out[i*2u+1u]=a->fifo[a->read_index*2u+1u];a->read_index=(a->read_index+1u)%SM_APP_FIFO;}
    a->count-=n;return n;
}
size_t sailor_moon_recomp_audio_discard(SailorMoonRecomp *a){size_t n;if(a==NULL)return 0u;n=a->count;a->read_index=a->write_index;a->count=0u;return n;}
int sailor_moon_recomp_audio_overflowed(const SailorMoonRecomp *a){return a!=NULL?a->overflow:0;}
uint64_t sailor_moon_recomp_audio_dropped_frames(const SailorMoonRecomp *a){return a!=NULL?a->dropped:0u;}
void sailor_moon_recomp_audio_clear_overflow(SailorMoonRecomp *a){if(a!=NULL)a->overflow=0;}

int sailor_moon_recomp_sram_copy(const SailorMoonRecomp *a,void *out,size_t cap){
    uint64_t generation;
    if(a==NULL||out==NULL||cap<SM_CORE_SRAM_BYTES)return 0;
    if(sm_core_encode_sram(a->core,out,SM_CORE_SRAM_BYTES,&generation)!=SM_CORE_OK)return 0;
    ((SailorMoonRecomp *)a)->last_exported_generation=generation;return 1;
}
int sailor_moon_recomp_sram_load(SailorMoonRecomp *a,const void *data,size_t size,char *error,size_t cap){
    SmCoreDiagnostic d;SmCoreStatus status;SmCore *candidate;
    if(a==NULL||data==NULL||size!=SM_CORE_SRAM_BYTES||!sm_core_diagnostic(a->core,&d)||d.scpu_instructions!=0u){sm_app_error(error,cap,"Battery data must be a complete 9296-byte codec loaded before game execution.");return 0;}
    candidate=sm_core_create(a->rom,SM_CORE_ROM_BYTES,data,size,&a->options,&status);
    if(candidate==NULL){sm_app_error(error,cap,"Battery data rejected (status %u); current core retained.",(unsigned)status);return 0;}
    sm_core_destroy(a->core);a->core=candidate;sm_app_clear_output(a);
    a->last_exported_generation=0u;a->acked_generation=0u;a->force_sram_dirty=0;return 1;
}
int sailor_moon_recomp_sram_dirty(const SailorMoonRecomp *a){uint8_t bytes[SM_CORE_SRAM_BYTES];uint64_t generation;if(a==NULL)return 0;if(a->force_sram_dirty)return 1;return sm_core_encode_sram(a->core,bytes,sizeof(bytes),&generation)==SM_CORE_OK&&generation!=a->acked_generation;}
void sailor_moon_recomp_sram_mark_clean(SailorMoonRecomp *a){if(a!=NULL&&sm_core_ack_sram(a->core,a->last_exported_generation)){a->acked_generation=a->last_exported_generation;a->force_sram_dirty=0;}}

int sailor_moon_recomp_snapshot_save(const SailorMoonRecomp *a,const char *path,char *error,size_t cap){
    wchar_t wide[4096],temporary[4096];LARGE_INTEGER stamp;HANDLE file;
    size_t size,offset=0u;uint8_t *image;int okay=1;DWORD written;
    if(a==NULL||!sm_app_wide(path,wide)){sm_app_error(error,cap,"Invalid snapshot path.");return 0;}
    size=sm_core_snapshot_size(a->core);image=size!=0u?malloc(size):NULL;
    if(image==NULL||!sm_core_snapshot_save(a->core,image,size)){free(image);sm_app_error(error,cap,"Snapshot requires a healthy quiescent core.");return 0;}
    (void)QueryPerformanceCounter(&stamp);
    if(_snwprintf(temporary,4096,L"%ls.tmp-%lu-%llu",wide,(unsigned long)GetCurrentProcessId(),(unsigned long long)stamp.QuadPart)<0){free(image);sm_app_error(error,cap,"Snapshot path is too long.");return 0;}
    temporary[4095]=L'\0';file=CreateFileW(temporary,GENERIC_WRITE,0u,NULL,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL);
    if(file==INVALID_HANDLE_VALUE){free(image);sm_app_error(error,cap,"Cannot create snapshot temporary file.");return 0;}
    while(offset<size){DWORD count=(DWORD)(size-offset>1048576u?1048576u:size-offset);if(!WriteFile(file,image+offset,count,&written,NULL)||written!=count){okay=0;break;}offset+=written;}
    if(okay&&!FlushFileBuffers(file))okay=0;
    if(!CloseHandle(file))okay=0;
    free(image);
    if(okay&&!MoveFileExW(temporary,wide,MOVEFILE_REPLACE_EXISTING|MOVEFILE_WRITE_THROUGH))okay=0;
    if(!okay){(void)DeleteFileW(temporary);sm_app_error(error,cap,"Snapshot write failed; prior slot retained.");return 0;}
    return 1;
}
int sailor_moon_recomp_snapshot_load(SailorMoonRecomp *a,const char *path,char *error,size_t cap){
    wchar_t wide[4096];FILE *file;size_t size,got;int trailing,okay;uint8_t *image;
    if(a==NULL||!sm_app_wide(path,wide)){sm_app_error(error,cap,"Invalid snapshot path.");return 0;}
    size=sm_core_snapshot_size(a->core);image=size!=0u?malloc(size):NULL;
    if(image==NULL){sm_app_error(error,cap,"Cannot allocate snapshot candidate.");return 0;}
    file=_wfopen(wide,L"rb");if(file==NULL){free(image);sm_app_error(error,cap,"Cannot open snapshot.");return 0;}
    got=fread(image,1u,size,file);trailing=fgetc(file);okay=!ferror(file)&&got==size&&trailing==EOF;
    if(fclose(file)!=0)okay=0;
    if(!okay||!sm_core_snapshot_load(a->core,image,size)){free(image);sm_app_error(error,cap,"Snapshot rejected; live machine and queued audio retained.");return 0;}
    free(image);
    /* Only a committed load clears stale host output. Guest pending PCM is
     * preserved by the core and transferred through its ordinary drain. */
    sm_app_clear_output(a);a->failed=0;a->error[0]='\0';a->force_sram_dirty=1;
    (void)sm_app_capture(a);sm_app_collect(a);return 1;
}
static int sm_app_log(const SailorMoonRecomp *a,const char *path,const char *section,const char *screen,int append,char *error,size_t cap){
    wchar_t wide[4096];FILE *f;SmCoreDiagnostic d;SmCoreTiming t;uint8_t identity[32];size_t i;int okay;
    if(a==NULL||!sm_app_wide(path,wide)||!sm_core_diagnostic(a->core,&d)||!sm_core_timing(&t)){sm_app_error(error,cap,"Diagnostic input unavailable.");return 0;}
    f=_wfopen(wide,append?L"ab":L"wb");if(f==NULL){sm_app_error(error,cap,"Cannot open diagnostic log.");return 0;}
    (void)fprintf(f,"\n%s\nSailor Moon: Another Story (SNES)\nScreenshot=%s\n",section!=NULL?section:"Core diagnostic",screen!=NULL?screen:"");
    (void)fprintf(f,"Build=");if(sm_core_build_identity(identity))for(i=0u;i<32u;++i)(void)fprintf(f,"%02x",identity[i]);
    (void)fprintf(f,"\nStatus=%u Owner=%u Address=%06X Sample=%02X/%02X Reason=%s\nCPU=%06X Key=%08X Instructions=%llu Cycles=%llu Master=%llu Raster=%u/%u Fields=%llu Published=%llu\n",(unsigned)d.status,d.failure_owner,d.failure_address,d.failure_value,d.failure_known_mask,d.failure_reason,d.scpu_address,d.scpu_context,(unsigned long long)d.scpu_instructions,(unsigned long long)d.cpu_cycles,(unsigned long long)d.master_clock,d.scanline,d.hclock,(unsigned long long)d.completed_fields,(unsigned long long)d.published_sequence);
    (void)fprintf(f,"MasterHz=%u/%u Presentation=%u/%u SMPHz=%u PCMRate=%u SMPRatio=%u/%u Remainder=%u SMPcycles=%llu CompletedHalf=%llu APUphase=%u SPC=%04X Active=%04X DSPphase=%u\n",t.master_numerator,t.master_denominator,t.presentation_numerator,t.presentation_denominator,t.smp_hz,t.pcm_hz,t.smp_ratio_numerator,t.smp_ratio_denominator,d.smp_remainder,(unsigned long long)d.smp_cycles,(unsigned long long)d.completed_half,d.apu_phase,d.smp_pc,d.smp_active_pc,d.dsp_phase);
    (void)fprintf(f,"PPUmode=%u/%02X Blank=%u Brightness=%u Main=%02X/%02X Renderer=%u/%u At=%u,%u Address=%06X\nVoices=%02X/%02X PCMFrames=%llu Known=%llu Unknown=%llu FIFO=%u Overflow=%llu Hash=%016llX\nAdapterFIFO=%zu AdapterDropped=%llu AdapterObserved=%llu AdapterUnknown=%llu\n",d.ppu_mode,d.ppu_mode_known,d.ppu_blank,d.ppu_brightness,d.ppu_main,d.ppu_main_known,d.render_status,d.render_dependency,d.render_x,d.render_y,d.render_address,d.active_voice_mask,d.active_voice_known_mask,(unsigned long long)d.pcm.frames,(unsigned long long)d.pcm.known_frames,(unsigned long long)d.pcm.unknown_frames,d.pcm.frames_available,(unsigned long long)d.pcm.overflows,(unsigned long long)d.pcm.pcm_hash,a->count,(unsigned long long)a->dropped,(unsigned long long)a->observed_pcm,(unsigned long long)a->unknown_pcm);
    okay=!ferror(f);if(fclose(f)!=0)okay=0;return okay;
}
int sailor_moon_recomp_write_diagnostic_log(const SailorMoonRecomp *a,const char *path,const char *screen,char *error,size_t cap){return sm_app_log(a,path,"Current joined core",screen,0,error,cap);}
int sailor_moon_recomp_append_diagnostic_log(const SailorMoonRecomp *a,const char *path,const char *section,char *error,size_t cap){return sm_app_log(a,path,section,NULL,1,error,cap);}
