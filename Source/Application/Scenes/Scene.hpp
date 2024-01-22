#pragma once

#include <memory>

#include "Control/Controller.hpp"
#include "Graphic/Drawable/Drawable.hpp"
#include "Graphic/Intersectable/Intersectable.hpp"

class Scene 
{
public:
    using IntersectablesContainer = std::vector<Intersectable*>;
    using DrawablesContainer = std::vector<Drawable*>;

public:
    Scene() = default;

    Scene(Controller* controller);
    
    virtual ~Scene() = default;

    virtual void UpdateLogic() noexcept(false) = 0;

    virtual void UpdateGraphic() noexcept(false);

    void AddIntersectable(Intersectable* const intersectable) noexcept;

    IntersectablesContainer& GetIntersectables() noexcept;
    const IntersectablesContainer& GetIntersectables() const noexcept;

    void AddDrawable(Drawable* const drawable) noexcept;

    DrawablesContainer& GetDrawable() noexcept;
    const DrawablesContainer& GetDrawable() const noexcept;

    const Controller& GetController() const noexcept;
    Controller& GetController() noexcept;
    void SetController(Controller* controller) noexcept;

    bool IsWorking() const noexcept;
    void SetWorking(const bool isWorking) noexcept;

// Change some of the fields to private
protected:
    DrawablesContainer m_Drawables{};
    IntersectablesContainer  m_Intersectables{};

    std::unique_ptr<Controller> m_Controller{};

private:
    bool m_IsWorking{ true };
};
