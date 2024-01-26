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

}

bool PawnAttackMove::IsBasicAlright(const BoardCell& initial, 
    const BoardCell& final) const noexcept
{
    return !final.IsFree();
}
    
