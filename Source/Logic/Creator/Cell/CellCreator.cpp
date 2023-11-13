#include "CellCreator.hpp"

#include <exception>

CellCreator::CellCreator(const PieceSideHolder& sideHolder,
        IndexCreator* indexCreator, 
        PositionCreator* positionCreator,
        TextureLoader* loader)
    : m_SideHolder{ sideHolder }, m_IndexCreator{ indexCreator }, 
    m_PositionCreator{ positionCreator }, m_TextureLoader{ loader }
{}

BoardCell CellCreator::CreateCell(const TextureIndex index) noexcept(false)
{
    BoardCell cell{ m_IndexCreator->CreateInstance() };

    cell.setTexture(*m_TextureLoader->LoadTexture(m_SideHolder.GetSide()));
    m_SideHolder.SetOppositeSide();

    cell.setPosition(m_PositionCreator->CreateInstance());

    return cell; 
}

