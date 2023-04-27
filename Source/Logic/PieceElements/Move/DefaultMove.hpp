#pragma once

#include "MoveSpecs/MoveSpecs.hpp"

// I've changed my mind: forward-declaration is really a good thing
class Board;
class BoardCell;

class DefaultMove
{
public:
	DefaultMove() = delete;
	DefaultMove(const DefaultMove&) = delete;
	DefaultMove(DefaultMove&&) = delete;

	DefaultMove(const MoveSpecs& defaultMove);

	virtual ~DefaultMove() = default;

	// Exceptions allowed to make tests 
	virtual bool CheckRequirements(const Board& board, 
		const BoardCell& initial, const BoardCell& final) const noexcept(false);

	virtual void HandleMove(Board& board, BoardCell& initial, BoardCell& final /* DeadBoard& deadBoard*/) const noexcept; 

	inline const MoveSpecs& GetMoveSpecs() const noexcept { return m_DefaultMove; }

	DefaultMove& operator = (const DefaultMove&) = delete;
	DefaultMove& operator = (DefaultMove&&) = delete;

protected:
	MoveSpecs m_DefaultMove;
};