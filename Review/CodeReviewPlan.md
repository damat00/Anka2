Openka2 Code Review Plan
Scope
- Focus on core server and client cpp sources and any Python scripts in the repo (Source/Server, Source/Binary, Tools, etc.).
- Identify high-risk areas: memory management, pointer use, exception safety, thread safety, cryptography usage, data validation, and integration points between server and client.

Objectives
- Produce a concise defect/risks list per file/directory.
- Propose mitigation steps and quick wins (linting, modernization, refactors).
- Align with the current architecture (32-bit, C++20 on server, VS-based client).

Approach
- First pass: quick scan for TODO/FIXME, dangerous APIs (strcpy, sprintf, gets, malloc without free, raw new/delete), global state, and missing includes.
- Second pass: identify memory management issues (RAII, smart pointers), exception safety, and resource handling.
- Third pass: review cross-module boundaries (libthecore, liblua, db interactions, proto/data flow).
- Produce a short report per file containing: summary, risk level, recommended fixes, and estimated effort.

Deliverables
- A prioritized checklist in Markdown and an accompanying summary in OpenCodeMemory.json if needed.
- Optional patches to implement safe changes (only with explicit user consent).

Timeline
- 1-2 days for initial pass across top modules; iterative refinement thereafter.

Notes
- This is a planning artifact for identifying issues and does not replace actual testing or building.
