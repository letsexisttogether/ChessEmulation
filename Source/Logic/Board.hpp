#pragma once

#include <array>

#include "Constants.hpp"
#include "Piece.hpp"

/**
* Auxillary class for representing board cell
* in params for board functions
*/ 
struct BoardCell
{
    BoardCell(const CNST::Rank rank, const CNST::File file) noexcept;

    auto operator == (const BoardCell& otherCell) const noexcept -> bool;
    auto operator != (const BoardCell& otherCell) const noexcept -> bool;
    
    static constexpr auto MinRank = CNST::Rank{ 'a' };
    static constexpr auto MaxRank = CNST::Rank{ 'h' };
    static constexpr auto MinFile = CNST::File{ 1 };
    static constexpr auto MaxFile = CNST::File{ 8 };

    struct Hash
    {
        auto operator () (const BoardCell& cell) const noexcept -> std::size_t;
    };

    struct Equal 
    {
        auto operator () (const BoardCell& left, const BoardCell& right)
            const noexcept -> bool;
    };

    CNST::Rank Rank{};
    CNST::File File{};
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
