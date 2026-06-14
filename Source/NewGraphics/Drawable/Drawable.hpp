#pragma once

#include <memory>
#include <array>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include "../Placable/Placable.hpp"

GraphicsSpaceStart

class Drawable : public sf::Drawable
{
public:
    using TexturePointer = std::shared_ptr<sf::Texture>;

public:
    Drawable() = default;
    Drawable(const Drawable& drawable) = default;
    Drawable(Drawable&& drawable) = default;

    Drawable(const Placable& position) noexcept;
    Drawable(const Placable& position, const TexturePointer& texture)
        noexcept;
    Drawable(const Placable& position, const TexturePointer& texture,
        const Placable& textureCoords) noexcept;

    virtual ~Drawable() = default;

    void draw(sf::RenderTarget& target, sf::RenderStates states) 
        const noexcept(false) override;

    Drawable& operator = (const Drawable&) = default;
    Drawable& operator = (Drawable&&) = default;

private:
    void Create(const Placable& position, const Placable& textureCoords)
        noexcept;

    /*
    void FillVerticesByPosition(const Placable& position) noexcept;
    void FillVerticesByTexture(const Placable& textureCoords) noexcept;

    sf::Vertex CreateVertex(const Placable& position,
        const Location location) const noexcept;
    */

private:
    std::array<sf::Vertex, 4> m_Vertices{};
    TexturePointer m_Texture{};
};

GraphicsSpaceEnd
