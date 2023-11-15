#include "CellIndexSpawner.hpp"

CellIndexSpawner::CellIndexSpawner(const BoardCellIndex& start,
        const BoardCellIndex& step,
        const BoardCellIndex& lowest, const BoardCellIndex& highest)
    : Super{ start, step, lowest, highest }
{}

void CellIndexSpawner::ChangeNextInstance() noexcept(false)
{
    m_NextInstance.SetFile(m_NextInstance.GetFile() + m_Step.GetFile());

    if (!CheckColumnBoundries())
    {
        m_NextInstance.SetFile(m_Start.GetFile());
        m_NextInstance.SetRank(m_NextInstance.GetRank() + m_Step.GetRank());
    }
}

bool CellIndexSpawner::CheckColumnBoundries() const noexcept
{
    return (m_NextInstance.GetFile() <= m_Highest.GetFile())
        && (m_NextInstance.GetFile() >= m_Lowest.GetFile());
}

bool CellIndexSpawner::CheckRowBoundries() const noexcept
{
    return (m_NextInstance.GetRank() <= m_Highest.GetRank())
        && (m_NextInstance.GetRank() >= m_Lowest.GetRank());
}
