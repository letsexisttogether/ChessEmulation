#include "Scene.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include "Application/Application.hpp"

Scene::Scene(Controller* controller)
    : m_Controller{ controller }
{}

void Scene::UpdateGraphic() noexcept(false)
{
    sf::RenderWindow& window = Application::GetInstance().GetWindow();
    
    for (const Drawable* drawable : GetDrawables())
    {
        window.draw(*drawable); 
    }
}

const Controller& Scene::GetController() const noexcept
{
    return *m_Controller;
}

Controller& Scene::GetController() noexcept
{
    return *m_Controller;
}

void Scene::SetController(Controller* controller) noexcept
{
    m_Controller.reset(controller);
}

bool Scene::IsWorking() const noexcept
{
    return m_IsWorking;
}

void Scene::SetWorking(const bool isWorking) noexcept
{
    m_IsWorking = isWorking;
}

