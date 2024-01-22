#include "Controller.hpp"

#include <iostream>

#include "Application/Application.hpp"
#include "Application/Scenes/Scene.hpp"

Controller::Controller(Window& window, const TexturePointer texture, 
    const Position position)
    : Sprite{ texture, position }, m_Window{ window }
{}

Intersectable* Controller::GetPossibleIntersectable() const noexcept(false)
{
    const Scene& scene = Application::GetInstance().GetScene();
    
    for (Intersectable* intersectable : scene.GetIntersectables())
    {
        if (IsIntersected(*intersectable))
        {
            return intersectable;
        }
    }

    return nullptr;
}
