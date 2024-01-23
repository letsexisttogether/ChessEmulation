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

    MoveEffect Try(const Match& match) 
        const noexcept override;

    BasicMove* Clone() const noexcept override;

protected:
    bool IsUnderDistance(const BoardCell& initial, 
        const BoardCell& final) 
        const noexcept override;

};
