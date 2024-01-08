#pragma once

#include <algorithm>
#include <unordered_map>
#include <stdexcept>

#include "Spawn/Associative/Storage/AssociativeStorage.hpp"

template <class _Association, class _Instance>
class ObjectsStorage : 
    public AssociativeStorage<_Association, _Instance, const _Instance&>
{
public:
    using Super = AssociativeStorage<_Association, _Instance, const _Instance&>;
    using typename Super::Container;

public:
    ObjectsStorage() = default;
    ObjectsStorage(const ObjectsStorage&) = default;
    ObjectsStorage(ObjectsStorage&&) = default;

    ObjectsStorage(const Container& container)
        : Super{ container }
    {}
    ObjectsStorage(Container&& container)
        : Super{ std::move(container) }
    {}

    virtual ~ObjectsStorage() = default;

    const _Instance& GetInstance(const _Association& trait) 
        noexcept(false) override
    {
        return this->Find(trait);
    }

    ObjectsStorage& operator = (const ObjectsStorage&) 
        = delete;
    ObjectsStorage& operator = (ObjectsStorage&&) 
        = delete;
};
