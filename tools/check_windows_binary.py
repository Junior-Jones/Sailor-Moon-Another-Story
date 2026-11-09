"""Verify x64 output and static runtime linkage without starting the game."""
from pathlib import Path
import subprocess
import sys

path = Path(sys.argv[1])
assert path.is_file(), path
header = subprocess.check_output(['objdump','-f',str(path)], text=True)
assert 'pei-x86-64' in header, header
details = subprocess.check_output(['objdump','-p',str(path)], text=True)
imports = [s.split('DLL Name:',1)[1].strip().lower() for s in details.splitlines() if 'DLL Name:' in s]
system = {'kernel32.dll','user32.dll','gdi32.dll','comdlg32.dll','comctl32.dll',
          'shell32.dll','dsound.dll','winmm.dll','advapi32.dll','ole32.dll',
          'oleaut32.dll','imm32.dll','setupapi.dll','version.dll','msvcrt.dll',
          'ucrtbase.dll','ws2_32.dll','ntdll.dll','rpcrt4.dll','cfgmgr32.dll',
          'hid.dll','bcrypt.dll','dwmapi.dll','shlwapi.dll','wintrust.dll'}
assert imports, 'Missing PE import directory'
assert all(v in system or v.startswith(('api-ms-win-','ext-ms-win-')) for v in imports), imports
print('PASS: Windows x64, system DLLs only: '+', '.join(imports))
