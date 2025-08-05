#pragma once

#include <string>

//------------------------------------------------------------------------------
// IAssetManager
//------------------------------------------------------------------------------
// Manages loading, caching, and hot-reloading of game assets. Asset types may
// include textures, meshes, audio, and scripts. Implementations should be
// thread-safe and support asynchronous loading for performance.
class IAssetManager {
public:
    virtual ~IAssetManager() = default;

    // Loads an asset identified by path. Implementations may return handles or
    // pointers; for now we use a void pointer placeholder.
    virtual void* LoadAsset(const std::string& path) = 0;

    // Releases a previously loaded asset.
    virtual void UnloadAsset(void* handle) = 0;
};
