#pragma once

#include <vector>

#include "SFML/Graphics/Sprite.hpp"
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

    using OrderSpawnerStorage = ObjectsStorage<PieceSide, OrderContainer>;
    using PieceSpawnerStorage = PointersStorage<PieceSide, PieceSpawner>;

    using Counter = std::size_t;
    
public:
    BoardSpawner(const BoardSpawner&) = delete;
    BoardSpawner(BoardSpawner&&) = delete;

    BoardSpawner(const sf::Sprite& spriteExample,
            OrderSpawnerStorage* piecesOrder, 
            PieceSpawnerStorage* piecesSpawners,
            CellSpawner* cellSpawner, 
            const Counter blankCellsCount);

    virtual ~BoardSpawner() = default;

    Board GetInstance() noexcept(false) override;

    BoardSpawner& operator = (const BoardSpawner&) = delete;
    BoardSpawner& operator = (BoardSpawner&&) = delete;

protected:
    BoardSpawner();

    virtual sf::Sprite GetSpriteExample() const noexcept;

    virtual OrderSpawnerStorage* GetPieceOrder() const noexcept;
    virtual PieceSpawnerStorage* GetPieceStorage() const noexcept; 
    virtual CellSpawner* GetCellSpawner() const noexcept;

private:
    void FillCells(Board& board, const PieceSide side) noexcept(false);
    
    void FillWithBlank(Board& board) noexcept(false);

protected:
    const sf::Sprite m_SpriteExample;

    std::unique_ptr<OrderSpawnerStorage> m_PieceOrder;
    std::unique_ptr<PieceSpawnerStorage> m_PieceSpawners;

    std::unique_ptr<CellSpawner> m_CellSpawner;

    const Counter m_BlankCellsCount;
};
