#pragma once

#include "../Placable/Placable.hpp"

GraphicsSpaceStart

class Intersectable
{
public:
    Intersectable() = default;
    Intersectable(const Intersectable&) = default;
    Intersectable(Intersectable&&) = default;

    Intersectable(const Placable& hitBox) noexcept;

    virtual ~Intersectable() = default;

    const Placable& GetHitBox() const noexcept;
    void SetHitBox(const Placable& placable) noexcept;

    bool IsIntersectedBy(const Intersectable& intersectable)
        const noexcept;

    Intersectable& operator = (const Intersectable&) = default;
    Intersectable& operator = (Intersectable&&) = default;

private:
    Placable m_HitBox{};
};

GraphicsSpaceEnd
