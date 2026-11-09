# Sailor Moon: Another Story — Windows 1.0.0

[![Windows CI](https://github.com/Junior-Jones/Sailor-Moon-Another-Story/actions/workflows/windows-ci.yml/badge.svg)](https://github.com/Junior-Jones/Sailor-Moon-Another-Story/actions/workflows/windows-ci.yml)

Native SNES static recompilation for Windows 10/11 x64.
Japanese title: **Bishoujo Senshi Sailor Moon: Another Story**
(美少女戦士セーラームーン Another Story).

Download the Windows ZIP from [Releases](https://github.com/Junior-Jones/Sailor-Moon-Another-Story/releases),
extract it, and run Launcher.exe. Supply your own Japan NTSC ROM patched with the
English translation **v2.08**. No ROM, game assets or translation patch is included.
The launcher checks the exact supported ROM before loading it.

Translation patch: https://www.romhacking.net/translations/4654/

Please report any issues you encounter through
[GitHub Issues](https://github.com/Junior-Jones/Sailor-Moon-Another-Story/issues).

## Supported ROM

Unheadered, English v2.08 patched Japan NTSC image: 4,194,304 bytes.
SHA-256: `9690863eea45167e69b522c124b517bdc3457e70dc080ddbf925462a989acec9`.
Apply the patch according to its included instructions. Other ROMs or patches
are rejected. You must obtain the game separately.

## Features and scope

Portable keyboard/gamepad frontend, fullscreen, FPS display, screenshots,
native stereo audio, battery saves, and five save/load snapshot slots.
Settings, saves, screenshots and diagnostic logs live beside the executable.
Natural NTSC pacing is approximately 60.0988 FPS.
See README.txt for controls and VERSION.txt for release details.

The core retains 68,539 exact context keys in 440 shared native bodies and
747 page wrappers. The discovery ledger contains 185,876 repeat-inclusive records.
No runtime interpreter, JIT or emulator fallback is enabled.

Opening gameplay through leaving Usagi's house and reaching OSA-P was exercised
by an autonomous headed replay. This is not a complete-game certification.
CI runs without the copyrighted ROM and verifies the build and packaging inputs.

## Build and source

See [BUILDING.md](BUILDING.md). The production frontend, selected compact core
sources, matched MinGW x64 core archive and SDL 3.4.10 source are included.
The default build links the supplied, hash-checked core archive.
`static-core/sources.txt` lists the core translation units for provenance;
the default build does not rebuild that archive. No neighboring project or
private drive layout is required. SOURCE-MANIFEST.csv records export hashes.

SDL retains its upstream zlib license; see SDL-LICENSE.txt and
THIRD-PARTY-NOTICES.txt for frontend provenance. Game and translation rights
remain with their respective owners. This project does not grant rights to them.
See .github/CONTRIBUTING.md and SECURITY.md for reporting guidance.
