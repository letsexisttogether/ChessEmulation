#pragma once

#include <array>

#include "Piece.hpp"

/**
* @brief Representation of the board
*
* @details Stores the actual board rotated  
*/
class Board final
{
public:
    // a, b, c, d, e, f, g, h
    using Rank = unsigned char;
    // 1, 2, 3, 4, 5, 6, 7, 8
    using File = std::uint8_t;

    using Row = std::uint32_t;
    using RawBoard = std::array<Row, 8>;

public:
    explicit Board(const RawBoard& board) noexcept;

    auto GetCellContent(const Rank rank, const File file) const -> Piece;

public:
    static constexpr auto MinRank = 'a';
    static constexpr auto MaxRank = 'h';
    static constexpr auto MinFile = 1;
    static constexpr auto MaxFile = 8;

private:
    static constexpr auto BytesPerCell = 4u;
    static constexpr auto PieceByes = ((1u << (BytesPerCell * 4)) - 1) / 15;

private:
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
    RawBoard m_Board{};
};
