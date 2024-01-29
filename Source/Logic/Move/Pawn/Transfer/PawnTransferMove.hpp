#pragma once

#include "Logic/Move/DefaultMove/DefaultMove.hpp"
#include "Logic/Move/Transfer/TransferMove.hpp"

class PawnTransferMove: public TransferMove
{
public:
	PawnTransferMove() = delete;
	PawnTransferMove(const PawnTransferMove&) = default;
	PawnTransferMove(PawnTransferMove&&) = default;

	PawnTransferMove(const DefaultMove& defaultMove);

	~PawnTransferMove() = default;

    BasicMove* Clone() const noexcept override;

    void SpawnLegalMoves(Board& board, BoardCell& initial, 
        MovePairContainer& moves) noexcept(false) override; 

private:
    bool IsBasicAlright(const BoardCell& initial, 
        const BoardCell& final) const noexcept override;
};
