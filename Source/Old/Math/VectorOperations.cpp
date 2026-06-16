#include "VectorOperations.hpp"

MathSpaceStart

sf::Vector2f RotateVector(const sf::Vector2f& vec, const float degrees)
    noexcept
{
    const auto radians = degrees * PI / 180.f;
    const auto consinus = std::cos(radians);
    const auto sinus = std::sin(radians);

    return
    {
        vec.x * consinus - vec.y * sinus,
        vec.x * sinus + vec.y * consinus
    };
}

MathSpaceEnd
