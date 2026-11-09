Sailor Moon: Another Story (SNES) Static Recompilation
Version 1.0.0
Native 64-bit Windows 10 and Windows 11

Running the application
-----------------------
Extract the complete package to a writable folder and run Launcher.exe.
Close Welcome, then use Browse ROM or place your verified ROM in Rom beside
Launcher.exe. The original ROM and translation patch are not included.
No development tools, separate SDL DLL or installer are needed to run it.

Supported ROM and English translation
-------------------------------------
Title: Bishoujo Senshi Sailor Moon - Another Story
Region: Japan NTSC, patched to English v2.08 (1 September 2021)
Translation credits: Bishoujo Senshi Translations, mteam, mziab and vivify93
Format: unheadered .sfc
Size: 4,194,304 bytes
SHA-256: 9690863eea45167e69b522c124b517bdc3457e70dc080ddbf925462a989acec9

Original translation release page:
https://www.romhacking.net/translations/4654/
Translation project discussion:
https://www.romhacking.net/forum/index.php?topic=28632.0
Archived release information:
https://neoromhacking.net/translationpage.php?id=4654

The original site may restrict access. The archived listing identifies the
v2.08 release; it is a mirror, not the translation team's own website.
Use your own legally obtained game and apply the matching translation.
The filename can differ, but the complete patched ROM hash must match.
Additional gameplay patches and other translation versions are not accepted.

Keyboard shortcuts
------------------
Escape  Switch between the game and Launcher; pause or resume
1       Save the selected snapshot slot
2       Load the selected snapshot slot
F1      Welcome and shortcut help
F2      Save Snapshot window
F3      Load Snapshot window
F4      Settings
F5      Controls
F6      Audio Settings
F7      Run the selected ROM
F8      Screenshot

Controls supports configurable one-player keyboard and SDL3 gamepad input.
Choose and remap controls in F5. Disconnecting a gamepad falls back to the
keyboard. The selected input source and bindings persist in Settings.ini.

Settings, saves and snapshots
----------------------------
Settings.ini, Saves, Screenshots and Logs are stored beside Launcher.exe.
Display, input, audio, selected snapshot slot and Welcome preferences persist
locally. An existing legacy game-named INI is migrated only if Settings.ini
does not already exist. Moving the complete folder retains these user files.

Battery-backed game progress and five separate full-machine snapshot slots
are stored under Saves. Snapshots preserve CPU, timing, memory, graphics,
input and audio state. Use matching-build snapshots; incompatible or damaged
files are rejected without replacing the current machine. Saving writes a
temporary file before replacing the destination. A successful load clears
stale frontend audio so playback resumes from the restored machine state.

Static core, graphics and audio
------------------------------
The game's S-CPU and S-SMP executable instructions run as ahead-of-time
native code. Graphics, audio and gameplay are calculated live. There is no
general-purpose CPU interpreter, runtime opcode decoder, JIT, learning system
or emulator fallback. Unknown execution states stop with diagnostic evidence.

All 68,539 exact S-CPU contexts remain in the compacted representation,
using 440 shared native bodies and 747 page wrappers. The 185,876 discovery
records include repeated contexts; they are not 185,876 distinct CPU keys.
Source-byte guards, finite successors and fail-closed behavior are retained.

The core owns NTSC master-clock, raster, DMA/HDMA, input, PPU, S-SMP and
32-phase S-DSP execution. Native audio is 32,000 Hz signed 16-bit stereo.
The frontend streams this PCM through DirectSound with selectable output
rate and resampling. Audio Settings provides device, volume, latency, buffer,
drift correction and underrun recovery options. PCM knownness is diagnostic;
it does not mute native samples. Natural NTSC pacing is mandatory, following
39,375,000 / 655,171 (about 60.0988 frames per second). FPS display is enabled
by default and can be changed in Settings. Windowed/full-screen presentation,
scaling and screenshots are available through the frontend.

Package and licensing
---------------------
Launcher.exe, README.txt, VERSION.txt, THIRD-PARTY-NOTICES.txt, SDL-LICENSE.txt,
and Rom/Screenshots instruction folders form the clean portable package.
ROMs, personal settings, saves, snapshots, logs, captured images and development
tools are excluded. Windows system DLLs are provided by Windows itself.
SDL3 is statically linked and retains its own license. The original game,
translation, graphics and music remain the property of their respective owners.
