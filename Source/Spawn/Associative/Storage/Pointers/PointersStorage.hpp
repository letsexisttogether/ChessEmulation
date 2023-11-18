#pragma once 

#include <memory>

#include "Spawn/Associative/Storage/AssociativeStorage.hpp"

template <class _Association, class _Instance>
class PointersStorage :
    public AssociativeStorage<_Association, 
        std::unique_ptr<_Instance>, _Instance*>
{
public:
    using Super = AssociativeStorage<_Association, 
        std::unique_ptr<_Instance>, _Instance*>;

    using typename Super::Container;
    using InContainer = std::unordered_map<_Association, _Instance*>;

    using InstancePointer = std::unique_ptr<_Instance>;

public:
    PointersStorage() = default;
    PointersStorage(const PointersStorage&) = delete; 
    PointersStorage(PointersStorage&&) = delete; 

    PointersStorage(const InContainer& container)
    {
        for (const auto& [index, pointer] : container)
        {
            this->m_Container[index] = InstancePointer{ pointer };
        }
    }
    PointersStorage(Container&& container)
    {
        for (auto& [index, pointer] : container)
        {
            this->m_Container[index] = std::move(pointer);
        }
    }

    virtual ~PointersStorage() = default;

    _Instance* GetInstance(const _Association& trait) noexcept(false) override
    {
        return this->Find(trait).get();
    }
    
    PointersStorage& operator = (const PointersStorage&) 
        = delete;
    PointersStorage& operator = (PointersStorage&&) 
        = delete;
};
