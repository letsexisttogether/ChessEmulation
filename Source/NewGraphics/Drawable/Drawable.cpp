#include "Drawable.hpp"

#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

GraphicsSpaceStart

Drawable::Drawable(const Placable& position, const TexturePointer& texture)
    noexcept : m_Texture{ texture }
{
    const auto size = static_cast<Placable::Position>
        (texture->getSize());

    const auto halfSize = size / 2.0f;

    const Placable textureCoords{ halfSize, size };

    Create(position, textureCoords); 
}

Drawable::Drawable(const Placable& position, const TexturePointer& texture,
    const Placable& textureCoords) noexcept : m_Texture{ texture }
{
    Create(position, textureCoords); 
}

void Drawable::draw(sf::RenderTarget& target, sf::RenderStates states)
    const noexcept(false)
{
    states.texture = m_Texture.get();

    target.draw(m_Vertices.data(), m_Vertices.size(),
            sf::PrimitiveType::TriangleStrip, states);
}

void Drawable::Create(const Placable& position, const Placable&
    textureCoords) noexcept
{
    const std::array<Location, 4> locations
    {
        Location::UpLeft, Location::DownLeft,
        Location::UpRight, Location::DownRight
    };

    for (std::size_t i = 0; i < locations.size(); ++i)
    {
        m_Vertices[i] = sf::Vertex
        { 
            position.GetPosition(locations[i]),
            textureCoords.GetPosition(locations[i])
        };
    }
}

/*
void Drawable::FillVerticesByPosition(const Placable& position) noexcept
{
    m_Vertices[0] = CreateVertex(position, Location::UP_LEFT);
    m_Vertices[1] = CreateVertex(position, Location::DOWN_LEFT);
    m_Vertices[2] = CreateVertex(position, Location::UP_RIGHT);
    m_Vertices[3] = CreateVertex(position, Location::DOWN_RIGHT);
}

void Drawable::FillVerticesByTexture(const Placable& textureCoords) noexcept
{
    m_Vertices[0].texCoords = textureCoords.GetPosition(Location::UP_LEFT);
    m_Vertices[1].texCoords = textureCoords.GetPosition(Location::DOWN_LEFT);
    m_Vertices[2].texCoords = textureCoords.GetPosition(Location::UP_RIGHT);
    m_Vertices[3].texCoords = textureCoords.GetPosition(Location::DOWN_RIGHT);
}

sf::Vertex Drawable::CreateVertex(const Placable& position,
    const Location location) const noexcept
{
    const auto finalPosition = position.GetPosition(location);

    return { finalPosition, finalPosition };
}
*/

GraphicsSpaceEnd
