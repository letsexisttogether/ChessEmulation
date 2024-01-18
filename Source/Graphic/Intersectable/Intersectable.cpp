#include "Intersectable.hpp"

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
    const Position intersecatbleDownLeft 
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


    bool isXIntersected = (thisDownLeft.x <= intersecatbleDownLeft.x 
            && thisUpRight.x >= intersectablaUpRight.x);
    bool isYIntersected  = (thisDownLeft.y >= intersecatbleDownLeft.y
            && thisUpRight.y <= intersectablaUpRight.y);

    return isXIntersected && isYIntersected ;
}
