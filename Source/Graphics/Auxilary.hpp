#pragma once

#include <iostream>
#include <cctype>

#include "Logic/Board.hpp"
#include "Logic/Piece.hpp"

inline auto PrintPiece(const Piece& piece, const bool isLastInRow)
    noexcept -> void
{
    constexpr auto pieces = std::array<char, 7>
    {
        '0', 'p', 'r', 'n', 'b', 'q', 'k'
    };

    const auto pieceSymbol = pieces.at(piece.GetPieceType());

    const auto finalPieceSymbol = static_cast<char>(((!piece.IsWhite()) ? 
        (std::toupper(pieceSymbol)) : (pieceSymbol)));

    std::cout << finalPieceSymbol << ((isLastInRow) ? ('\n') : (' '));
}

inline auto PrintBoard(const Board& board) -> void
{
    for (auto file = Board::MinFile; file <= Board::MaxFile; ++file)
    {
        std::cout << (Board::MaxFile - file + Board::MinFile) << "  ";

        for (auto rank = Board::MinRank; rank <= Board::MaxRank; ++rank)
        {
            const auto piece = board.GetCellContent(rank, file);

            PrintPiece(piece, rank == Board::MaxRank);
        }
    }

    std::cout << "\n   a b c d e f g h" << std::endl;
}

