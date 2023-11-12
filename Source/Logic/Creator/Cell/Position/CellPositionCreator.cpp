#include "CellPositionCreator.hpp"

CellPositionCreator::CellPositionCreator(const Position& start, 
        const Position& step, const Position& lowest, const Position& highest)
    : ConsecutiveCreator<Position>{ start, step, lowest, highest }
{}

void CellPositionCreator::ChangeNextInstance() noexcept(false)
{
    m_NextInstance.x += m_Step.x;

    if (!CheckColumnBoundries())
    {
        m_NextInstance.x = m_Start.x;
        m_NextInstance.y += m_Step.y;
    }

}

bool CellPositionCreator::CheckColumnBoundries() const noexcept
{
    return (m_NextInstance.x <= m_Highest.x)
        && (m_NextInstance.x >= m_Lowest.x);
}

bool CellPositionCreator::CheckRowBoundries() const noexcept
{
    return (m_NextInstance.y <= m_Highest.y)
        && (m_NextInstance.y >= m_Lowest.y);
}
