#include "WalkThrougher.hpp"

#include "Logic/Board/Cell/BoardCell.hpp"
#include <iostream>
#include <string>


WalkThrougher::WalkThrougher(const BoardCell& initial,
    const BoardCell& final, const BoardCellIndex& boundries)
    : m_Start{ initial.GetIndex() }, m_End{ final.GetIndex() },
    m_Boundries{ boundries }, m_Index{ m_Start }
{
        
    const DefaultMove possibleMove = final - initial;

    if (DefaultMove::Rank rank = possibleMove.GetRank();
        rank > 0)
    {
        m_Step.SetRank(1);
    }
    else if (rank < 0)
    {
        m_Step.SetRank(-1);
    }
    if (DefaultMove::File file = possibleMove.GetFile();
        file > 0)
    {
        m_Step.SetFile(1);
    }
    else if (file < 0)
    {
        m_Step.SetFile(-1);
    }
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
    const bool isRankInBoundries = (m_Index.GetRank() > 0)
        && m_Index.GetRank() <= m_Boundries.GetRank();

    const bool isFileInBoundries = (m_Index.GetFile() > 0)
        && m_Index.GetFile() <= m_Boundries.GetFile();

    return isRankInBoundries && isFileInBoundries;
}

void Reset() noexcept;
