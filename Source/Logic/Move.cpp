#include "Move.hpp"

#include <utility>

Move::Move(const Board& board, const BoardCell& fromCell,
    const BoardCell& toCell) noexcept
     : m_Rank(fromCell.Rank - toCell.Rank),
     m_File(fromCell.File - toCell.File)
{
    const auto piece = board.GetCellContent(fromCell);
    const auto enemy = board.GetCellContent(toCell);

    m_IsAttacking = static_cast<bool>(enemy);
 
    if (m_Rank && !m_File || !m_Rank && m_File) 
    {
        m_Type = MoveType::Side;
    }
    else if (m_Rank && m_File)
    {
        m_Type = ((m_Rank == m_File) ? 
            (MoveType::Diagonal) : (MoveType::Wierd));
    }
}

auto Move::GetRank() const noexcept -> Rank
{
    return m_Rank;
}

auto Move::GetFile() const noexcept -> File
{
    return m_File;
}

auto Move::GetType() const noexcept -> MoveType
{
    return MoveType(std::to_underlying(m_Type) & 0x7);
}

auto Move::IsAttacking() const noexcept -> bool 
{
    return m_IsAttacking;
}

auto Move::AsPack() const noexcept -> std::tuple<Rank, File, MoveType, bool>
{
    return { GetRank(), GetFile(), GetType(), IsAttacking() };
}

Move::operator bool () const noexcept
{
    return m_Type != MoveType::None;
}
