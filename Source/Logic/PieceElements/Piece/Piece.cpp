#include "Piece.hpp"

Piece::Piece(const Piece& piece)
    : m_Side{ piece.m_Side }, m_Type{ piece.m_Type }
{
    for (const MovePointer& move : piece.m_Moves)
    {
        m_Moves.push_back(MovePointer{ move->Clone() });
    }
}

Piece::Piece(Piece&& piece)
    : m_Side{ piece.m_Side }, m_Type{ piece.m_Type },
    m_Moves{ std::move(piece.m_Moves) }
{}

Piece::Piece(const PieceSide side, const PieceType type,
    const InMovesContainer& moves)
    : m_Side{ side }, m_Type{ type }
{
    for (const BasicMove* move : moves)
    {
        m_Moves.push_back(MovePointer{ move->Clone() });
    }
}

Piece::Piece(const PieceSide side, const PieceType type, 
    const InMovesContainer& moves, const TexturePointer texture,
    const Drawable::Position position)
    : Sprite{ texture, position }, m_Side{ side }, m_Type{ type }
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

Piece& Piece::operator = (const Piece& piece)
{
    m_Side = piece.m_Side;
    m_Type = piece.m_Type;

    m_Moves.clear();

    for (const MovePointer& move : piece.m_Moves)
    {
        m_Moves.push_back(MovePointer{ move->Clone() });
    }

    return *this;
}

Piece& Piece::operator = (Piece&& piece)
{
    m_Side = piece.m_Side;
    m_Type = piece.m_Type;

    m_Moves = std::move(piece.m_Moves);

    return *this;
}
