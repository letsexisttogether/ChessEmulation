#include "CellCreator.hpp"

#include <exception>

CellCreator::CellCreator(const BoardCellIndex& start, 
            const Side startSide,
            const BoardCellIndex::Rank limitRank, 
            const BoardCellIndex::File limitFile,
            const BoardCellIndex::File fileStep,
            const BoardCellIndex::Rank rankStep,
            TextureLoader* loader)
    : m_NextIndex{ start }, m_NextSide{ startSide },
    m_StartFile{ start.GetFile() }, m_LimitRank{ limitRank }, 
    m_LimitFile{ limitFile }, m_FileStep{ fileStep }, 
    m_RankStep{ rankStep }, m_TextureLoader{ loader }
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

    m_NextIndex.SetFile(m_NextIndex.GetFile() + m_FileStep);

    if (m_NextIndex.GetFile() > m_LimitFile)
    {
        m_NextIndex.SetFile(m_StartFile);
        m_NextIndex.SetRank(m_NextIndex.GetRank() + m_RankStep);
    }

    if (m_NextIndex.GetRank() > m_LimitRank) 
    {
        throw std::exception
        { 
            "The next cell index is out of the specified range" 
        };
    }
    
}

