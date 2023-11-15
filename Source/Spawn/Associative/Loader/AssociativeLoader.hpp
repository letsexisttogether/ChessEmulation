#pragma once

#include "Spawn/Associative/Storage/Objects/ObjectsStorage.hpp"
#include "Spawn/Associative/Storage/Pointers/PointersStorage.hpp"

template <class _Association, class _Instance, class _LoadBy> 
class AssociativeLoader : public PointersStorage<_Association, _Instance>
{
public:
    using Super = PointersStorage<_Association, _Instance>;
    using ObjStorage = ObjectsStorage<_Association, _LoadBy>;

public:
    AssociativeLoader() = default;

    AssociativeLoader(const ObjStorage& storage)
        : m_Storage{ storage }
    {}
    AssociativeLoader(ObjStorage&& storage)
        : m_Storage{ std::move(storage) }
    {}

    ~AssociativeLoader() = default;

    _Instance* GetInstance(const _Association& trait) noexcept(false) override
    {
        const _LoadBy& loadBy = m_Storage.GetInstance(trait);

        if (const auto& iter = this->m_Container.find(trait);
                iter == this->m_Container.end())
        {
            _Instance* instance = LoadInstance(loadBy);

            this->m_Container[trait] = InstancePointer{ instance };

            return instance;
        }
        else
        {
            return iter->second.get();
        }
    }

protected:
    virtual _Instance* LoadInstance(const _LoadBy& loadBy) noexcept(false) = 0;

protected:
    ObjStorage m_Storage{};
};

