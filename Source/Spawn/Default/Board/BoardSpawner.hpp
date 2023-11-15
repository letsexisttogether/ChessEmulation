#pragma once

#include <vector>

#include "Spawn/Associative/Storage/Objects/ObjectsStorage.hpp"
#include "Spawn/Associative/Storage/Pointers/PointersStorage.hpp"
#include "Spawn/Default/DefaultSpawner.hpp"

#include "Logic/Board/Board.hpp"

class BoardSpawner : public DefaultSpawner<Board>
{
public:
    using OrderContainer = std::vector<PieceType>;
    using PieceSpawner = AssociativeSpawner<PieceType, Piece*>;

    using CellSpawner = DefaultSpawner<BoardCell>;

    using ObjStorage = ObjectsStorage<PieceSide, OrderContainer>;
    using PtrStorage = PointersStorage<PieceSide, PieceSpawner>;

    using Counter = std::size_t;
    
public:
    BoardSpawner() = delete;
    BoardSpawner(const BoardSpawner&) = delete;
    BoardSpawner(BoardSpawner&&) = delete;

    BoardSpawner(ObjStorage* piecesOrder, PtrStorage* piecesSpawners,
            CellSpawner* cellSpawner, const Counter blankCellsCount);

    ~BoardSpawner() = default;

    Board GetInstance() noexcept(false) override;

    BoardSpawner& operator = (const BoardSpawner&) = delete;
    BoardSpawner& operator = (BoardSpawner&&) = delete;

private:
    void FillCells(Board& board, const PieceSide side) noexcept(false);
    
    void FillWithBlank(Board& board) noexcept(false);

private:
    std::unique_ptr<ObjStorage> m_PieceOrder;
    std::unique_ptr<PtrStorage> m_PieceSpawners;

    std::unique_ptr<CellSpawner> m_CellSpawner;

    const Counter m_BlankCellsCount;
};
