#include "CastlingMove.hpp"

#include "Logic/Match/Match.hpp"

CastlingMove::CastlingMove(const DefaultMove& defaultMove)
    : KnightMove{ defaultMove }
{}

BasicMove* CastlingMove::Clone() const noexcept
{
    return new CastlingMove{ *this };
}

MoveEffect CastlingMove::DefinePossibleMoveEffect(const Match& match) 
    const noexcept(false)
{
    return MoveEffect::CASTLE;
}

bool CastlingMove::IsBasicAdhered(const Match& match) const noexcept
{
    const GameObserver& gameObserver = match.GetGameObserver();

    if (gameObserver.IsMoveBeingMade())
    {
        return false;
    }

    const BoardCell& initial = gameObserver.GetInitial();
    const BoardCell& final = gameObserver.GetFinal();

    if (final.IsFree() || !IsSameSide(initial, final))
    {
        return false;
    }
    
    const Piece& initialPiece = initial.GetPiece();
    const Piece& finalPiece = final.GetPiece();

    return !(initialPiece.WasMoved()
        || finalPiece.WasMoved());
}

