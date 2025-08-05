#pragma once

//------------------------------------------------------------------------------
// IECS
//------------------------------------------------------------------------------
// Placeholder interface for the Entity-Component-System. Real implementation
// will provide cache-friendly storage, system registration, and scene
// management. This stub defines the minimal contract for future expansion.
class IECS {
public:
    virtual ~IECS() = default;

    // Updates all registered systems using a fixed timestep.
    virtual void Update(double delta_time) = 0;
};
