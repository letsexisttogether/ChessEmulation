#pragma once 

#include <memory>

#include "Spawn/Associative/Storage/AssociativeStorage.hpp"

template <class _Association, class _Instance>
class PointersStorage :
    public AssociativeStorage<_Association, 
        std::unique_ptr<_Instance>, _Instance*>
{
public:
    using InConteiner = std::unordered_map<_Association, _Instance*>;
    using InstancePointer = std::unique_ptr<_Instance>;

public:
    PointersStorage() = default;
    PointersStorage(const PointersStorage&) = delete; 
    PointersStorage(PointersStorage&&) = delete; 

    PointersStorage(const InConteiner& map)
    {
        for (const auto& [index, pointer] : map)
        {
            this->m_Container[index] = InstancePointer{ pointer };
        }
    }

    virtual ~PointersStorage() = default;

    _Instance* GetInstance(const _Association& traits) noexcept(false) override
    {
        return this->Find().get();
    }
    
    PointersStorage& operator = (const PointersStorage&) 
        = delete;
    PointersStorage& operator = (PointersStorage&&) 
        = delete;
};
