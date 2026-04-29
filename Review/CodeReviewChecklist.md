Openka2 Code Review Checklist (C++ / Python)

C++ (.cpp/.h)
- Memory management: avoid raw new/delete; prefer RAII, smart pointers.
- Exception safety: strong/guaranteed noexcept where applicable; ensure no leaks on exceptions.
- Resource handling: file handles, sockets, etc. are RAII-wrapped.
- Thread safety: access to shared state guarded by mutexes; avoid data races.
- API boundaries: clear ownership, avoid leaking internals; check header inclusions.
- Modern C++ usage: rely on move semantics, smart containers, and avoid C-style arrays where feasible.
- Error handling: return codes vs exceptions; consistent logging of errors.
- Logging: avoid excessive logging in hot paths; ensure log level controls.
- Security: input validation, buffer bounds, cryptographic usage review (Crypto++ usage in client/lib).
- Build/test: ensure compilation in 32-bit target; verify compile flags.
- Code hygiene: avoid unused code; remove dead code; consistent formatting.
- Known hotspots in this repo: libthecore, liblua, db integration, proto/dump tooling.

Python (.py)
- PEP8/style adherence: line lengths, naming; module imports organized.
- Security: avoid shell escapes, use subprocess with list args.
- Dependency management: avoid global imports, requirements alignment.
- Tests: presence of unit tests; ensure tests exist for critical logic.
- Documentation: docstrings; function/class descriptions where necessary.
- Packaging: scripts/modules have clear entry points; avoid side effects on import.

Deliverables
- Short per-file notes for high-risk files (done in memory or patch as requested).
- If requested, apply small patches to address issues.
