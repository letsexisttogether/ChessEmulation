#pragma once 

template <class _Instance>
class DefaultSpawner
{
public:
    DefaultSpawner() = default;
    
    virtual ~DefaultSpawner() = default;

    virtual _Instance GetInstance() noexcept(false) = 0;
};
