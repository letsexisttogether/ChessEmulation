#pragma once

#include "Logic/Move/Pawn/Transfer/PawnTransferMove.hpp"

class PawnDoubleTransferMove : public PawnTransferMove 
{
public:

public:
	PawnDoubleTransferMove() = delete;
	PawnDoubleTransferMove(const PawnDoubleTransferMove&) = default;
	PawnDoubleTransferMove(PawnDoubleTransferMove&&) = default;

	PawnDoubleTransferMove(const DefaultMove& defaultMove);
    
	~PawnDoubleTransferMove() = default;

    BasicMove* Clone() const noexcept override;

    void SpawnLegalMoves(Board& board, BoardCell& initial, 
        MovePairContainer& moves) noexcept(false) override;

protected:
    bool IsUnderDistance(const BoardCell& initial, 
        const BoardCell& final) const noexcept override;
    
    bool IsBasicAlright(const BoardCell &initial, 
        const BoardCell &final) const noexcept override;
};
