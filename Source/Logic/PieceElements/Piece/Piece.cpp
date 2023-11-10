#include "Piece.hpp"

Piece::Piece(const Side side, const PieceType type, 
            const sf::Texture& texture, const MovesContainer& moves)
    : m_Side{ side }, m_Type{ type }, m_Moves{ moves }
{
    setTexture(texture);
}

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
