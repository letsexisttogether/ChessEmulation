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
    bool IsUnderDistance(BoardCell& initial, BoardCell& final)
        const noexcept override;

    bool IsAnyObstacles(Board& board, BoardCell& initial, 
        BoardCell& final) const noexcept override;
};
