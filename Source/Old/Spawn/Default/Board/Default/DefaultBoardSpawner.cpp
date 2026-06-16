#include "DefaultBoardSpawner.hpp"

#include "Logic/PieceElements/Piece/Side/SideHolder/PieceSideHolder.hpp"
#include "Spawn/Default/Cell/CellCreator.hpp"
#include "Spawn/Default/Consecutive/CellIndex/CellIndexSpawner.hpp"
#include "Spawn/Default/Consecutive/CellPosition/CellPositionSpawner.hpp"

DefaultBoardSpawner::DefaultBoardSpawner()
    : BoardSpawner{}
{}

BoardSpawner::OrderSpawnerStorage* DefaultBoardSpawner::GetPieceOrder() 
    const noexcept
{}

BoardSpawner::PieceSpawnerStorage* DefaultBoardSpawner::GetPieceStorage() 
    const noexcept
{}

BoardSpawner::CellSpawner* DefaultBoardSpawner::GetCellSpawner() 
    const noexcept
{

    PieceSideHolder sideHolder{ PieceSide::WHITE };
    
    CellCreator::IndexSpawner* indexSpawner = new CellIndexSpawner
    {
        BoardCellIndex{ 1, 'a' }, BoardCellIndex{ 1, 1 },
        BoardCellIndex{ 1, 'a' }, BoardCellIndex{ 8, 'h' }
    };

    CellCreator::PositionSpawner* positionSpawner = new CellPositionSpawner
    {
        sf::Vector2f{  }, sf::Vector2f{ 1.f, -1.f },
        sf::Vector2f{ 
    };

    

    return new CellCreator
    { 
        sideHolder,
        indexSpawner,
        positionSpawner,
        nullptr
    };
}

