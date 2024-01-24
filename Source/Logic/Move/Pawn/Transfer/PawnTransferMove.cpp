#include "PawnTransferMove.hpp"

PawnTransferMove::PawnTransferMove(const DefaultMove& defaultMove,
    const DefaultMove& startMove)
    : TransferMove{ defaultMove }, m_StartMove{ startMove }
{}

 
BasicMove* PawnTransferMove::Clone() const noexcept
{
    return new PawnTransferMove{ *this };
}

bool PawnTransferMove::IsBasicAlright(BoardCell& initial, 
    BoardCell& final) const noexcept
{
    return final.IsFree();
}
    
bool PawnTransferMove::IsUnderDistance(BoardCell& initial, 
    BoardCell& final) const noexcept
{
    const DefaultMove possibleMove = final - initial;

    const bool isDefaultMove = m_DefaultMove
        .IsUnderDistance(possibleMove);
    const bool isStartMove = (!initial.GetPiece().WasMoved()
        && m_StartMove == possibleMove);

    return isDefaultMove || isStartMove;
}
