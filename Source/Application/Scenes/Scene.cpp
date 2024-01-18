#include "Scene.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <algorithm>

#include "Application/Application.hpp"

void Scene::UpdateGraphic() noexcept(false)
{
    sf::RenderWindow& window = Application::GetInstance().GetWindow();

    for (const Drawable* drawable : m_Drawables)
    {
        window.draw(*drawable);
    }
}

void Scene::AddIntersectable(Intersectable* const intersectable)
    noexcept
{
    if (const auto iter = std::find(m_Intersectables.begin(), 
                m_Intersectables.end(), intersectable);
        iter == m_Intersectables.end())
    {
        m_Intersectables.push_back(intersectable);
    }
}

Scene::IntersectablesContainer& Scene::GetIntersectables() noexcept
{
    return m_Intersectables;
}

const Scene::IntersectablesContainer& Scene::GetIntersectables() const noexcept
{
    return m_Intersectables;
}

void Scene::AddDrawable(Drawable* const drawable) noexcept
{
    if (const auto iter = std::find(m_Drawables.begin(), 
                m_Drawables.end(), drawable);
        iter == m_Drawables.end())
    {
        m_Drawables.push_back(drawable);
    }
}

Scene::DrawablesContainer& Scene::GetDrawable() noexcept
{
    return m_Drawables;
}

const Scene::DrawablesContainer& Scene::GetDrawable() const noexcept
{
    return m_Drawables;
}

bool Scene::IsWorking() const noexcept
{
    return m_IsWorking;
}

void Scene::SetWorking(const bool isWorking) noexcept
{
    m_IsWorking = isWorking;
}

