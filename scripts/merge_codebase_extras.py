#!/usr/bin/env python3
import json
from pathlib import Path

MEM_PATH = Path(r"E:\Anka2\OpenCodeMemory.json")
EXTRAS_PATH = Path(r"E:\Anka2\OpenCodeMemory_codebase_extra.json")

def load_json(p):
    with p.open('r', encoding='utf-8') as f:
        return json.load(f)

def save_json(p, data):
    with p.open('w', encoding='utf-8') as f:
        json.dump(data, f, indent=2, ensure_ascii=False)

def main():
    if not MEM_PATH.exists():
        print("Memory file not found:", MEM_PATH)
        return
    if not EXTRAS_PATH.exists():
        print("Extras file not found:", EXTRAS_PATH)
        return

    mem = load_json(MEM_PATH)
    extras = load_json(EXTRAS_PATH)
    extras_entries = extras.get("codebase_report", []) if isinstance(extras, dict) else []
    current = mem.get("codebase_report", [])
    # Avoid duplicates by path
    existing_paths = {item.get("path"): item for item in current}
    added = 0
    for e in extras_entries:
        p = e.get("path")
        if not p or p in existing_paths:
            continue
        current.append(e)
        added += 1
    mem["codebase_report"] = current
    save_json(MEM_PATH, mem)
    print(f"Merged {added} codebase entries from extras into OpenCodeMemory.json")

if __name__ == "__main__":
    main()
