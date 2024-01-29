#include "PawnAttackMove.hpp"

PawnAttackMove::PawnAttackMove(const DefaultMove& defaultMove)
    : KnightMove{ defaultMove }
{}

BasicMove* PawnAttackMove::Clone() const noexcept
{
    return new PawnAttackMove{ *this };
}

void PawnAttackMove::SpawnLegalMoves(Board& board, BoardCell& initial, 
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

bool PawnAttackMove::IsBasicAlright(const BoardCell& initial, 
    const BoardCell& final) const noexcept
{
    return !final.IsFree();
}
    
