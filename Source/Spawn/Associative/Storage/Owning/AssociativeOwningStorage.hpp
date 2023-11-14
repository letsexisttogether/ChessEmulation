#pragma once 

#include <memory>

#include "Spawn/Associative/Storage/AssociativeStorage.hpp"

template <class _Association, class _Instance>
class AssociativeOwningStorage :
    public AssociativeStorage<_Association, 
        std::unique_ptr<_Instance>, _Instance*>
{
public:
    using InConteiner = std::unordered_map<_Association, _Instance*>;
    using InstancePointer = std::unique_ptr<_Instance>;

public:
    AssociativeOwningStorage() = default;
    AssociativeOwningStorage(const AssociativeOwningStorage&) = delete; 
    AssociativeOwningStorage(AssociativeOwningStorage&&) = delete; 

    AssociativeOwningStorage(const InConteiner& map)
    {
        for (const auto& [index, pointer] : map)
        {
            this->m_Container[index] = InstancePointer{ pointer };
        }
    }

    virtual ~AssociativeOwningStorage() = default;

    _Instance* GetInstance(const _Association& traits) noexcept(false) override
    {
        return this->Find().get();
    }
    
    AssociativeOwningStorage& operator = (const AssociativeOwningStorage&) 
        = delete;
    AssociativeOwningStorage& operator = (AssociativeOwningStorage&&) 
        = delete;
};
