#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <string>

#include "Graphic/Drawable/Drawable.hpp"
#include "Graphic/Intersectable/Intersectable.hpp"
#include "UI/Buttons/Button.hpp"

class Scene 
{
public:
    using IntersectablesContainer = std::vector<Intersectable*>;
    using DrawablesContainer = std::vector<Drawable*>;

public:
    Scene() = default;
    
    virtual ~Scene() = default;

    virtual void UpdateLogic() noexcept(false) = 0;

    virtual void UpdateGraphic() noexcept(false) = 0;

    void AddIntersectable(Intersectable* const intersectable) noexcept;

    IntersectablesContainer& GetIntersectables() noexcept;
    const IntersectablesContainer& GetIntersectables() const noexcept;

    void AddDrawable(Drawable* const drawable) noexcept;

    DrawablesContainer& GetDrawable() noexcept;
    const DrawablesContainer& GetDrawable() const noexcept;

    bool IsWorking() const noexcept;
    void SetWorking(const bool isWorking) noexcept;

// Change some of the fields to private
protected:
    DrawablesContainer m_Drawables{};
    IntersectablesContainer  m_Intersectables{};

private:
    bool m_IsWorking{ true };
};
