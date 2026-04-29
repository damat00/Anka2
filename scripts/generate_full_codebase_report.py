#!/usr/bin/env python3
import os
import json
from pathlib import Path

ROOT = Path(r"E:\Anka2")

def categorize(p: Path) -> str:
    s = str(p).lower()
    if "source\\server\\game" in s:
        return "Server Game Core"
    if "source\\server\\db" in s:
        return "Server DB Layer"
    if "source\\server\\library" in s:
        return "Server Libs"
    if "source\\binary" in s:
        return "Client Backend"
    if "tools" in s:
        return "Tools/Build Tools"
    if "foxfs" in s or "foxfs_s" in s or "foxfs_archiver" in s:
        return "FoxFS/Archiver"
    if "dump_proto" in s or "dumpproto" in s:
        return "DumpProto Tools"
    return "Other"

def describe_by_name(name: str) -> str:
    mapping = {
        "main.cpp": "Program entry point; initialization and main loop",
        "char.cpp": "Character model and logic",
        "item.cpp": "Item entity and inventory logic",
        "questlua_target.cpp": "Quest target integration with Lua quest engine",
        "DBManager.cpp": "DB manager: SQL wrapper",
        "ClientManager.cpp": "DB to Game bridge; handles game data from DB",
        "protocol.h": "Packet protocol and serialization",
        "version.cpp": "Versioning control",
        "log.cpp": "Logging to DB and runtime logs"
    }
    base = Path(name).name.lower()
    return mapping.get(base, f"Module in {name}")

def collect() -> list:
    report = []
    for root, dirs, files in os.walk(ROOT):
        for f in files:
            if f.endswith(".cpp") or f.endswith(".py"):
                path = Path(root) / f
                cat = categorize(path)
                desc = describe_by_name(str(path))
                dep = []
                if cat == "Server Game Core":
                    dep = ["libthecore","liblua","db"]
                elif cat == "Server DB Layer":
                    dep = ["libsql","libthecore"]
                elif cat == "Server Libs":
                    dep = ["libthecore","liblua","libgame"]
                elif cat == "Client Backend":
                    dep = ["DirectX","Python","Boost"]
                else:
                    dep = ["Unknown"]
                report.append({
                    "path": str(path),
                    "category": cat,
                    "description": desc,
                    "dependencies": dep,
                    "status": "known"
                })
    return report

def main():
    report = collect()
    mem_path = ROOT / "OpenCodeMemory.json"
    if mem_path.exists():
        try:
            with mem_path.open("r", encoding="utf-8") as f:
                mem = json.load(f)
        except Exception:
            mem = {}
    else:
        mem = {}
    mem.setdefault("codebase_report", [])
    mem["codebase_report"] = report
    # Write a separate codebase report to avoid memory mutation during generation
    with (ROOT / "CodebaseReport.json").open("w", encoding="utf-8") as f:
        json.dump(mem, f, indent=2, ensure_ascii=False)
    print("OpenCodeMemory.json updated with codebase_report")

if __name__ == "__main__":
    main()
