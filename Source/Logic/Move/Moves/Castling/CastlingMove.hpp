#pragma once 

#include "Logic/Move/Moves/Knight/KnightMove.hpp"

class CastlingMove : public KnightMove 
{
public:
	CastlingMove() = delete;
	CastlingMove(const CastlingMove&) = default;
	CastlingMove(CastlingMove&&) = default;

	CastlingMove(const DefaultMove& defaultMove);

	~CastlingMove() = default;

    BasicMove* Clone() const noexcept override;

protected:
    MoveEffect DefinePossibleMoveEffect(const BoardCell& initial,
        const BoardCell& final) const noexcept(false) override;

    bool IsBasicAdhered(const BoardCell& initial,
        const BoardCell& final) const noexcept(false) override;
};
