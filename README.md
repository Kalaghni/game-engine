# Titan Engine

Titan Engine is a modern C++17 game engine blueprint designed for cross-platform desktop and web targets. The repository provides a minimal yet extensible foundation with a clear separation between engine, platform layer, and sample game code.

## Features
- Modular architecture with `engine`, `platform`, and `game` modules
- OpenGL-focused rendering interfaces with future backend flexibility
- Entity Component System and event bus foundations
- Catch2-based unit tests

## Project Layout
- `engine/` – core engine components
- `platform/` – platform abstraction layer
- `game/` – example application using the engine
- `tests/` – unit tests
- `third_party/` – external libraries

## Building
```bash
cmake -S . -B build
cmake --build build
```

## Running Tests
```bash
ctest --test-dir build
```

## Contributing
Please build the project and run all tests before submitting a pull request. See [AGENTS.md](AGENTS.md) for additional contributor guidelines.
