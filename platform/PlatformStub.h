#pragma once

#include "Platform.h"
#include <iostream>

//------------------------------------------------------------------------------
// PlatformStub
//------------------------------------------------------------------------------
// Minimal platform implementation used for bootstrapping. In a real engine this
// would be replaced by platform-specific modules (GLFW, SDL, etc.).
class PlatformStub : public Platform {
public:
    bool Initialize() override {
        std::cout << "PlatformStub initialized" << std::endl;
        return true;
    }

    void PollEvents() override {
        // No-op: real implementations would process OS messages here.
    }

    void Shutdown() override {
        std::cout << "PlatformStub shutdown" << std::endl;
    }
};
