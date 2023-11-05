#pragma once

#include "Logic/PieceElements/Move/PieceMove.hpp"

class HorizontalMove : public PieceMove
{
public:
    HorizontalMove() = delete;
    HorizontalMove(const HorizontalMove&) = delete;
    HorizontalMove(HorizontalMove&&) = delete;

    HorizontalMove(const DefaultMove& defaultMove);

    ~HorizontalMove() = default;

    bool CheckRequirements(const Board& board, 
        const BoardCell& initial, const BoardCell& final, 
        const std::uint16_t currentMove) const noexcept override;

    PieceMove& operator = (const HorizontalMove&) = delete;
    PieceMove& operator = (HorizontalMove&&) = delete;
};
