#include "Piece.hpp"

Piece::Piece(const sf::Texture& texture, const Side side)
	: m_Sprite{ texture }, m_Side{ side }
{}

Piece::Piece(const Side side, const MovesContainer& moves)
    : m_Side{ side }, m_Moves{ moves }
{}

MoveEffect Piece::TryMove(const BoardCell& initial, const BoardCell& final) 
    const noexcept
{
    for (const MovePointer& move : m_Moves)
    {
        if (const MoveEffect effect = move->CheckRequirements(initial, final);
                effect != MoveEffect::NONE)
        {
            return effect;
        }
    }

    return MoveEffect::NONE;
}

void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Sprite);
}

void Piece::SetScreenPosition(const sf::Vector2f& position) noexcept
{
	m_Sprite.setPosition(position);
}
