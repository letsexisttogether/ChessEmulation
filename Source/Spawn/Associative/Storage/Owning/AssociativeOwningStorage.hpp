#pragma once 

#include <algorithm>
#include <stdexcept>
#include <unordered_map>
#include <memory>

#include "Spawn/Associative/AssociativeSpawner.hpp"

template <class _Instance, class _MapIndex>
class AssociativeOwningStorage 
    : public AssociativeSpawner<_Instance*, _MapIndex> 
{
public:
    using InstancePointer = std::unique_ptr<_Instance>;

    using InMap = std::unordered_map<_MapIndex, _Instance*>;
    using Map = std::unordered_map<_MapIndex, InstancePointer>;

public:
    AssociativeOwningStorage() = default;
    AssociativeOwningStorage(const AssociativeOwningStorage&) = delete; 
    AssociativeOwningStorage(AssociativeOwningStorage&&) = delete; 

    AssociativeOwningStorage(InMap&& map)
    {
        for (auto& [index, pointer] : map)
        {
            m_Map[index] = InstancePointer{ pointer };
        }
    }

    ~AssociativeOwningStorage() = default;

    _Instance* GetInstance(const _MapIndex& traits) noexcept(false) override
    {
        const auto& iter = m_Map.find(traits);

        if (iter == m_Map.end())
        {
            throw std::exception
            {
                "Failed to find such a pointer in the storage"
            };
        }

        return iter->second.get();
    }
    
    AssociativeOwningStorage& operator = (const AssociativeOwningStorage&) 
        = delete;
    AssociativeOwningStorage& operator = (AssociativeOwningStorage&&) 
        = delete;
    
protected:
    Map m_Map{};
};
