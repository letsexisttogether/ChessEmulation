#pragma once

#include <cstdint>

class BoardCellIndex
{
public:
    // Not sure about the file type, but leave it as that for now
    using Rank = std::int8_t;
    using File = std::int8_t;

public:
    BoardCellIndex() = default;
    BoardCellIndex(const BoardCellIndex&) = default;
    BoardCellIndex(BoardCellIndex&&) = default;

    BoardCellIndex(const File file, const Rank rank);

    ~BoardCellIndex() = default;

    inline File GetFile() const noexcept { return m_File; }
    inline void SetFile(const File file) noexcept { m_File = file; }

    inline Rank GetRank() const noexcept { return m_Rank; }
    inline void SetRank(const Rank rank) noexcept { m_Rank = rank; }

    BoardCellIndex& operator = (const BoardCellIndex&) = default;
    BoardCellIndex& operator = (BoardCellIndex&&) = default;

    bool operator == (const BoardCellIndex& index) const noexcept;
    bool operator != (const BoardCellIndex& index) const noexcept;

    operator bool () const noexcept;

    BoardCellIndex operator + (const BoardCellIndex& index) const noexcept;
    BoardCellIndex& operator += (const BoardCellIndex& index) noexcept;
    BoardCellIndex operator ++ (std::int32_t) noexcept;
    BoardCellIndex& operator ++ () noexcept;

    BoardCellIndex operator - (const BoardCellIndex& index) const noexcept;
    BoardCellIndex operator -- (std::int32_t) noexcept;
    BoardCellIndex& operator -- () noexcept;

private:
    File m_File{};
    Rank m_Rank{};
};
