# Build Sailor Moon: Another Story 1.0.0

Use Windows x64, MinGW-w64 GCC/G++, CMake 3.20 or newer, Ninja and Python 3.
The release used GCC 16.1.0. SDL 3.4.10 source is bundled; no other recomp
workspace or source download is required. Add the compiler tools to PATH.

```powershell
python tools/check_portable_source.py --strict-manifest
cmake -S . -B build/release -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
cmake --build build/release --target Launcher --parallel 2
python tools/check_windows_binary.py build/release/release/Launcher.exe
```

Output: build/release/release/Launcher.exe. SDL and compiler runtimes are linked
statically. Required DLLs are supplied by Windows. The complete compact native
core archive and its receipt in lib are hash-checked by CMake. The default graph
links this supplied MinGW x64 archive, rather than recompiling the core sources.
Use a compatible MinGW x64 toolchain; MSVC cannot consume this archive.

Runtime instructions: README.txt. Never distribute ROMs, Settings.ini, Saves,
Logs or personal Screenshots with a release. CI does not require or fetch a ROM.
