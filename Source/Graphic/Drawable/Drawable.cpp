#include "Drawable.hpp"

#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <stdexcept>

Drawable::Drawable(sf::Texture* const texture, 
        const Position& position)
{
    SetTexture(texture);

    setPosition(position);
}

Drawable::Drawable(const Drawable& drawable)
{
    SetTexture(drawable.m_Texture.get());

    setPosition(drawable.getPosition());
}

Drawable::Drawable(Drawable&& drawable)
{
    SetTexture(drawable.m_Texture.get());
    drawable.m_Texture.reset();

    setPosition(drawable.getPosition());
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
    states.transform *= getTransform();
    states.texture = m_Texture.get();
    
    // Create a quad (two triangles) for rendering the texture
    sf::VertexArray vertices(sf::Quads, 4);
    vertices[0].position = sf::Vector2f(0, 0);
    vertices[1].position = sf::Vector2f(m_Texture->getSize().x, 0);
    vertices[2].position = sf::Vector2f(m_Texture->getSize().x, m_Texture->getSize().y);
    vertices[3].position = sf::Vector2f(0, m_Texture->getSize().y);

    // Set texture coordinates
    vertices[0].texCoords = sf::Vector2f(0, 0);
    vertices[1].texCoords = sf::Vector2f(m_Texture->getSize().x, 0);
    vertices[2].texCoords = sf::Vector2f(m_Texture->getSize().x, m_Texture->getSize().y);
    vertices[3].texCoords = sf::Vector2f(0, m_Texture->getSize().y);

    // Apply the transform and draw the vertices
    target.draw(vertices, states);
}

Drawable& Drawable::operator = (const Drawable& drawable) noexcept(false)
{
    SetTexture(drawable.m_Texture.get());

    setPosition(drawable.getPosition());

    return *this;
}

Drawable& Drawable::operator = (Drawable&& drawable) noexcept(false)
{
    SetTexture(drawable.m_Texture.get());
    drawable.m_Texture.reset();

    setPosition(drawable.getPosition());

    return *this;
}

void Drawable::CheckTexture() const noexcept(false)
{
    if (!m_Texture)
    {
        throw std::runtime_error{ "The texure is nullptr" };
    }
} 

const Drawable::Position Drawable::DefaultPosition{ 0, 0 };
