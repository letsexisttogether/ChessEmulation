#include "PawnDoubleTransferMove.hpp"

PawnDoubleTransferMove::PawnDoubleTransferMove
    (const DefaultMove& defaultMove)
    : PawnTransferMove{ defaultMove }
{}


void PawnDoubleTransferMove::SpawnLegalMoves(Board& board, BoardCell& initial, 
    MovePairContainer& moves) noexcept(false)
{
    const BoardCellIndex temp{ m_DefaultMove };
    const BoardCellIndex initialIndex{ initial.GetIndex() };
    const BoardCellIndex finalIndex{ initialIndex + temp };

    if (board.IsIndexIn(finalIndex) 
        && IsConditionSatisfied(board, initial, board[finalIndex], true))
    {
        moves.push_back({ Clone(), finalIndex });
    }
}

BasicMove* PawnDoubleTransferMove::Clone() const noexcept
{
    return new PawnDoubleTransferMove{ *this };
}

bool PawnDoubleTransferMove::IsUnderDistance(const BoardCell& initial, 
        const BoardCell& final) const noexcept
{
    const DefaultMove possibleMove = final - initial;

    return m_DefaultMove == possibleMove;
}

bool PawnDoubleTransferMove::IsBasicAlright
    (const BoardCell &initial, const BoardCell &final)
    const noexcept
{
    return final.IsFree() && !initial.GetPiece().WasMoved();
}
