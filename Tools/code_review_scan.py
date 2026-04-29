#!/usr/bin/env python3
import os
import re
import sys
from pathlib import Path

# Simple static scan for common C++/Python issues
CPP_PERIL = [
    r"\bstrcpy\s*\(",
    r"\bsprintf\s*\(",
    r"\bfgets\s*\(",
    r"\bnew\s+[^;]+;;?",  # naive
]
PY_PERIL = [r"\beval\(", r"import\s+os|subprocess|pickle|yaml|exec\(|exec\s*\w+\(" ]

def find_matches(root, patterns):
    hits = []
    for dirpath, dirnames, filenames in os.walk(root):
        for fname in filenames:
            p = os.path.join(dirpath, fname)
            try:
                content = open(p, 'r', encoding='utf-8', errors='ignore').read()
            except Exception:
                continue
            for pat in patterns:
                if re.search(pat, content, re.IGNORECASE):
                    hits.append((p, pat))
    return hits

def main():
    root = Path.cwd()
    cpp_hits = find_matches(str(root), CPP_PERIL)
    py_hits = find_matches(str(root), PY_PERIL)
    print("CPP risky patterns found:", len(cpp_hits))
    for h in cpp_hits[:20]:
        print("CPP:", h[0], "pattern:", h[1])
    print("\nPython risky patterns found:", len(py_hits))
    for h in py_hits[:20]:
        print("PY:", h[0], "pattern:", h[1])

if __name__ == '__main__':
    main()
