#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <memory>

#include "Graphic/Placable/Placable.hpp"

class Drawable: public sf::Drawable, virtual public Placable 
{
public:
    using Texture = sf::Texture;
    using TexturePointer = std::shared_ptr<Texture>;

public:
    Drawable() = default;
    Drawable(const Drawable& drawable);
    Drawable(Drawable&& drawable);

    Drawable(const TexturePointer& texture);
    Drawable(const TexturePointer& texture, const Position& position);

    ~Drawable() = default;

    const Texture& GetTexture() const noexcept(false);
    void SetTexture(const TexturePointer& texture) noexcept(false);

    void draw(sf::RenderTarget& target, sf::RenderStates states) 
        const override;

    Drawable& operator = (const Drawable& drawable) noexcept(false);
    Drawable& operator = (Drawable&& drawable) noexcept(false);

private:
    void CheckTexture() const noexcept(false);

protected:
    TexturePointer m_Texture{};
};
