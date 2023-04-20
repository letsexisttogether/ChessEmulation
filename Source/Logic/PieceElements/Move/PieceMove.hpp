#pragma once

#include "DefaultMove/DefaultMove.hpp"

// I've changed my mind: forward-declaration is really a good thing
class Board;
class BoardCell;

class PieceMove
{
public:
	PieceMove() = delete;
	PieceMove(const PieceMove&) = delete;
	PieceMove(PieceMove&&) = delete;

	PieceMove(const DefaultMove& defaultMove);

	virtual ~PieceMove() = default;

	// Exceptions allowed to make tests 
	virtual bool CheckRequirements(const Board& board, 
		const BoardCell& initial, const BoardCell& final) const noexcept(false);

	inline const DefaultMove& GetMoveSpecs() const noexcept { return m_DefaultMove; }

	PieceMove& operator = (const PieceMove&) = delete;
	PieceMove& operator = (PieceMove&&) = delete;

protected:
	DefaultMove m_DefaultMove;
};