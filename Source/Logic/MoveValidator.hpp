#pragma once

#include <vector>
#include <unordered_set>

#include "Logic/Board.hpp"
#include "Logic/Move.hpp"

class PawnMoveGenerator
{
public:
    using ValidCells = std::unordered_set<BoardCell,
        BoardCell::Hash, BoardCell::Equal>;

public:
    PawnMoveGenerator(const Board& board) noexcept;

    auto GenerateMoves(const BoardCell& fromCell) const -> ValidCells; 

private:
    using PossibleMoves = std::vector<Move>;

private:
    const Board& m_Board;
    const PossibleMoves m_WhiteMoves
    { 
        { 0, 1 }, { 0, 2 }, { 1, 1 }, { -1, 1 }
    };
    const PossibleMoves m_BlackMoves
    { 
        { 0, -1 }, { 0, -2 }, { -1, 1 }, { -1, -1 }
    };
};

class MoveValidator
{
public:
    MoveValidator(const Board& board);

    auto IsMoveValid(const BoardCell fromCell, const BoardCell toCell)
        const -> bool;

private:
    const Board& m_Board;
};
