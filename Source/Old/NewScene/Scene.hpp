#pragma once

#include <iostream>
#include <vector>

#include "../NewGraphics/Sprite/Sprite.hpp"

class Button : Graphics::Sprite
{
public:
    Button(Sprite&& sprite) noexcept
        : Graphics::Sprite{ std::move(sprite) }
    {}

    ~Button() = default;

    void Interact(const Graphics::InteractionEvent interactions)
        noexcept(false)
    {
        switch (interactions)
        {
            case Graphics::InteractionEvent::Hover:
                OnHover();
            break;
            case Graphics::InteractionEvent::OnClick:
                OnClick();
            break;
            default:
            break;
        }
    }

private:
    void OnHover() noexcept(false)
    {
        std::cout << "OnHover" << std::endl;
    }

    void OnClick() noexcept(false)
    {
        std::cout << "OnClick" << std::endl;
    }
};

class Scene
{
public:
    static std::unique_ptr<Scene> LoadMenuScene() noexcept(false);

public:
    using Sprites = std::vector<Graphics::Sprite>;

public:
    Scene() = default;
    ~Scene() = default;
    
    void UpdateLogic() noexcept(false);
    void UpdateGraphics() noexcept(false);

    void AddSprite(Graphics::Sprite&& sprite) noexcept(false);

    bool IsWorking() const noexcept;
    void SetIsWorking(const bool isWorking) noexcept;

private:
    Sprites m_Sprites{};
    bool m_IsWorking{ true };
};
