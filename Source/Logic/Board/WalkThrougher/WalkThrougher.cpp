#include "WalkThrougher.hpp"

#include "Logic/Board/Cell/BoardCell.hpp"


WalkThrougher::WalkThrougher(const BoardCellIndex& initial, 
        const BoardCellIndex& final, const BoardCellIndex& boundries)
    : m_Start{ initial }, m_End{ final },
    m_Boundries{ boundries }, m_Index{ m_Start }
{
    const auto possibleMove = m_End - m_Start;

    if (auto rank = possibleMove.GetRank(); rank > 0)
    {
        m_Step.SetRank(1);
    }
    else if (rank < 0)
    {
        m_Step.SetRank(-1);
    }

    if (const auto file = possibleMove.GetFile(); file > 0)
    {
        m_Step.SetFile(1);
    }
    else if (file < 0)
    {
        m_Step.SetFile(-1);
    }
}

const BoardCellIndex& WalkThrougher::GetIndex() noexcept
{
    return m_Index;
}

const BoardCellIndex& WalkThrougher::GetNext() noexcept
{
    m_Index += m_Step;

    return m_Index;
}

bool WalkThrougher::IsEndReached() const noexcept
{
    return m_Index == m_End;
}

bool WalkThrougher::IsInBoundries() const noexcept
{
    const auto isRankInBoundries = (m_Index.GetRank() > 0)
        && m_Index.GetRank() <= m_Boundries.GetRank();

    const auto isFileInBoundries = (m_Index.GetFile() > 0)
        && m_Index.GetFile() <= m_Boundries.GetFile();

    return isRankInBoundries && isFileInBoundries;
}

void Reset() noexcept;
