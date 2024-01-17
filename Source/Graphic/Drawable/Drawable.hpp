#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <memory>

#include "Graphic/Placable/Placable.hpp"

class Drawable: public sf::Drawable, public Placable 
{
public:
    using Texture = sf::Texture;

public:
    Drawable() = default;
    Drawable(const Drawable& drawable);
    Drawable(Drawable&& drawable);

    Drawable(Texture* const texture, const Position& position);

    virtual ~Drawable() = default;

    const Texture& GetTexture() const noexcept(false);
    void SetTexture(Texture* const texture) noexcept(false);

    void draw(sf::RenderTarget& target, sf::RenderStates states) 
        const override;

    Drawable& operator = (const Drawable& drawable) noexcept(false);
    Drawable& operator = (Drawable&& drawable) noexcept(false);

private:
    void CheckTexture() const noexcept(false);

protected:
    std::shared_ptr<Texture> m_Texture{};
};
