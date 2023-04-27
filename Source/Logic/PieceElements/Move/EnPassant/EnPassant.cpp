#include "EnPassant.hpp"

#include "Logic/BoardElements/BoardCell/BoardCell.hpp"

EnPassant::EnPassant(const MoveSpecs specs)
    : DefaultMove{ specs }
{}

bool EnPassant::CheckRequirements(const Board &board, const BoardCell &initial, const BoardCell &final) const noexcept(false)
{
    return false;
}

void EnPassant::HandleMove(Board& board, BoardCell& initial, BoardCell& final) const noexcept
{
    
}
