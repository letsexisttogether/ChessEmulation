#include "Move.hpp"

Move::Move(const Rank rank, const File file) noexcept
    : m_Rank{ rank }, m_File{ file }, m_Type{ DetermineType() } {}

Move::Move(const BoardCell& fromCell, const BoardCell& toCell)
    noexcept : Move(static_cast<Rank>(fromCell.Rank) - toCell.Rank,
        static_cast<File>(fromCell.File) - toCell.File) {}


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
    return m_Type;
}

auto Move::DetermineType() const noexcept -> MoveType
{
    // Possible throw

    return MoveType::None;
}
