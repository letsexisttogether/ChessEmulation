#pragma once

#include "Graphic/Placable/Placable.hpp"

class Intersectable : virtual public Placable
{
public:
    Intersectable() = default;
    Intersectable(const Intersectable& intersectabla);
    Intersectable(Intersectable&& intersectabla);
    
    Intersectable(const Position origin, 
        const Size size = Size{});

    virtual ~Intersectable() = default;

    // The default verison checks the fully coverage of this over intersectabla
    virtual bool IsIntersected(const Intersectable& intersectabla)
        const noexcept;

    virtual void OnInteract() noexcept(false);

    Intersectable& operator = (const Intersectable&) = default;
    Intersectable& operator = (Intersectable&&) = default;
};
