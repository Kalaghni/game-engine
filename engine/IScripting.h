#pragma once

#include <string>

//------------------------------------------------------------------------------
// IScripting
//------------------------------------------------------------------------------
// Interface for script engine integrations (e.g., Lua). Future implementations
// will expose engine APIs to the scripting environment and allow hot-reloading
// of gameplay logic.
class IScripting {
public:
    virtual ~IScripting() = default;

    // Loads and executes a script file.
    virtual bool ExecuteFile(const std::string& path) = 0;
};
