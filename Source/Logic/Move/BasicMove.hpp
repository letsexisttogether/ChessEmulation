#pragma once

class Match;
class Board; 
class BoardCell;

#include "DefaultMove/DefaultMove.hpp"

class BasicMove
{
public:
	BasicMove() = delete;
	BasicMove(const BasicMove&) = default;
	BasicMove(BasicMove&&) = default;

	BasicMove(const DefaultMove& defaultMove);

	virtual ~BasicMove() = default;

	virtual bool IsConditionSatisfied(Board& board, BoardCell& initial, 
        BoardCell& final, const bool shouldCheckKing) noexcept(false) = 0;

    virtual void DoMove(Board& board, BoardCell& initial, 
        BoardCell& final) noexcept = 0;

    virtual void UndoMove(Board& board, BoardCell& initial, 
        BoardCell& final) noexcept = 0;

    virtual void CompleteMove(Match& match) noexcept = 0;

    virtual BasicMove* Clone() const noexcept = 0;

	BasicMove& operator = (const BasicMove&) = delete;
	BasicMove& operator = (BasicMove&&) = delete;

protected:
    virtual bool IsBasicAlright(BoardCell& initial, 
        BoardCell& final) const noexcept = 0;
    
    virtual bool IsUnderDistance(BoardCell& initial, 
        BoardCell& final) const noexcept;

    virtual bool IsAnyObstacles(Board& board, BoardCell& initial, 
        BoardCell& final) const noexcept;

protected:
    const DefaultMove m_DefaultMove;
};
