#pragma once

#include "Logic/Move/Moves/BasicMove.hpp"

class PawnMove : public BasicMove 
{
public:
	PawnMove() = delete;
    PawnMove(const PawnMove&) = default;
	PawnMove(PawnMove&&) = default;

	PawnMove(const DefaultMove& defaultMove, 
        const DefaultMove& maximumStartMove);

	~PawnMove() = default;

    MoveEffect Try(const Match& match) 
        const noexcept override;

    BasicMove* Clone() const noexcept override;

protected:
    MoveEffect DefinePossibleMoveEffect(const Match& match) 
        const noexcept(false) override;

    bool IsUnderDistance(const BoardCell& initial, 
        const BoardCell& final) 
        const noexcept override;

private:
    const DefaultMove m_MaximumStartMove;
};
