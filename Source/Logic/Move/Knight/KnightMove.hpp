#pragma once

#include "Logic/Move/Transfer/TransferMove.hpp"

class KnightMove : public TransferMove
{
public:
	KnightMove() = delete;
	KnightMove(const KnightMove&) = default;
	KnightMove(KnightMove&&) = default;

	KnightMove(const DefaultMove& defaultMove);

	~KnightMove() = default;

    BasicMove* Clone() const noexcept override;

protected:
    bool IsUnderDistance(const BoardCell& initial, 
        const BoardCell& final) const noexcept override;

    bool IsAnyObstacles(const Board& board, const BoardCell& initial, 
        const BoardCell& final) const noexcept override;
};
