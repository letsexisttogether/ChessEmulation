#pragma once

#include <algorithm>
#include <unordered_map>
#include <stdexcept>

#include "Spawn/Associative/AssociativeSpawner.hpp"

template <class _Instance, class _MapIndex>
class AssociativeStorage : public AssociativeSpawner<const _Instance&, _MapIndex>
{
public:
    using Map = std::unordered_map<_MapIndex, _Instance>;

public:
    AssociativeStorage() = default;
    AssociativeStorage(const AssociativeStorage&) = default;
    AssociativeStorage(AssociativeStorage&&) = default;

    AssociativeStorage(const Map& map)
        : m_Map{ map }
    {}
    AssociativeStorage(Map&& map)
        : m_Map{ std::move(map) }
    {}

    virtual ~AssociativeStorage() = default;

    const _Instance& GetInstance(const _MapIndex& traits) 
        noexcept(false) override
    {
        const auto& iter = m_Map.find(traits);

        if (iter == m_Map.end())
        {
            throw std::exception
            {
                "Failed to find such an association in the storage"
            };
        }

        return iter->second;
    }

protected:
    Map m_Map{};
};
