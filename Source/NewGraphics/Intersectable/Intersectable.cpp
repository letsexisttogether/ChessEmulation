#include "Intersectable.hpp"

#include <cmath>

GraphicsSpaceStart

Intersectable::Intersectable(const Placable& hitBox) noexcept
    : m_HitBox{ hitBox }
{}

const Placable& Intersectable::GetHitBox() const noexcept
{
    return m_HitBox;
}

void Intersectable::SetHitBox(const Placable& hitBox) noexcept
{
    m_HitBox = hitBox;
}

bool Intersectable::IsIntersectedBy(const Intersectable&
    intersectable) const noexcept
{
    const auto& origin = m_HitBox.Origin;
    const auto& size = m_HitBox.Size;

    const auto& otherOrigin = intersectable.m_HitBox.Origin;
    const auto& otherSize = intersectable.m_HitBox.Size;

    const auto deltaX = std::abs(origin.x - otherOrigin.x);
    const auto deltaY = std::abs(origin.y - otherOrigin.y);

    const auto halfWidthSum = (size.x + otherSize.x) * 0.5f;
    const auto halfHeightSum = (size.y + otherSize.y) * 0.5f;

    return deltaX <= halfWidthSum && deltaY <= halfHeightSum;
}

GraphicsSpaceEnd
