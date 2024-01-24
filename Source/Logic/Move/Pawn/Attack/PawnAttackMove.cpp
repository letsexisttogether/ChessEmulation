#include "PawnAttackMove.hpp"

PawnAttackMove::PawnAttackMove(const DefaultMove& defaultMove)
    : TransferMove{ defaultMove }
{}

BasicMove* PawnAttackMove::Clone() const noexcept
{
    return new PawnAttackMove{ *this };
}

bool PawnAttackMove::IsBasicAlright(BoardCell& initial, 
    BoardCell& final) const noexcept
{
    return !final.IsFree();
}
    
