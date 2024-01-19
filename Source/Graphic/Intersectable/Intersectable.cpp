#include "Intersectable.hpp"

#include <iostream>

Intersectable::Intersectable(const Placable::Position origin)
    : Placable{ origin, Placable::Size{ 1.f, 1.f } }
{}

Intersectable::Intersectable(const Placable::Position origin, 
    const Placable::Size size)
    : Placable{ origin, size }
{}

bool Intersectable::IsIntersected(const Intersectable& intersectabla)
    const noexcept
{
    const Position intersectablaUpRight
    { 
        intersectabla.GetPosition(PositionLocation::UP_RIGHT)
    };
    const Position intersecatblaDownLeft 
    {
        intersectabla.GetPosition(PositionLocation::DOWN_LEFT)
    };

    const Position thisUpRight
    { 
        GetPosition(PositionLocation::UP_RIGHT)
    };
    const Position thisDownLeft 
    {
        GetPosition(PositionLocation::DOWN_LEFT)
    };


    const bool isXIntersected = (thisDownLeft.x <= intersecatblaDownLeft.x 
            && thisUpRight.x >= intersectablaUpRight.x);
    const bool isYIntersected  = (thisDownLeft.y >= intersecatblaDownLeft.y
            && thisUpRight.y <= intersectablaUpRight.y);

    return isXIntersected && isYIntersected;
}

void Intersectable::OnInteract() noexcept(false)
{}
