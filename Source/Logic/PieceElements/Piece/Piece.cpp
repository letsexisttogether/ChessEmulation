#include "Piece.hpp"

Piece::Piece(const PieceSide side, const PieceType type, 
            const sf::Texture& texture, const MovesContainer& moves)
    : m_Side{ side }, m_Type{ type }, m_Moves{ moves }
{
    setTexture(texture);
}

Piece::Piece(const Piece& piece)
    : m_Side{ piece.m_Side }, m_Type{ piece.m_Type }
{
    for (const MovePointer move : piece.m_Moves)
    {
        m_Moves.push_back(move->Clone());
    }
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
