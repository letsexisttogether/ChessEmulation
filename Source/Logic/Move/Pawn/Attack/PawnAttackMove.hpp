#pragma once

#include "Logic/Move/Knight/KnightMove.hpp"

class PawnAttackMove : public KnightMove 
{
public:
	PawnAttackMove() = delete;
	PawnAttackMove(const PawnAttackMove&) = default;
	PawnAttackMove(PawnAttackMove&&) = default;

	PawnAttackMove(const DefaultMove& defaultMove);

	~PawnAttackMove() = default;

    BasicMove* Clone() const noexcept override;

    void SpawnLegalMoves(Board& board, BoardCell& initial, 
        MovePairContainer& moves) noexcept(false) override;

private:
    bool IsBasicAlright(const BoardCell& initial, const BoardCell& final) 
        const noexcept override;
};
