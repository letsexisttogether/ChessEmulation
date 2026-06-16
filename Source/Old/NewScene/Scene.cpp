#include "Scene.hpp"

#include "Application/Application.hpp"

std::unique_ptr<Scene> Scene::LoadMenuScene() noexcept(false)
{
    auto scene = std::make_unique<Scene>();

    auto texture = std::make_shared<sf::Texture>();
    texture->loadFromFile("Resourses\\Buttons\\ExitButton.png");

    Graphics::Drawable drawable
    { 
        { { 500, 500 }, { 500, 500 }, 140 }, texture 
    };

    Graphics::Intersectable intersectable
    {
        { { 500, 500 }, { 500, 500} }
    };

    Graphics::Interactable interactable
    { 
        Graphics::InteractionEvent::Hover | 
            Graphics::InteractionEvent::OnClick
    };

    Graphics::Sprite sprite
    {
        std::move(drawable), std::move(intersectable),
        std::move(interactable)
    };

    scene->AddSprite(std::move(sprite));

    return scene;
}

void Scene::UpdateLogic() noexcept(false)
{
    std::cout << "Updating Logic\n";
}

void Scene::UpdateGraphics() noexcept(false)
{
    auto& window = Application::GetInstance().GetWindow();

    for (auto& sprite : m_Sprites)
    {
        window.draw(sprite);
    }
}

void Scene::AddSprite(Graphics::Sprite&& sprite) noexcept(false)
{
    m_Sprites.push_back(std::move(sprite));
}

bool Scene::IsWorking() const noexcept
{
    return m_IsWorking;
}

void Scene::SetIsWorking(const bool isWorking) noexcept
{
    m_IsWorking = isWorking;
}
