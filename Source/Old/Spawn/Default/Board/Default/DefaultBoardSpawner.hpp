#pragma once

#include "Spawn/Default/Board/BoardSpawner.hpp"

class DefaultBoardSpawner : public BoardSpawner
{
public:
    DefaultBoardSpawner();
    DefaultBoardSpawner(const DefaultBoardSpawner&) = delete;
    DefaultBoardSpawner(DefaultBoardSpawner&&) = delete;

    ~DefaultBoardSpawner() = default;

    DefaultBoardSpawner& operator = (const DefaultBoardSpawner&) = delete;
    DefaultBoardSpawner& operator = (DefaultBoardSpawner&&) = delete;

protected:
    sf::Sprite GetSpriteExample() const noexcept override;

    OrderSpawnerStorage* GetPieceOrder() const noexcept override;
    PieceSpawnerStorage* GetPieceStorage() const noexcept override; 
    CellSpawner* GetCellSpawner() const noexcept override;
};

