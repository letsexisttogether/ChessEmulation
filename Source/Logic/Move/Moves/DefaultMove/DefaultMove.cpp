#include "DefaultMove.hpp"

DefaultMove::DefaultMove(const DefaultMove& move)
    : m_Rank{ move.m_Rank }, m_File{ move.m_File }
{}

DefaultMove::DefaultMove(const Rank rank, const File file)
	: m_Rank{ rank }, m_File{ file }
{}


bool DefaultMove::IsUnderDistance(const DefaultMove& move) 
    const noexcept
{
    bool isRankUnderDistance = false;
    bool isFileUnderDistance = false;

    if (const Rank moveRank = move.GetRank(); 
        m_Rank < 0)
    {
        isRankUnderDistance = (m_Rank <= moveRank);
    }
    else if (m_Rank > 0)
    {
        isRankUnderDistance = (m_Rank >= moveRank);
    }
    else 
    {
        isRankUnderDistance = (!moveRank);
    }

    if (const File moveFile = move.GetFile();
        m_File < 0)
    {
        isFileUnderDistance = (m_File <= moveFile);
    }
    else if (m_File > 0)
    {
        isFileUnderDistance = (m_File >= moveFile);
    }
    else 
    {
        isFileUnderDistance = !(moveFile);
    }

    return isRankUnderDistance && isFileUnderDistance;
}

DefaultMove::Distance DefaultMove::GetDistance() const noexcept
{
    return Distance{ m_Rank, m_File };
}

DefaultMove::Rank DefaultMove::GetRank() const noexcept
{
    return m_Rank;
}

DefaultMove::File DefaultMove::GetFile() const noexcept
{
    return m_File;
}

bool DefaultMove::operator == (const DefaultMove& move) 
    const noexcept
{
    return (m_Rank == move.m_Rank && m_File == move.m_File);
}

