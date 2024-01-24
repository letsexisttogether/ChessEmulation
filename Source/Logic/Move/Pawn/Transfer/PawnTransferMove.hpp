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
    bool IsBasicAlright(BoardCell& initial, BoardCell& final) 
        const noexcept override;
    
    bool IsUnderDistance(BoardCell& initial, BoardCell& final) 
        const noexcept override;

private:
    const DefaultMove m_StartMove;
};
