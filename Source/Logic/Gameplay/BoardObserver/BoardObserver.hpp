#pragma once

#include "Logic/Board/Cell/BoardCell.hpp"
#include <unordered_map>
#include <vector>

class BoardObserver
{
public:
    using PieceKey = std::pair<PieceSide, PieceType>;
    using PiecesMap = std::unordered_multimap<PieceKey, const BoardCell*>;

    using CellsOutContainer = std::vector<const BoardCell*>;

public:
    BoardObserver() = default;
    
    BoardObserver(const BoardObserver&) = default;
    BoardObserver(BoardObserver&&) = default;

    ~BoardObserver() = default;

    void AddPiece(const PieceSide side, const PieceType type, 
        const BoardCell*) noexcept;

    const BoardCell& GetPiece(const PieceSide side, 
        const PieceType type) const noexcept(false);
    
    CellsOutContainer GetAlivePieces(const PieceSide side)
        const noexcept;

private:
    PiecesMap& GetPiecesMap(const PieceSide side) const noexcept;

private:
    PiecesMap m_White{};
    PiecesMap m_Black{};
};
