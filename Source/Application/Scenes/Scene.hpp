#pragma once

#include <memory>

#include "Control/Controller.hpp"
#include "Graphic/Drawable/Drawable.hpp"
#include "Graphic/Intersectable/Intersectable.hpp"

class Scene 
{
public:
    using IntersectablesContainer = std::vector<Intersectable*>;
    using DrawablesContainer = std::vector<const Drawable*>;

public:
    Scene() = default;

    Scene(Controller* controller);
    
    virtual ~Scene() = default;

    virtual void UpdateLogic() noexcept(false) = 0;

    virtual void UpdateGraphic() noexcept(false);

    virtual IntersectablesContainer GetIntersectables() 
        const noexcept = 0;

    virtual DrawablesContainer GetDrawables() 
        const noexcept = 0;

    const Controller& GetController() const noexcept;
    Controller& GetController() noexcept;
    void SetController(Controller* controller) noexcept;

    bool IsWorking() const noexcept;
    void SetWorking(const bool isWorking) noexcept;

protected:
    std::unique_ptr<Controller> m_Controller{};

private:
    bool m_IsWorking{ true };
};
