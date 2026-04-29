import os
import sys
import json
import re
from pathlib import Path
import datetime
import time

if len(sys.argv) > 1:
    ROOT = Path(sys.argv[1])
else:
    ROOT = Path(r"E:\Anka2\Source")
    
MEMORY_FILE = Path(r"E:\Anka2\OpenCodeMemory.json")

def categorize(p: Path) -> str:
    s = str(p).lower()
    if "server\\game" in s: return "Server Game Core"
    if "server\\db" in s: return "Server DB Layer"
    if "server\\library" in s: return "Server Libs"
    if "binary" in s or "client" in s: return "Client Backend"
    if "tools" in s: return "Tools/Build Tools"
    return "Source Module"

# Pre-compile regex
RE_INCLUDES = re.compile(r'#(?:include|import)\s+[<"]([^>"]+)[>"]')
RE_IMPORTS = re.compile(r'^(?:from|import)\s+([a-zA-Z0-9_]+)', re.MULTILINE)
RE_CLASSES = re.compile(r'(?:class|struct)\s+([A-Za-z0-9_]+)')
RE_FUNCS = re.compile(r'def\s+([A-Za-z0-9_]+)')

def extract_info(filepath):
    desc = f"Module: {filepath.name}"
    deps = set()
    try:
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            # Only read the first 100KB to speed up regex on huge files
            content = f.read(102400)
            
            for match in RE_INCLUDES.finditer(content):
                deps.add(match.group(1))
            for match in RE_IMPORTS.finditer(content):
                deps.add(match.group(1))
            
            classes = RE_CLASSES.findall(content)
            if classes:
                desc = f"Defines classes/structs: {', '.join(classes[:3])}"
            elif filepath.suffix == '.py':
                funcs = RE_FUNCS.findall(content)
                if funcs:
                    desc = f"Python script containing functions like: {', '.join(funcs[:3])}"
    except:
        pass
    return desc, list(deps)[:5]

def main():
    report = []
    print(f"Scanning directory: {ROOT}")
    start_time = time.time()
    
    count = 0
    for root, dirs, files in os.walk(ROOT):
        for f in files:
            if f.endswith(('.cpp', '.h', '.hpp', '.py', '.c', '.cs', '.bat', '.ps1')):
                count += 1
                if count % 1000 == 0:
                    print(f"Processed {count} files... elapsed: {time.time()-start_time:.1f}s")
                path = Path(root) / f
                cat = categorize(path)
                desc, deps = extract_info(path)
                
                report.append({
                    "path": str(path),
                    "category": cat,
                    "description": desc,
                    "dependencies": deps if deps else ["Unknown"],
                    "status": "known"
                })

    print(f"Finished scanning {count} target files in {time.time()-start_time:.1f}s")

    if MEMORY_FILE.exists():
        with open(MEMORY_FILE, "r", encoding="utf-8") as f:
            try:
                mem = json.load(f)
            except:
                mem = {}
    else:
        mem = {}

    existing_report = mem.get("codebase_report", [])
    report_dict = {item["path"]: item for item in existing_report}
    
    for new_item in report:
        report_dict[new_item["path"]] = new_item
        
    mem["codebase_report"] = list(report_dict.values())

    log = mem.get("update_log", [])
    log.append({"date": datetime.datetime.now().strftime("%Y-%m-%d"), "action": f"Auto-scanned {len(report)} files in {ROOT} and appended to codebase_report."})
    mem["update_log"] = log

    with open(MEMORY_FILE, "w", encoding="utf-8") as f:
        json.dump(mem, f, indent=2, ensure_ascii=False)
        
    print(f"Successfully processed {len(report)} files and updated {MEMORY_FILE}.")

if __name__ == "__main__":
    main()
