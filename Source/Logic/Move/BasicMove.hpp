#pragma once

#include <utility>
#include <vector>
#include <memory>

#include "DefaultMove/DefaultMove.hpp"
#include "Logic/Board/Cell/Index/BoardCellIndex.hpp"

class Match;
class Board; 
class BoardCell;

class BasicMove
{
public:
    using MovePair = std::pair<BasicMove*, 
        BoardCellIndex>;

    using MovePairContainer = std::vector<MovePair>;

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

    virtual void SpawnLegalMoves(Board& board, 
        BoardCell& initial, 
        MovePairContainer& moves) 
        noexcept(false) = 0;

	BasicMove& operator = (const BasicMove&) = delete;
	BasicMove& operator = (BasicMove&&) = delete;

    bool TryAct(Board& board, BoardCell& initial,
        BoardCell& final, const bool shouldCheckKing);

    virtual bool IsBasicAlright(const BoardCell& initial, 
        const BoardCell& final) const noexcept = 0;
    
    virtual bool IsUnderDistance(const BoardCell& initial, 
        const BoardCell& final) const noexcept(false);

    virtual bool IsAnyObstacles(const Board& board, 
        const BoardCell& initial, const BoardCell& final) 
        const noexcept;

protected:
    const DefaultMove m_DefaultMove;
};
