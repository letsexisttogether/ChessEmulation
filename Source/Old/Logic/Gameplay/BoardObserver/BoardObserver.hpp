#pragma once

#include "Logic/Board/Cell/BoardCell.hpp"
#include "Logic/Piece/Side/PieceSide.hpp"
#include "Logic/Piece/Type/PieceType.hpp"
#include <unordered_map>
#include <vector>

class Board;

class BoardObserver
{
public:
    using PiecesContainer = std::vector<const Piece*>;
    using CellContainer = std::vector<const BoardCell*>;

public:
    BoardObserver() = default;
    
    BoardObserver(const BoardObserver&) = default;
    BoardObserver(BoardObserver&&) = default;

    ~BoardObserver() = default;

    void AddPiece(BoardCell* cell) noexcept(false);

    void UpdatePiece(BoardCell* cell) noexcept(false);

    void DeletePiece(const PieceSide side, const PieceType type)
        noexcept(false);

    const Piece& GetPiece(const PieceSide side, 
        const PieceType type) const noexcept(false);
    
    PiecesContainer GetPieces(const PieceSide side) 
        const noexcept;

    bool IsKingSave(const Board& board, const PieceSide side) 
        const noexcept(false);
    
private:
    CellContainer& GetCells(const PieceSide side) noexcept;
    const CellContainer& GetContainer(const PieceSide side) const noexcept;

    std::size_t FindCell(const PieceSide side, 
        const PieceType type) const noexcept(false);

    void CheckCell(const BoardCell* cell) const noexcept(false);

private:
    CellContainer m_White{};
    CellContainer m_Black{};
};
