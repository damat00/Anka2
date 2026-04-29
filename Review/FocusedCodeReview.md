Openka2 Focused Code Review (Top Targets)

Top C++ targets (by size/impact)
- Source/Server/game/src/char_item.cpp
- Source/Server/game/src/char.cpp
- Source/Server/game/src/cmd_general.cpp
- Source/Server/db/src/ClientManager.cpp
- Source/Server/game/src/questlua_target.cpp

Top Python targets (by size/impact)
- Tools/archiver/tools/Python27/Lib/topics.py
- Tools/binary_unpack/root/ui.py
- Tools/archiver/tools/Python27/Lib/decimal.py
- Tools/archiver/tools/Python27/Lib/test/test_descr.py
- Tools/binary_unpack/root/ui.py

Why these
- They are large and central to runtime behavior, with potential risk in memory management, data handling and security.

Checklist (per file)
- Build/compile status: compile warnings, missing includes, API changes since last review.
- Memory/Resource safety: RAII usage, smart pointers, scope-bound lifetimes, no leaks in error paths.
- Error handling: robust error codes or exceptions; logging in failure paths.
- Concurrency: thread-safety, locks usage, potential deadlocks.
- Security/validation: safe parsing/serialization, boundaries, input validation.
- Code quality: formatting, modern C++ usage, avoids raw pointers where possible.
- Data flow: verify how data flows between server and client modules; ensure interfaces are well defined.
- Tests: identify missing tests; propose new tests where feasible.

Next steps
- Pick a couple of files to start and report findings; then proceed iteratively.
