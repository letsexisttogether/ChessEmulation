#include "CellCreator.hpp"

#include <exception>

CellCreator::CellCreator(const PieceSideHolder& sideHolder,
        IndexSpawner* indexCreator, 
        PositionSpawner* positionCreator,
        TextureLoader* loader)
    : m_SideHolder{ sideHolder }, m_IndexCreator{ indexCreator }, 
    m_PositionCreator{ positionCreator }, m_TextureLoader{ loader }
{}

BoardCell CellCreator::GetInstance() noexcept(false)
{
    BoardCell cell{ m_IndexCreator->GetInstance() };

    cell.SetTexture(m_TextureLoader->GetInstance(m_SideHolder.GetSide()));
    m_SideHolder.SetOppositeSide();

    cell.SetPosition(m_PositionCreator->GetInstance());

    return cell; 
}

