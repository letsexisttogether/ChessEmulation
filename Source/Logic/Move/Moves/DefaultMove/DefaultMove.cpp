#include "DefaultMove.hpp"

DefaultMove::DefaultMove(const Rank rank, const File file)
	: m_Rank{ rank }, m_File{ file }
{}

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

bool DefaultMove::operator >= (const DefaultMove& move) 
    const noexcept
{
    return (m_Rank >= move.m_Rank && m_File >= move.m_File);
} 

bool DefaultMove::operator <= (const DefaultMove& move) 
    const noexcept
{
    return (m_Rank <= move.m_Rank && m_File <= move.m_File);
} 
