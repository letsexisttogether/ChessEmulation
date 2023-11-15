#pragma once 

#include <unordered_map>
#include <algorithm>

#include "Spawn/Associative/AssociativeSpawner.hpp"

template <class _Association, class _Instance, class _GetResult>
class AssociativeStorage : public AssociativeSpawner<_Association, _GetResult>
{
public:
    using Container = std::unordered_map<_Association, _Instance>;

public:
    AssociativeStorage() = default;

    AssociativeStorage(const Container& container)
        : m_Container{ container }
    {}
    AssociativeStorage(Container&& container)
        : m_Container{ std::move(container) }
    {}

    virtual ~AssociativeStorage() = default;

    virtual _GetResult GetInstance(const _Association& trait) 
        noexcept(false) = 0;
  
protected:
    const _Instance& Find(const _Association& trait) const noexcept(false)
    {
        const auto& iter = m_Container.find(trait);

        if (iter == m_Container.end())
        {
            throw std::exception
            {
                "Failed to find such an association in the storage"
            };
        }

        return iter->second;
    }

    _Instance& Find(const _Association& trait) noexcept(false)
    {
        return const_cast<_Instance&>(
                static_cast<const AssociativeStorage*>(this)->Find(trait));
    }

protected:
    Container m_Container{};
};
