#include "BoardCellIndex.hpp"


BoardCellIndex::BoardCellIndex(const Rank rank, const File file)
    : m_Rank{ rank }, m_File{ file }
{}

BoardCellIndex BoardCellIndex::operator + (const BoardCellIndex& index) noexcept
{
    return 
    { 
        static_cast<Rank>(m_Rank + index.m_Rank),
        static_cast<File>(m_File + index.m_File) 
    };
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


BoardCellIndex BoardCellIndex::operator - (const BoardCellIndex& index) noexcept
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
