#include "Piece.hpp"

Piece::Piece(const sf::Texture& texture, Side side)
	: m_Sprite{ texture }, m_Side{ side }
{}

void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Sprite);
}

void Piece::SetScreenPosition(const sf::Vector2f& position) noexcept
{
	m_Sprite.setPosition(position);
}
