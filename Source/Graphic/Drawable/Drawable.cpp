#include "Drawable.hpp"
#include <utility>

Drawable::Drawable(sf::Texture* const texture)
    : m_Texture{ texture }
{}

Drawable::Drawable(const Drawable& drawable)
    : m_Texture{ drawable.m_Texture }
{}

Drawable::Drawable(Drawable&& drawable)
    : m_Texture{ std::move(drawable.m_Texture) }
{}

const sf::Texture& Drawable::GetTexture() const noexcept(false)
{
    CheckTexture();

    return *m_Texture;
}

void Drawable::SetTexture(sf::Texture* const texture) noexcept
{
    m_Texture.reset(texture);
}

void Drawable::draw(sf::RenderTarget& target, sf::RenderStates states) 
    const
{
    CheckTexture();

    sf::Sprite sprite(*m_Texture);
    target.draw(sprite, states);
}

Drawable& Drawable::operator = (const Drawable& drawable)
{
    m_Texture = drawable.m_Texture;

    return *this;
}

Drawable& Drawable::operator = (Drawable&& drawable)
{
    m_Texture = std::move(drawable.m_Texture);

    return *this;
}

void Drawable::CheckTexture() const noexcept(false)
{
    if (!m_Texture)
    {
        throw std::runtime_error{ "The texure is nullptr" };
    }
}
