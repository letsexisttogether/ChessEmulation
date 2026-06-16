#include "PawnTransferMove.hpp"

PawnTransferMove::PawnTransferMove(const DefaultMove& defaultMove)
    : TransferMove{ defaultMove }
{}
 
BasicMove* PawnTransferMove::Clone() const noexcept
{
    return new PawnTransferMove{ *this };
}


void PawnTransferMove::SpawnLegalMoves(Board& board, BoardCell& initial, 
    MovePairContainer& moves) noexcept(false)
{
    const BoardCellIndex temp{ m_DefaultMove };
    const BoardCellIndex initialIndex{ initial.GetIndex() };
    const BoardCellIndex finalIndex{ initialIndex + temp };

    if (board.IsIndexIn(finalIndex) 
        && IsConditionSatisfied(board, initial, 
        board[finalIndex], true))
    {
        moves.push_back({ Clone(), finalIndex });
    }
}

bool PawnTransferMove::IsBasicAlright(const BoardCell& initial, 
    const BoardCell& final) const noexcept
{
    return final.IsFree();
} 
