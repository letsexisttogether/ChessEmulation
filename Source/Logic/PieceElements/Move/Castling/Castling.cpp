#include "Castling.hpp"

#include "Logic/BoardElements/BoardCell/BoardCell.hpp"

Castling::Castling(const MoveSpecs specs)
    : DefaultMove{ specs }
{}

bool Castling::CheckRequirements(const Board &board, const BoardCell &initial, const BoardCell &final) const noexcept(false)
{
    return false;
}

void Castling::HandleMove(Board &board, BoardCell &initial, BoardCell &final) const noexcept
{

}
