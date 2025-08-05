# Titan Engine: Modern Cross-Platform Game Engine Blueprint

Welcome to the **Titan Engine** specification! This document outlines the requirements, architecture, and engineering mandates for building a cutting-edge, cross-platform game engine targeting professional desktop (Windows, macOS, Linux) and web (WebAssembly) environments. The engine is written in **C++17**, utilizes a **CMake** build system, and is designed with modularity, high performance, and multi-threaded scalability in mind. It enforces strict boundaries between engine and game code for maximum maintainability and extensibility.

## Key Requirements

### Rendering
- Employ **OpenGL 4.5 Core Profile** for high-efficiency 2D and 3D graphics.
- Abstract rendering interfaces via `IRenderer`, allowing seamless migration to Vulkan, Metal, or DirectX backends in the future.
- Implement a comprehensive graphics resource manager: buffers, textures, shaders, framebuffers, and state tracking.
- Integrate a batch-optimized 2D renderer, and a physically-based (PBR) 3D pipeline with forward+ lighting, supporting shadow mapping and environment probes.
- Support instanced drawing, dynamic mesh streaming, and texture array atlases for optimized performance.

### Platform Layer
- Use a platform abstraction for window/context (via **GLFW**), HID input, file access, and high-resolution timing.
- Design all platform-specific code in isolated modules; core engine code must interact via interfaces only.

### Asset Pipeline
- Develop an asset manager for images (PNG/JPG), models (OBJ/glTF), audio (WAV/OGG), and shader assets.
- Reference-count all assets and support async streaming (using futures and a background job system).
- Implement automatic hot-reloading of assets when files are modified.

### ECS/Scene System
- Build a cache-friendly **Entity-Component-System (ECS)** using packed arrays, enabling fast iteration and component lookup.
- Register systems with configurable priorities; support dynamic system creation and teardown.
- Include a transform hierarchy, parent-child relationships, and a spatial partitioning structure (octree/quadtree) for scene culling.

### Core Game Loop
- Design a fixed timestep update loop, decoupled from rendering framerate for determinism.
- Integrate a work-stealing thread pool for parallelized system and asset operations.
- Insert hooks for per-system timing, debugging, and profiling overlays.

### Event System
- Engineer a template-based, thread-safe event bus using double buffering or lock-free queues for efficient inter-system messaging.

### Scripting
- Integrate **Lua** with full access to engine internals via a minimal, idiomatic C++ binding (e.g., sol2).
- Allow hot-reload of scripts, runtime registration of new systems/components, and C++ callbacks from Lua.

### Serialization
- Implement versioned binary and JSON serialization for scenes, prefabs, and runtime state.
- Ensure forward/backward compatibility for save data and project assets.

### Debugging/Tooling
- Embed **ImGui** for an in-engine debug UI: live log viewer, entity/component explorer, and graphics pipeline inspector.
- Include real-time overlays for FPS, memory, thread, and asset statistics.
- Support live asset and shader reloading, breakpoint-style pausing, and state inspection.

---

## MANDATES

- **Provide clear class diagrams** (textual or PlantUML), highlighting the relationships in the core engine, ECS, and rendering architecture.
- For each subsystem:
    - Supply header/implementation skeletons with public APIs and detailed rationale in comments for all design and performance decisions.
    - Deliver real ECS data structure code (entity registry, packed arrays), and a full system example.
    - For rendering, include OpenGL context creation, robust resource management, shader hot-reload, and batched draw call examples.
    - For the event system, show the complete lock-free or double-buffered event bus.
    - For scripting, demonstrate C++/Lua class exposure, and a sample Lua game script.
- **Show a full `main.cpp` usage example:** engine setup, asset preloading, ECS/system registration, main loop, and clean shutdown.
- For every architectural choice, provide an explicit rationale, referencing industry standards (Unity, Unreal, Godot, etc.).
- **Highlight challenges and growth opportunities:** such as integrating a physics engine, adding network support, or building a modular plugin loader.
- At all stages, invite the user to select which subsystem to expand or deepen, and offer curated resources for advanced study.

> **All output must be comprehensive and precise, as if it is the onboarding documentation for a new senior engineer joining a next-generation game engine team.**
