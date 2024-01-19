#pragma once

#include "DefaultMove/DefaultMove.hpp"
#include "MoveEffect/MoveEffect.hpp"

// I've changed my mind: forward-declaration is really a good thing
class Board;
class BoardCell;

class BasicMove
{
public:
	BasicMove() = delete;
	BasicMove(const BasicMove&) = default;
	BasicMove(BasicMove&&) = default;

	BasicMove(const Board& board, const DefaultMove& defaultMove);

	virtual ~BasicMove() = default;

	virtual MoveEffect CheckRequirements(const BoardCell& initial, 
            const BoardCell& final) const noexcept;

    virtual BasicMove* Clone() const noexcept;

	BasicMove& operator = (const BasicMove&) = delete;
	BasicMove& operator = (BasicMove&&) = delete;

protected:
    MoveEffect DefinePossibleMoveEffect(const BoardCell& initial, 
            const BoardCell& final) const noexcept;

    virtual bool CheckDistance(const BoardCell& initial, 
            const BoardCell& final) const noexcept;
    virtual bool CheckObstacles(const BoardCell& initial, 
            const BoardCell& final) const noexcept;

private:
    bool CheckSameSide(const BoardCell& initial, 
            const BoardCell& final) const noexcept;

protected:
    const Board& m_Board;
	DefaultMove m_DefaultMove;
};