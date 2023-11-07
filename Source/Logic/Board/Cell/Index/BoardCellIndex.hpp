#pragma once

#include <cstdint>

class BoardCellIndex
{
public:
    using Rank = std::uint8_t;
    using File = char;

public:
    BoardCellIndex() = default;
    BoardCellIndex(const BoardCellIndex&) = default;
    BoardCellIndex(BoardCellIndex&&) = default;

    BoardCellIndex(const Rank rank, const File file);

    ~BoardCellIndex() = default;

    inline Rank GetRank() const noexcept { return m_Rank; }
    inline File GetFile() const noexcept { return m_File; }

    BoardCellIndex operator + (const BoardCellIndex& index) noexcept;
    BoardCellIndex operator ++ (std::int32_t) noexcept;
    BoardCellIndex& operator ++ () noexcept;

    BoardCellIndex operator - (const BoardCellIndex& index) noexcept;
    BoardCellIndex operator -- (std::int32_t) noexcept;
    BoardCellIndex& operator -- () noexcept;

private:
    Rank m_Rank{};
    File m_File{};
};
