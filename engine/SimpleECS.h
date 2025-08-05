#pragma once

#include "IECS.h"

#include <cstdint>
#include <functional>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>

//------------------------------------------------------------------------------
// SimpleECS
//------------------------------------------------------------------------------
// A lightweight Entity-Component-System implementation intended to demonstrate
// how the engine can evolve. Entities are represented by integer IDs and
// components are stored in type-indexed associative containers. Systems can be
// registered as callbacks that are invoked every update.
class SimpleECS : public IECS {
public:
    using Entity = std::uint32_t;
    using SystemFunc = std::function<void(double)>;

    SimpleECS();
    ~SimpleECS() override = default;

    // Creates a new entity identifier.
    Entity CreateEntity();

    // Destroys an entity and removes all associated components.
    void DestroyEntity(Entity entity);

    // Adds a component of type T to the entity. Returns reference to the new
    // component.
    template <typename T, typename... Args>
    T& AddComponent(Entity entity, Args&&... args) {
        auto& store = components_[std::type_index(typeid(T))];
        auto comp = std::make_shared<T>(std::forward<Args>(args)...);
        store[entity] = comp;
        return *comp;
    }

    // Retrieves a component of type T for the given entity. Returns nullptr if
    // the component is absent.
    template <typename T>
    T* GetComponent(Entity entity) {
        auto type = std::type_index(typeid(T));
        auto it = components_.find(type);
        if (it == components_.end()) {
            return nullptr;
        }
        auto it2 = it->second.find(entity);
        if (it2 == it->second.end()) {
            return nullptr;
        }
        return static_cast<T*>(it2->second.get());
    }

    // Removes a component of type T from the entity if present.
    template <typename T>
    void RemoveComponent(Entity entity) {
        auto type = std::type_index(typeid(T));
        auto it = components_.find(type);
        if (it != components_.end()) {
            it->second.erase(entity);
        }
    }

    // Registers a system callback that will be invoked during Update().
    void RegisterSystem(SystemFunc system);

    // Invokes all registered systems with the provided timestep.
    void Update(double delta_time) override;

private:
    Entity next_entity_;
    std::unordered_map<std::type_index, std::unordered_map<Entity, std::shared_ptr<void>>> components_;
    std::vector<SystemFunc> systems_;
};


inline SimpleECS::SimpleECS() : next_entity_(1) {}

inline SimpleECS::Entity SimpleECS::CreateEntity() { return next_entity_++; }

inline void SimpleECS::DestroyEntity(Entity entity) {
    for (auto& [type, store] : components_) {
        store.erase(entity);
    }
}

inline void SimpleECS::RegisterSystem(SystemFunc system) {
    systems_.push_back(std::move(system));
}

inline void SimpleECS::Update(double delta_time) {
    for (auto& system : systems_) {
        system(delta_time);
    }
}

