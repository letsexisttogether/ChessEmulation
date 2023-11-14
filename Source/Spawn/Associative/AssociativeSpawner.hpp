#pragma once 

template <class _Instance, class _Association>
class AssociativeSpawner
{
public:
    AssociativeSpawner() = default;
    
    virtual ~AssociativeSpawner() = default;

    virtual _Instance GetInstance(const _Association& traits) 
        noexcept(false) = 0;
};
