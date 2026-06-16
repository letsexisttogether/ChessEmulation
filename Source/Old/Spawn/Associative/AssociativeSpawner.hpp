#pragma once 

template <class _Association, class _Instance>
class AssociativeSpawner
{
public:
    AssociativeSpawner() = default;
    
    virtual ~AssociativeSpawner() = default;

    virtual _Instance GetInstance(const _Association& trait) 
        noexcept(false) = 0;
};
