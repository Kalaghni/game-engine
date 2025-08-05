# Game Engine Architecture & Implementation Prompt

Act as a senior systems engineer and architect a modern game engine from scratch for cross-platform desktop (Windows, macOS, Linux) and optionally web (WebAssembly). The target language is **C++17**, with a CMake-based build, strict separation of engine and game layers, and strong emphasis on performance, multithreading, and modularity.

## Key Requirements

### Rendering
- Use **OpenGL 4.5 core profile** for 3D and 2D rendering.
- Implement a **renderer abstraction layer** (`IRenderer`) for potential future Vulkan/D3D12 backends.
- Design a low-level graphics API wrapper with resource management (buffers, VAOs, textures, FBOs, shader compilation/error reporting, state caching).
- Architect a **batched 2D renderer** and a **forward+ 3D renderer** supporting basic PBR materials, point/directional lights, and camera transforms.
- Support for instanced rendering, texture atlases, and dynamic batching for 2D.

### Platform Layer
- Implement a platform abstraction for window/context management (use **GLFW**), input (keyboard, mouse, gamepad), file IO, and timing.
- Design as a thin layer—engine core should never directly depend on platform APIs.

### Asset Pipeline
- Design an asset manager that loads and tracks images (PNG, JPG), meshes (OBJ, glTF), audio (WAV, OGG), and shader files.
- Assets should be **reference-counted** and support both synchronous and asynchronous loading (`std::future` or job system).
- Implement **hot-reload** for shaders and other assets.

### ECS/Scene System
- Implement a data-oriented **ECS (Entity-Component-System)** architecture using sparse sets or packed arrays, supporting millions of entities.
- Components should be POD structs, and systems should be decoupled and registered with an update priority.
- Scene graphs for transforms, parent/child hierarchy, and spatial queries (AABB, octree or quadtree for optional culling).

### Core Game Loop
- Implement a **fixed timestep update** with variable render (decoupled physics and rendering).
- Integrate a job system/thread pool for parallelizing system updates and asset loading.
- Provide hooks for pre/post-update, pre/post-render, and per-system profiling.

### Event System
- Implement a **lock-free, thread-safe publish/subscribe event bus** for engine/game communication, using templates for type safety.

### Scripting
- Embed **Lua** as the scripting language.
- Expose engine systems to Lua with a clean API (using `sol2` or similar), allow script hot-reload, and support calling engine-side callbacks from Lua.

### Serialization
- Support binary and JSON serialization for scene and prefab data, with versioning support for forward/backward compatibility.

### Debugging/Tooling
- Include an in-engine debug console (**ImGui**), real-time logging, FPS/memory/profiling overlays, and entity/component browser.
- Implement shader and asset hot-reloading.

---

## MANDATES

- **Show class diagrams** (text or PlantUML if code output is allowed), for the overall engine, the ECS core, and renderer abstraction.
- For each major subsystem:
    - Provide header and implementation skeletons with all main public methods, and detailed inline comments explaining the rationale for class structure, memory layout, and thread safety.
    - Provide real code for the ECS core data structures (e.g., entity registry, sparse set, component pools) and an example System implementation.
    - For the renderer, show the actual OpenGL context creation, resource tracking, shader hot-reload logic, and batched draw submission.
    - For the event system, show lock-free queue or double-buffered event bus design.
    - For scripting, provide code that exposes C++ engine classes to Lua, and a sample Lua script that interacts with a game object.
- **Show example `main.cpp`**: engine initialization, asset loading, main loop, system registration, and game logic integration.
- For every design decision, include a rationale section explaining **why** you chose that approach, referencing real-world engines (Unity, Unreal, Godot, etc.) where relevant.
- **Call out potential pitfalls and possi**
