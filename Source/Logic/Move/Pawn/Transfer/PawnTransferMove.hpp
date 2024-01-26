#pragma once

#include "Logic/Move/DefaultMove/DefaultMove.hpp"
#include "Logic/Move/Transfer/TransferMove.hpp"

class PawnTransferMove: public TransferMove
{
public:
	PawnTransferMove() = delete;
	PawnTransferMove(const PawnTransferMove&) = default;
	PawnTransferMove(PawnTransferMove&&) = default;

	PawnTransferMove(const DefaultMove& defaultMove,
        const DefaultMove& startMove);

	~PawnTransferMove() = default;

    BasicMove* Clone() const noexcept override;

private:
    void SpawnLegalMoves(Board& board, BoardCell& initial, 
        MovePairContainer& moves) noexcept(false) override;

    bool IsBasicAlright(const BoardCell& initial, 
        const BoardCell& final) const noexcept override;
    
    bool IsUnderDistance(const BoardCell& initial, 
        const BoardCell& final) const noexcept override;

private:
    const DefaultMove m_StartMove;
};
