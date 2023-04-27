#pragma once

#include "../DefaultMove.hpp"

class KnightMove : public DefaultMove
{
public:
    KnightMove() = delete;
    KnightMove(const KnightMove&) = delete;
    KnightMove(KnightMove&&) = default; 
    
    KnightMove(const MoveSpecs specs);

    virtual ~KnightMove() override = default;

    bool CheckRequirements(const Board& board, const BoardCell& initial, const BoardCell& final)
            const noexcept(false) override;

    KnightMove& operator = (const KnightMove&) = delete;
	KnightMove& operator = (KnightMove&&) = delete;
};
