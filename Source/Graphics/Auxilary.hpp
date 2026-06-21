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
        '-', 'p', 'r', 'n', 'b', 'q', 'k'
    };

    const auto pieceSymbol = pieces.at(piece.GetPieceType());

    const auto finalPieceSymbol = static_cast<char>(((!piece.IsWhite()) ? 
        (std::toupper(pieceSymbol)) : (pieceSymbol)));

    std::cout << finalPieceSymbol << ((isLastInRow) ? ('\n') : (' '));
}

inline auto PrintBoard(const Board& board) -> void
{
    for (auto file = BoardCell::MinFile; file <= BoardCell::MaxFile; ++file)
    {
        std::cout << (BoardCell::MaxFile - file + BoardCell::MinFile) << "  ";

        for (auto rank = BoardCell::MinRank; rank <= BoardCell::MaxRank; ++rank)
        {
            const auto piece = board.GetCellContent({ rank, file });

            PrintPiece(piece, rank == BoardCell::MaxRank);
        }
    }

    std::cout << "\n   a b c d e f g h\n" << std::endl;
}

