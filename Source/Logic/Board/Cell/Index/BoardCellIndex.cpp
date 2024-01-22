#include "BoardCellIndex.hpp"


BoardCellIndex::BoardCellIndex(const Rank rank, const File file)
    : m_Rank{ rank }, m_File{ file }
{}

bool BoardCellIndex::operator == (const BoardCellIndex& index)
    const noexcept
{
    return m_Rank == index.m_Rank && m_File == index.m_File;
}

bool BoardCellIndex::operator != (const BoardCellIndex& index)
    const noexcept
{
    return !(*this == index);
}

BoardCellIndex::operator bool() const noexcept
{
    return m_Rank || m_File;
}

BoardCellIndex BoardCellIndex::operator + (const BoardCellIndex& index) 
    const noexcept
{
    return 
    { 
        static_cast<Rank>(m_Rank + index.m_Rank),
        static_cast<File>(m_File + index.m_File) 
    };
}

BoardCellIndex& BoardCellIndex::operator += (const BoardCellIndex& index) noexcept
{
    return *this = *this + index;
}

BoardCellIndex BoardCellIndex::operator ++ (std::int32_t) noexcept
{
    BoardCellIndex temp{ *this };
    ++(*this);

    return temp;
}

BoardCellIndex& BoardCellIndex::operator ++ () noexcept
{
    ++m_Rank;
    ++m_File;

    return *this;
}


BoardCellIndex BoardCellIndex::operator - (const BoardCellIndex& index) 
    const noexcept
{
    return 
    {
        static_cast<Rank>(m_Rank - index.m_Rank),
        static_cast<File>(m_File - index.m_File)
    };
}

BoardCellIndex BoardCellIndex::operator -- (std::int32_t) noexcept
{
    BoardCellIndex temp{ *this };
    --(*this);

    return temp;
}

BoardCellIndex& BoardCellIndex::operator -- () noexcept
{
    --m_Rank;
    --m_File;

    return *this;
}
