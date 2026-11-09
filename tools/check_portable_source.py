"""UW export portability/manifest check, adapted for Sailor Moon."""
from pathlib import Path
import argparse
import csv
import hashlib
import re

root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser()
parser.add_argument('--strict-manifest', action='store_true')
args = parser.parse_args()
if args.strict_manifest:
    rows = list(csv.DictReader((root/'SOURCE-MANIFEST.csv').open(encoding='utf-8')))
    expected = {r['path'] for r in rows}
    actual = {p.relative_to(root).as_posix() for p in root.rglob('*') if p.is_file()
              and not any(v in ('.git','build','__pycache__') for v in p.relative_to(root).parts)
              and p.name != 'SOURCE-MANIFEST.csv'}
    assert actual == expected, f'Manifest paths differ: {actual ^ expected}'
    for row in rows:
        assert hashlib.sha256((root/row['path']).read_bytes()).hexdigest() == row['sha256'], row['path']
for path in root.rglob('*'):
    rel = path.relative_to(root)
    if not path.is_file() or any(v in ('.git','build','__pycache__') for v in rel.parts):
        continue
    data = path.read_bytes()
    if rel.as_posix() == 'third_party/SDL3/include/SDL3/SDL_filesystem.h':
        data = re.sub(rb'[A-Za-z]:[/\\]+Users[/\\]+bob[/\\]', b'example/', data)
    private = rb'[A-Za-z]:' + rb'[/\\]+Users[/\\]'
    assert not re.search(private, data, re.I), f'Private path: {rel}'
    assert not re.search(private, data.replace(b'\0',b''), re.I), f'Private UTF-16 path: {rel}'
    assert path.suffix.lower() not in ('.smc','.sfc','.rom','.sav','.srm','.state','.smsnap','.exe','.dll','.obj','.pdb'), rel
    assert path.name.lower() != 'settings.ini', rel
for unit in (root/'static-core/sources.txt').read_text().splitlines():
    if unit.strip():
        assert (root/unit).is_file(), f'Missing core source: {unit}'
print('PASS: source inventory, portability, no ROMs or personal runtime data'
      + ('; exact release manifest verified' if args.strict_manifest else ''))
