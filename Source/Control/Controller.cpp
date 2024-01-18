#include "Controller.hpp"

#include "Application/Application.hpp"
#include "Application/Scenes/Scene.hpp"

Controller::Controller(const TexturePointer texture, 
    const Position position)
    : Sprite{ texture, position }
{}

Intersectable* Controller::GetPossibleIntersectable() const noexcept(false)
{
    const Scene& scene = Application::GetInstance().GetScene();
    
    for (Intersectable* intersectable : scene.GetIntersectables())
    {
        if (intersectable->IsIntersected(*this))
        {
            return intersectable;
        }
    }

    return nullptr;
}
