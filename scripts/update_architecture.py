import json
from pathlib import Path
import datetime

MEMORY_FILE = Path(r"E:\Anka2\OpenCodeMemory.json")

with open(MEMORY_FILE, "r", encoding="utf-8") as f:
    mem = json.load(f)

mem.setdefault("knowledge_base", {})

mem["knowledge_base"]["architecture"] = {
    "overview": "The codebase uses a split-server architecture typical of Metin2. It consists of a Game Server (live game logic, fast packet processing) and a DB Server (SQL proxy, persistence, caching). They communicate via internal P2P packets.",
    "packet_flow": "Client -> libthecore (descriptor) -> game/input_*.cpp (parser) -> game logic (e.g., char_item.cpp) -> internal packet -> db/ClientManager.cpp -> libsql (AsyncSQL) -> MySQL.",
    "layer_responsibilities": {
        "Source/game": "Live game core. Handles characters, combat, items, skills, dungeons, and packet parsing.",
        "Source/db": "Persistence service. Handles player save/load, guild info, caching, and SQL generation to prevent game server blocking.",
        "Source/common": "Shared structural definitions (tables.h, length.h) used by both game and db servers.",
        "Source/libthecore": "Low-level daemon network & heart omurga (socket, buffer, heart/tick, logging).",
        "Source/libsql": "Asynchronous SQL execution and connection pooling.",
        "Source/liblua": "Embedded Lua engine for the Quest system."
    },
    "design_patterns": [
        "Manager Pattern: Heavy use of singletons/managers (e.g., char_manager.cpp, item_manager.cpp) to store vectors/maps of active game objects.",
        "Domain Splitting: God-objects like Character are split into char.cpp, char_item.cpp, char_battle.cpp, char_skill.cpp to manage complexity.",
        "Event Driven / Timer Queue: Delayed actions (regen, dungeon timers, buffs) use the event queue (event.cpp, libthecore/heart.c)."
    ],
    "key_files": {
        "input_main.cpp": "Main entry point for incoming client gameplay packets.",
        "char.cpp": "Core character object and base state.",
        "char_item.cpp": "Inventory, item usage, and equipment logic.",
        "battle.cpp": "Combat, damage calculation, and attack resolution.",
        "questmanager.cpp": "Central manager for Lua-based scripted events and quests.",
        "ClientManager.cpp": "DB Server's main controller for handling game server SQL requests.",
        "AsyncSQL.cpp": "Asynchronous execution of SQL queries.",
        "desc_client.cpp": "Client network connection (descriptor) handling."
    }
}

log = mem.get("update_log", [])
log.append({"date": datetime.datetime.now().strftime("%Y-%m-%d"), "action": "Validated external architectural documentation against codebase structure and integrated insights into knowledge_base.architecture."})
mem["update_log"] = log

with open(MEMORY_FILE, "w", encoding="utf-8") as f:
    json.dump(mem, f, indent=2, ensure_ascii=False)
    
print("Memory successfully updated with architectural knowledge.")
