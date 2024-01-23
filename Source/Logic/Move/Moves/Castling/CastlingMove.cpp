#include "CastlingMove.hpp"

#include "Logic/Match/Match.hpp"

CastlingMove::CastlingMove(const DefaultMove& defaultMove)
    : KnightMove{ defaultMove }
{}

BasicMove* CastlingMove::Clone() const noexcept
{
    return new CastlingMove{ *this };
}

MoveEffect CastlingMove::DefinePossibleMoveEffect(const BoardCell& initial,
    const BoardCell& final) const noexcept(false)
{
    return MoveEffect::CASTLE;
}

bool CastlingMove::IsBasicAdhered(const BoardCell& initial,
    const BoardCell& final) const noexcept(false)
{
    if (final.IsFree() || !IsSameSide(initial, final))
    {
        return false;
    }
    
    const Piece& initialPiece = initial.GetPiece();
    const Piece& finalPiece = final.GetPiece();

    return !initialPiece.WasMoved() && !finalPiece.WasMoved();
}

