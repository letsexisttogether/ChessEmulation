#pragma once

#include <cstdint>

class BoardCellIndex
{
public:
    // Not sure about the file type, but leave it like that for now
    using Rank = std::int8_t;
    using File = std::int8_t;

public:
    BoardCellIndex() = default;
    BoardCellIndex(const BoardCellIndex&) = default;
    BoardCellIndex(BoardCellIndex&&) = default;

    BoardCellIndex(const Rank rank, const File file);

    ~BoardCellIndex() = default;

    inline Rank GetRank() const noexcept { return m_Rank; }
    inline void SetRank(const Rank rank) noexcept { m_Rank = rank; }

    inline File GetFile() const noexcept { return m_File; }
    inline void SetFile(const File file) noexcept { m_File = file; }

    BoardCellIndex& operator = (const BoardCellIndex&) = default;
    BoardCellIndex& operator = (BoardCellIndex&&) = default;

    bool operator == (const BoardCellIndex& index) const noexcept;
    bool operator != (const BoardCellIndex& index) const noexcept;

    operator bool () const noexcept;

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
