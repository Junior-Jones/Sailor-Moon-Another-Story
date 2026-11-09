# Sailor Moon: Another Story (SNES) frontend

The native Windows frontend uses the opaque Sailor Moon core API.
The compact static core is supplied by explicit archive and receipt paths
with SHA-256 pins.

Configure `SAILOR_MOON_SDL_SOURCE_DIR`, `SAILOR_MOON_CORE_LIBRARY`,
`SAILOR_MOON_CORE_LIBRARY_SHA256`, `SAILOR_MOON_CORE_RECEIPT`, and
`SAILOR_MOON_CORE_RECEIPT_SHA256`. Supply an extracted local SDL3 source tree
through `SAILOR_MOON_SDL_SOURCE_DIR`; no personal machine path is required.
The build produces Launcher.exe and its release documents.

External ROM: exact4194304-byte Englishv2.08 cartridge, SHA checked by the core.
No512-byte container/trailing bytes/ROM bundling. Native frame256x224,
signed16 stereo32000Hz, exact presentation39375000/655171; host timing never
advances guest clocks. Titles: Launcher; Sailor Moon: Another Story (SNES).
Optional FPS is a host-only overlay, not core framebuffer/title content.

Executable-adjacent runtime data: Saves/sailor-moon-another-story.sav uses
the9296-byte core knownness codec; five separate .smsnap slots; Screenshots;
Settings.ini. SRAM writes use temporary+atomic replacement.
Rejected snapshots preserve live machine/adapter/device queues. Successful
restore flushes host only, retaining restored guest pending PCM.

F1 Welcome; F2/F3 snapshot dialogs;1/2 current-slot save/load; F4 Settings;
F5 Controls; F6 Audio; F7 Run; F8 Screenshot; Escape Play/Launcher. Keyboard
and SDL gamepad bindings/source are persisted, including discovery/hotplug,
disconnect fallback and input latching. Unsupported expanded-view controls
are removed. Windowed screenshots use core pixels; fullscreen uses presented
surface. Welcome retains monitor-aware sizing, modal focus and accessibility.

