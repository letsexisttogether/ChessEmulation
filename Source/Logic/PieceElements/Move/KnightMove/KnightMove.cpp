#include "KnightMove.hpp"

#include "Logic/BoardElements/Board/Board.hpp"

KnightMove::KnightMove(const MoveSpecs specs)
    : DefaultMove{ specs }
{}

bool KnightMove::CheckRequirements(const Board &board, const BoardCell &initial, const BoardCell &final) const noexcept(false)
{
    return final.IsFree() || initial.GetPiece().GetSide() == final.GetPiece().GetSide();
}
