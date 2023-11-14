#pragma once

#include <algorithm>
#include <unordered_map>
#include <stdexcept>

#include "Spawn/Associative/Storage/AssociativeStorage.hpp"

template <class _Association, class _Instance>
class DefaultAssociativeStorage : 
    public AssociativeStorage<_Association, _Instance, const _Instance&>
{
public:
    using Super = AssociativeStorage<_Association, _Instance, const _Instance&>;
public:
    DefaultAssociativeStorage() = default;
    DefaultAssociativeStorage(const DefaultAssociativeStorage&) = default;
    DefaultAssociativeStorage(DefaultAssociativeStorage&&) = default;

    DefaultAssociativeStorage(const Container& map)
        : Super{ map }
    {}
    DefaultAssociativeStorage(Container&& map)
        : Super{ std::move(map) }
    {}

    virtual ~DefaultAssociativeStorage() = default;

    const _Instance& GetInstance(const _Association& trait) 
        noexcept(false) override
    {
        return this->Find(trait);
    }

    DefaultAssociativeStorage& operator = (const DefaultAssociativeStorage&) 
        = delete;
    DefaultAssociativeStorage& operator = (DefaultAssociativeStorage&&) 
        = delete;
};
