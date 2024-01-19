#pragma once

#include "Graphic/Placable/Placable.hpp"

class Intersectable : virtual public Placable
{
public:
    Intersectable() = default;
    
    Intersectable(const Position origin);
    Intersectable(const Position origin, 
        const Size size);

    virtual ~Intersectable() = default;

    // The default verison checks the fully coverage of this over intersectabla
    virtual bool IsIntersected(const Intersectable& intersectabla)
        const noexcept;

    virtual void OnInteract() noexcept(false);
};
