#include "CellCreator.hpp"

#include <exception>

CellCreator::CellCreator(const BoardCellIndex& start,
        const Side startSide,
        const BoardCellIndex& limit,
        const BoardCellIndex& step,
        TextureLoader* loader)
    : m_NextIndex{ start }, m_NextSide{ startSide },
    m_StartFile{ start.GetFile() }, m_Limit{ limit }, 
    m_Step{ step }, m_TextureLoader{ loader }
{}


BoardCell CellCreator::CreateCell(const TextureIndex index) noexcept(false)
{
    BoardCell cell{ m_NextIndex };
    cell.setTexture(*m_TextureLoader->LoadTexture(m_NextSide));

    SetNextIndex();    

    return cell; 
}


void CellCreator::SetNextIndex() noexcept(false)
{
    m_NextSide = ((m_NextSide == Side::WHITE) ? 
            (Side::BLACK) : (Side::WHITE));

    m_NextIndex.SetFile(m_NextIndex.GetFile() + m_Step.GetFile());

    if (m_NextIndex.GetFile() > m_Limit.GetFile())
    {
        m_NextIndex.SetFile(m_StartFile);
        m_NextIndex.SetRank(m_NextIndex.GetRank() + m_Step.GetRank());
    }

    if (m_NextIndex.GetRank() > m_Limit.GetRank()) 
    {
        throw std::exception
        { 
            "The next cell index is out of the specified range" 
        };
    }
    
}

