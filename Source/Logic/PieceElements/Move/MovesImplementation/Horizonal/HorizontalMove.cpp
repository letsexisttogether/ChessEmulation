#include "HorizontalMove.hpp"
#include "Logic/BoardElements/Board/Board.hpp"

HorizontalMove::HorizontalMove(const DefaultMove& defaultMove)
    : PieceMove{ defaultMove } 
{}

bool HorizontalMove::CheckRequirements(const Board& board, 
    const BoardCell& initial, const BoardCell& final, 
    const std::uint16_t currentMove) const noexcept 
{
    const auto diff = final - initial;

    const bool isFree = final.IsFree();



    return false;
}

