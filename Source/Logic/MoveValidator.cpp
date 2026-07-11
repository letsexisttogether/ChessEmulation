#include "MoveValidator.hpp"

#include <utility>
#include <vector>
#include <stdexcept>

PawnMoveGenerator::PawnMoveGenerator(const Board& board) noexcept
    : m_Board{ board } {}

auto PawnMoveGenerator::GenerateMoves(const BoardCell& fromCell)
    const -> ValidCells
{
    const auto piece = m_Board.GetCellContent(fromCell); 
    if (piece.GetPieceType() != PieceType::Pawn)
    {
        throw std::logic_error{ "[PawnMoveGenerator] The piece isn't a pawn " };
    }

    const auto& possibleMoves = ((piece.IsWhite()) ?
        (m_WhiteMoves) : (m_BlackMoves));

    auto validCells = ValidCells{};
    validCells.reserve(possibleMoves.size());

    for (const auto& move : possibleMoves)
    {
        const auto toCell = BoardCell
        (
             fromCell.Rank + move.GetRank(),
             fromCell.File + move.GetFile()
        );

        validCells.insert(std::move(toCell));
    }

    return validCells;
}

auto MoveValidator::IsMoveValid(const BoardCell fromCell,
    const BoardCell toCell) const -> bool
{
    // Assuming fromCell contains Pawn

    auto movesGenerator = PawnMoveGenerator(m_Board);

    auto validCells = movesGenerator.GenerateMoves(fromCell);

    return true;
}
