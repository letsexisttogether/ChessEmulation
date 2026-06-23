#pragma once

#include <array>

#include "Piece.hpp"


/**
* Auxillary class for representing board cell
* in params for board functions
*/ 
struct BoardCell
{
    using RankType = unsigned char;
    using FileType = std::uint8_t;

    BoardCell(const RankType rank, const FileType file);

    auto operator == (const BoardCell& otherCell) const noexcept -> bool;
    auto operator != (const BoardCell& otherCell) const noexcept -> bool;
    
    static constexpr auto MinRank = RankType{ 'a' };
    static constexpr auto MaxRank = RankType{ 'h' };
    static constexpr auto MinFile = FileType{ 1 };
    static constexpr auto MaxFile = FileType{ 8 };

    struct Hash
    {
        auto operator () (const BoardCell& cell) const noexcept -> std::size_t;
    };

    struct Equal 
    {
        auto operator () (const BoardCell& left, const BoardCell& right)
            const noexcept -> bool;
    };

    RankType Rank{};
    FileType File{};
};
 

/**
* @brief Representation of the board
*
* @details Stores the actual board rotated  
*/
class Board final
{
public:
    using RawBoard = std::array<std::uint32_t, 8>;

public:
    static auto CreateDefaultBoard() -> Board;
    
public:
    explicit Board(const RawBoard& board) noexcept;

    auto GetCellContent(const BoardCell cell) const -> Piece;

    auto Move(const BoardCell fromCell, const BoardCell toCell) -> void;

private:
    static constexpr auto BytesPerCell = 4u;
    static constexpr auto PieceMask = (1u << BytesPerCell) - 1u;

private:
    RawBoard m_Board{};
};

/**
*       h, g, f, e, d, c, b, a
*   1  
*   2
*   3
*   4
*   5
*   6
*   7
*   8
*/
