#pragma once

//------------------------------------------------------------------------------
// IRenderer
//------------------------------------------------------------------------------
// Interface for rendering backends. The engine interacts with rendering through
// this API, enabling future replacement of the underlying graphics API (OpenGL,
// Vulkan, Metal, etc.) without touching engine or game code.
class IRenderer {
public:
    virtual ~IRenderer() = default;

    // Prepares graphics resources and state. Returns false on failure.
    virtual bool Initialize() = 0;

    // Renders a single frame. Delta time is provided for time-based effects.
    virtual void RenderFrame(double delta_time) = 0;

    // Releases graphics resources.
    virtual void Shutdown() = 0;
};
