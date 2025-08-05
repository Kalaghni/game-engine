#pragma once

#include <cstdint>

//------------------------------------------------------------------------------
// IInput
//------------------------------------------------------------------------------
// Abstracts user input devices (keyboard, mouse, gamepad). Platform modules
// implement this interface and feed input events to the engine.
class IInput {
public:
    virtual ~IInput() = default;

    // Polls the current state of the input devices.
    virtual void Poll() = 0;

    // Simple query example: checks whether a key is pressed.
    virtual bool IsKeyPressed(std::uint32_t key_code) const = 0;
};
