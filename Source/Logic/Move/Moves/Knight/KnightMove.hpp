#pragma once 

#include "Logic/Move/Moves/BasicMove.hpp"

class KnightMove : public BasicMove
{
public:
    KnightMove() = delete;
    KnightMove(const KnightMove&) = default;
    KnightMove(KnightMove&&) = default;

    KnightMove(const DefaultMove& defaultMove);

    ~KnightMove() = default;

    MoveEffect Try(const Board& board, const BoardCell& initial,
        const BoardCell& final) const noexcept(false) override;

    BasicMove* Clone() const noexcept override;

protected:
    bool IsUnderDistance(const BoardCell& initial, 
        const BoardCell& final) 
        const noexcept override;

};
