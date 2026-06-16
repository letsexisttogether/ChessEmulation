#include "Placable.hpp"

#include "Math/VectorOperations.hpp"

GraphicsSpaceStart

Placable::Placable(const Position origin, const SizeType size,
    const RotationType rotation) noexcept
    : Origin{ origin }, Size{ size }, Rotation{ rotation }
{}


Placable::Position Placable::GetPosition(const Location location)
    const noexcept
{
    if (location == Location::Center)
    {
        return Origin;
    }

    const auto offset = GetPositionForOffset(location);
    const auto rotatedOffset = Math::RotateVector(offset, Rotation);

    return { Origin.x + rotatedOffset.x, Origin.y + rotatedOffset.y };
}


Placable::Position Placable::GetPositionForOffset(const Location location)
    const noexcept
{
    const auto halfSize{ Size / 2.0f };

    switch (location)
    {
        case Location::Center:
            return Origin;

        case Location::UpRight:
            return { halfSize.x, -halfSize.y };

        case Location::UpLeft:
            return { -halfSize.x, -halfSize.y };

        case Location::DownRight:
            return { halfSize.x, halfSize.y };

        case Location::DownLeft:
            return { -halfSize.x, halfSize.y };
    }

    return {};
}

GraphicsSpaceEnd
