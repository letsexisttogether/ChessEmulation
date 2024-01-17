#include "Drawable.hpp"

#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>
#include <stdexcept>

Drawable::Drawable(sf::Texture* const texture, 
    const Position& position)
{
    SetTexture(texture);
    
    SetOrigin(position);
    SetSize(static_cast<Placable::Size>(m_Texture->getSize()) / 2.f);
}

Drawable::Drawable(const Drawable& drawable)
{
    SetTexture(drawable.m_Texture.get());
    
    SetOrigin(drawable.GetOrigin());
    SetSize(drawable.GetSize());
}

Drawable::Drawable(Drawable&& drawable)
    : Drawable(drawable)
{
    drawable.m_Texture.reset();
}

const sf::Texture& Drawable::GetTexture() const noexcept(false)
{
    CheckTexture();

    return *m_Texture;
}

void Drawable::SetTexture(sf::Texture* const texture) noexcept(false)
{
    m_Texture.reset(texture);

    CheckTexture();
}

void Drawable::draw(sf::RenderTarget& target, sf::RenderStates states) 
    const
{
    CheckTexture();
    
    states.texture = m_Texture.get();

    std::vector<Placable::Vertex> vertices
    {
        GetVertex(PositionLocation::UP_LEFT),
            GetVertex(PositionLocation::DOWN_LEFT),
        GetVertex(PositionLocation::UP_RIGHT),
        GetVertex(PositionLocation::DOWN_RIGHT)
    };

    const Placable::Position textureSize
    { 
        static_cast<Placable::Position>(m_Texture->getSize()) 
    };

    vertices[0].texCoords = Placable::Position{ 0.f, 0.f }; 
    vertices[1].texCoords = Placable::Position{ 0.f, textureSize.y };
    vertices[2].texCoords = Placable::Position{ textureSize.x, 0 };
    vertices[3].texCoords = Placable::Position{ textureSize.x, textureSize.y };

    target.draw(vertices.data(), vertices.size(), 
            sf::PrimitiveType::TriangleStrip, states);
}

Drawable& Drawable::operator = (const Drawable& drawable) noexcept(false)
{
    SetTexture(drawable.m_Texture.get());

    SetOrigin(drawable.GetOrigin());
    SetSize(drawable.GetSize());

    return *this;
}

Drawable& Drawable::operator = (Drawable&& drawable) noexcept(false)
{
    *this = drawable;

    drawable.m_Texture.reset();

    return *this;
}

void Drawable::CheckTexture() const noexcept(false)
{
    if (!m_Texture)
    {
        throw std::runtime_error{ "The texure is nullptr" };
    }
} 
