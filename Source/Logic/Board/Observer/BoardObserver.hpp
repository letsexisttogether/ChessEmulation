#pragma once

#include <unordered_map>
#include <vector>

#include "Logic/Board/Cell/BoardCell.hpp"
#include "Logic/Piece/Type/PieceType.hpp"

class Board;

class BoardObserver
{
public:
    using IndexContainer 
        = std::unordered_multimap<PieceType, BoardCellIndex>;

public:
    BoardObserver() = default;
    BoardObserver(const BoardObserver&) = delete;
    BoardObserver(BoardObserver&& observer) = default;

    ~BoardObserver() = default;

    void SetBoard(Board& board) noexcept(false);

    void AddCell(const BoardCell& cell) noexcept(false);

    void UpdateCell(const BoardCellIndex& oldIndex,
        const BoardCell& newCell) noexcept(false);

    void DeleteCell(const BoardCellIndex& index, 
        const PieceSide side)
        noexcept(false);

    BoardCell& GetCell(const PieceSide side, const PieceType type) 
        noexcept(false);

    IndexContainer& GetIndices(const PieceSide side);

private:
    IndexContainer::iterator FindIndex(const PieceSide side,
        const PieceType type) noexcept(false);

    IndexContainer::iterator FindIndex(const BoardCellIndex& index,
        const PieceSide side) noexcept(false);

    void CheckBoard() const noexcept(false);

private:
    IndexContainer m_WhitePieces{};
    IndexContainer m_BlackPieces{};

    Board* m_Board{};
};
