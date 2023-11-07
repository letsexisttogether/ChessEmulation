#pragma once

#include <cstdint>

class BoardCellIndex
{
public:
    // Not sure about the file type, but leave it like that for now
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


    bool operator == (const BoardCellIndex& index) const noexcept;

    BoardCellIndex operator + (const BoardCellIndex& index) const noexcept;
    BoardCellIndex operator ++ (std::int32_t) noexcept;
    BoardCellIndex& operator ++ () noexcept;

    BoardCellIndex operator - (const BoardCellIndex& index) const noexcept;
    BoardCellIndex operator -- (std::int32_t) noexcept;
    BoardCellIndex& operator -- () noexcept;

private:
    Rank m_Rank{};
    File m_File{};
};
