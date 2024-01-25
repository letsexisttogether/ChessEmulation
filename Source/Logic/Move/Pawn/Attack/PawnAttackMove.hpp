#pragma once

#include "Logic/Move/Transfer/TransferMove.hpp"

class PawnAttackMove : public TransferMove
{
public:
	PawnAttackMove() = delete;
	PawnAttackMove(const PawnAttackMove&) = default;
	PawnAttackMove(PawnAttackMove&&) = default;

	PawnAttackMove(const DefaultMove& defaultMove);

	~PawnAttackMove() = default;

    BasicMove* Clone() const noexcept override;

private:
    bool IsBasicAlright(const BoardCell& initial, const BoardCell& final) 
        const noexcept override;
};
