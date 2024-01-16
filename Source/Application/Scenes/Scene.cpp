#include "Scene.hpp"

#include <utility>

Scene::Scene(const std::string& name, std::vector<Button>&& buttons)
    : m_Name{ name }, m_Buttons{ std::move(buttons) } 
{}

void Scene::ActivateButton(const std::size_t buttonIndex) noexcept(false)
{
    m_Buttons.at(buttonIndex).OnClick();
}

bool Scene::IsWorking() const noexcept
{
    return m_IsWorking;
}

void Scene::SetWorking(const bool isWorking) noexcept
{
    m_IsWorking = isWorking;
}


const std::string& Scene::GetName() const noexcept
{
    return m_Name;
}

