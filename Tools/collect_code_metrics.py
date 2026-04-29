#!/usr/bin/env python3
import os
import json
import sys
from pathlib import Path

ROOT = Path(r"E:\Anka2")

def scan_extensions(exts):
    return [e.lower() for e in exts]

def gather(root: Path):
    cpp_count = 0
    py_count = 0
    total_cpp_lines = 0
    total_py_lines = 0
    todos = []
    file_sizes = []
    for dirpath, dirnames, filenames in os.walk(root):
        for f in filenames:
            p = Path(dirpath) / f
            try:
                suf = p.suffix.lower()
            except Exception:
                continue
            if suf == '.cpp':
                cpp_count += 1
                size = p.stat().st_size
                file_sizes.append({"path": str(p), "size": size, "ext": ".cpp"})
                try:
                    with p.open('r', encoding='utf-8', errors='ignore') as fh:
                        for i, line in enumerate(fh, 1):
                            total_cpp_lines += 1
                            if 'TODO' in line or 'FIXME' in line:
                                todos.append({"path": str(p), "line": i, "text": line.strip()})
                except Exception:
                    pass
            elif suf == '.py':
                py_count += 1
                size = p.stat().st_size
                file_sizes.append({"path": str(p), "size": size, "ext": ".py"})
                try:
                    with p.open('r', encoding='utf-8', errors='ignore') as fh:
                        for i, line in enumerate(fh, 1):
                            total_py_lines += 1
                            if 'TODO' in line or 'FIXME' in line:
                                todos.append({"path": str(p), "line": i, "text": line.strip()})
                except Exception:
                    pass
    return {
        'cpp_count': cpp_count,
        'py_count': py_count,
        'cpp_lines': total_cpp_lines,
        'py_lines': total_py_lines,
        'largest_files': sorted(file_sizes, key=lambda x: x['size'], reverse=True)[:10],
        'todos': todos
    }

def main():
    meta = gather(ROOT)
    with open(ROOT / 'CodeMetrics.json', 'w', encoding='utf-8') as f:
        json.dump(meta, f, indent=2, ensure_ascii=False)
    print('Code metrics written to CodeMetrics.json')

if __name__ == '__main__':
    main()
