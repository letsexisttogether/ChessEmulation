#include "Piece.hpp"

Piece::Piece(const sf::Texture& texture, Side side)
	: m_Sprite{ texture }, m_Side{ side }
{}

void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Sprite);
}

const sf::Vector2f& Piece::GetScreenPosition() const noexcept
{
	return m_Sprite.getPosition();
}

void Piece::SetScreenPosition(const sf::Vector2f& position) noexcept
{
	m_Sprite.setPosition(position);
}

Side Piece::GetSide() const noexcept
{
	return m_Side;
}

const sf::Vector2u& Piece::GetSize() const noexcept
{
	return m_Sprite.getTexture()->getSize();
}
