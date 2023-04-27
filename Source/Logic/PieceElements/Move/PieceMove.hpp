#pragma once

#include "MoveSpecs/MoveSpecs.hpp"

// I've changed my mind: forward-declaration is really a good thing
class Board;
class BoardCell;

class PieceMove
{
public:
	PieceMove() = delete;
	PieceMove(const PieceMove&) = delete;
	PieceMove(PieceMove&&) = delete;

	PieceMove(const MoveSpecs& defaultMove);

	virtual ~PieceMove() = default;

	// Exceptions allowed to make tests 
	virtual bool CheckRequirements(const Board& board, 
		const BoardCell& initial, const BoardCell& final) const noexcept(false);

	virtual void HandleMove(BoardCell& initial, BoardCell& final /* DeadBoard deadBoard*/) const noexcept; 

	inline const MoveSpecs& GetMoveSpecs() const noexcept { return m_DefaultMove; }

	PieceMove& operator = (const PieceMove&) = delete;
	PieceMove& operator = (PieceMove&&) = delete;

protected:
	MoveSpecs m_DefaultMove;
};