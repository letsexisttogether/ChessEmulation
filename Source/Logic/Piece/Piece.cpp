#include "Piece.hpp"

#include "Logic/Match/Match.hpp"

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
    const TexturePointer texture,
    const InMovesContainer& moves,
    const Drawable::Position position)
    : Sprite{ texture, position }, m_Side{ side }, m_Type{ type }
{
    for (const BasicMove* move : moves)
    {
        m_Moves.push_back(MovePointer{ move->Clone() });
    }
}

MoveEffect Piece::TryMove(const Match& match) 
    const noexcept
{
    for (const MovePointer& move : m_Moves)
    {
        if (const MoveEffect effect = move->Try(match);
            effect != MoveEffect::NONE)
        {
            return effect;
        }
    }

    return MoveEffect::NONE;
}

bool Piece::WasMoved() const noexcept
{
    return m_WasMoved;
}

void Piece::NotifyAboutMove() noexcept
{
    m_WasMoved = true;
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

