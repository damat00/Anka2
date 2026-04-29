import os
import sys
import json
from pathlib import Path

def relative_path(p, root):
    try:
        rp = os.path.relpath(p, root)
        return rp.replace('/', '\\')
    except Exception:
        return str(p)

def describe_home_file(rel_path):
    # Simple heuristic for common files
    fname = os.path.basename(rel_path).lower()
    mapping = {
        'settings.lua': 'Locale service settings',
        'locale.lua': 'Locale mapping',
        'questlib.lua': 'Quest library and binding',
        'locale_quest.txt': 'Locale quest data',
        'quest_tr\training_grandmaster_skill.lua': 'Turkish grandmaster skill training',
        'training_grandmaster_skill.lua': 'Turkish grandmaster skill training',
        'skill_reset.quest': 'Skill reset quest definition',
        'skill_group.quest': 'Skill group quest definition',
        'welcome.lua': 'NPC welcome dialogue',
    }
    # normalize path to match mapping keys naïvely
    key = rel_path.replace('/', '\\').split('\\')[-1]
    if key in mapping:
        return mapping[key]
    # fallback: use filename without extension as description
    base = os.path.splitext(fname)[0]
    return base if base else 'script'

def describe_client_file(rel_path):
    fname = os.path.basename(rel_path).lower()
    mapping = {
        'metin2.cfg': 'Client startup config',
        'log.txt': 'Client runtime log',
        'locale.cfg': 'Client locale configuration',
    }
    if fname in mapping:
        return mapping[fname]
    # default generic description
    return 'client_asset'

def build_dependency_map(home_root, client_root):
    home_root = str(home_root)
    client_root = str(client_root)
    home_files = []
    client_files = []

    # scan home for relevant files
    for root, dirs, files in os.walk(home_root, topdown=True, onerror=lambda e: None):
        # skip ignore paths if provided by caller (this script does not rely on memory file; user controls)
        for f in files:
            path = os.path.join(root, f)
            ext = os.path.splitext(f)[1].lower()
            if ext in {'.lua', '.quest', '.txt', '.py'}:
                rel = relative_path(path, home_root)
                home_files.append({"path": path, "function": describe_home_file(rel)})

    # scan client for possible files
    for root, dirs, files in os.walk(client_root, topdown=True, onerror=lambda e: None):
        for f in files:
            path = os.path.join(root, f)
            ext = os.path.splitext(f)[1].lower()
            if ext in {'.cfg', '.txt', '.log'}:
                rel = relative_path(path, client_root)
                client_files.append({"path": path, "function": describe_client_file(rel)})

    result = {
        "Home": {
            "dependencies": ["liblua", "libthecore"],
            "files": home_files
        },
        "Client": {
            "dependencies": ["server protocol", "locale_config"],
            "files": client_files
        }
    }
    return result

def main():
    home = os.environ.get('HOME_ROOT', r'E:\\Anka2\\home')
    client = os.environ.get('CLIENT_ROOT', r'E:\\Anka2\\Client')
    out = Path.cwd() / 'OpenCodeDependencyMap.json'
    # Build map
    mapping = build_dependency_map(home, client)
    # If there is an existing file, merge on top (best-effort)
    if out.exists():
        try:
            with out.open('r', encoding='utf-8') as fh:
                existing = json.load(fh)
        except Exception:
            existing = {}
        # simple merge: overwrite Home/Client keys
        existing.update(mapping)
        merged = existing
    else:
        merged = mapping

    with out.open('w', encoding='utf-8') as fh:
        json.dump(merged, fh, indent=2, ensure_ascii=False)
    print(f'OpenCodeDependencyMap.json updated at {out}')

if __name__ == '__main__':
    main()
