#pragma once

#include <vector>
#include <memory>

#include "Spawn/Associative/Storage/AssociativeStorage.hpp"

template <class _Association, class _Instance>
class AssociativeTemplate :
    public AssociativeStorage<_Association, _Instance, _Instance*>
{
public:
    using Super = AssociativeStorage<_Association, _Instance, _Instance*>;
    using typename Super::Container;

    using InstancePointer = std::unique_ptr<_Instance>;
    using PointerContainer = std::vector<InstancePointer>;

public:
    AssociativeTemplate() = default;
    AssociativeTemplate(const AssociativeTemplate&) = default;
    AssociativeTemplate(AssociativeTemplate&&) = default;

    AssociativeTemplate(const Container& container)
        : Super{ container }
    {}
    AssociativeTemplate(Container&& container)
        : Super{ std::move(container) }
    {}

    virtual ~AssociativeTemplate() = default;

    _Instance* GetInstance(const _Association& trait) noexcept(false) override
    {
        _Instance* instance = new _Instance{ this->Find(trait) }; 

        m_Pointers.push_back(InstancePointer{ instance });

        return instance;
    }

    AssociativeTemplate& operator = (const AssociativeTemplate&) 
        = delete;
    AssociativeTemplate& operator = (AssociativeTemplate&&) 
        = delete;

protected:
    PointerContainer m_Pointers{};
};
