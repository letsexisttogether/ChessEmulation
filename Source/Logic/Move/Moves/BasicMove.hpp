#pragma once

#include "DefaultMove/DefaultMove.hpp"
#include "MoveEffect/MoveEffect.hpp"

class Match;
class Board;
class BoardCell;

class BasicMove
{
public:
	BasicMove() = delete;
	BasicMove(const BasicMove&) = default;
	BasicMove(BasicMove&&) = default;

	BasicMove(const DefaultMove& defaultMove);

	virtual ~BasicMove() = default;

	virtual MoveEffect Try(const Match& match) 
        const noexcept;

    virtual BasicMove* Clone() const noexcept;

	BasicMove& operator = (const BasicMove&) = delete;
	BasicMove& operator = (BasicMove&&) = delete;

protected:
    virtual MoveEffect DefinePossibleMoveEffect(const Match& match) 
        const noexcept(false);

    virtual bool IsUnderDistance(const BoardCell& initial, 
        const BoardCell& final) const noexcept;
    
    virtual bool IsAnyObstacles(const Board& board,
        const BoardCell& initial, const BoardCell& final) 
        const noexcept;

    bool IsSameSide(const BoardCell& initial,
        const BoardCell& final) const noexcept(false);

protected:
	DefaultMove m_DefaultMove;
};