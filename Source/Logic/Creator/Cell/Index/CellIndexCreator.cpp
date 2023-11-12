#include "CellIndexCreator.hpp"

#include <stdexcept>

CellIndexCreator::CellIndexCreator(const BoardCellIndex& start,
        const BoardCellIndex& step,
        const BoardCellIndex& lowest, const BoardCellIndex& highest)
    : m_NextIndex{ start }, m_Start{ start }, m_Step{ step },
    m_Lowest{ lowest }, m_Highest{ highest }
{}

BoardCellIndex CellIndexCreator::CreateIndex() noexcept(false)
{
    BoardCellIndex index{ m_NextIndex }; 

    ChangeNextIndex();

    return index;
}

void CellIndexCreator::ChangeNextIndex() noexcept(false)
{
    m_NextIndex.SetFile(m_NextIndex.GetFile() + m_Step.GetFile());

    if (!CheckFileBoundries())
    {
        m_NextIndex.SetFile(m_Start.GetFile());
        m_NextIndex.SetRank(m_NextIndex.GetRank() + m_Step.GetRank());
    }

    if (!CheckRankBoundries())
    {
        throw std::exception
        { 
            "The next cell index is out of the specified range" 
        };
    }
}


bool CellIndexCreator::CheckFileBoundries() const noexcept
{
    return  (m_NextIndex.GetFile() <= m_Highest.GetFile())
        && (m_NextIndex.GetFile() >= m_Lowest.GetFile());
}

bool CellIndexCreator::CheckRankBoundries() const noexcept
{
    return  (m_NextIndex.GetRank() <= m_Highest.GetRank())
        && (m_NextIndex.GetRank() >= m_Lowest.GetRank());
}
