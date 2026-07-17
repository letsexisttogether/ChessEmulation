#include "MoveValidator.hpp"

#include <algorithm>
#include <stdexcept>

#include "Logic/Move.hpp"

/*
Piece types and moves: 
1. Pawn
  White:
    1. Up (0, 2) if on start - slide
    2. Up (0, 1) - slide
    3. Up-left (-1, 1) - attack
    4. Up-right (1, 1) - attack
  Black:
    1. Down (0, -2) if on start - slide 
    2. Down (0, 1) - slide
    3. Down-left (-1, -1) - attack
    4. Down-right (1, -1) - attack
2. Rook:
    1. Any one-sided (n/0, 0/n) - slide/attack
    2. Castling (slide)
3. Knight:
    1. Any (1/2, 2/1) - slide/attack
4. Bishop:
    1. Any diagonal direction (n, n) - slide/attack
5. Queen:
    1. Any one-sided direction
    2. Any diagonal direction
6. King:
    1. Any direction (1, 1) - slide/attack.
    2. Castling (slide)
General:
    1. Pieces can't cross any other piece on its way,
    except for knight and castling
    2. If move puts the piece's king in danger,
    the move is not possible.
*/


MoveValidator::MoveValidator(const Board& board) noexcept
    : m_Board{ board } {}

auto MoveValidator::IsMoveValid(const BoardCell& fromCell,
    const BoardCell& toCell) -> bool
{
    // Assuming fromCell contains Pawn

    /*
    auto movesGenerator = PawnMoveGenerator(m_Board);
    auto validCells = movesGenerator.GenerateMoves(fromCell);
    */

    return true;
}

auto MoveValidator::IsPathEmpty(BoardCell fromCell, const BoardCell& toCell)
    const -> bool
{
    if (fromCell == toCell)
    {
        return true;
    }

    const auto rankDiff = std::clamp(toCell.Rank - fromCell.Rank, -1, 1);
    const auto fileDiff = std::clamp(toCell.File - fromCell.File, -1, 1);

    fromCell.Rank += rankDiff;
    fromCell.File += fileDiff;

    for ( ; fromCell != toCell; fromCell.Rank += rankDiff,
        fromCell.File += fileDiff)
    {
        if (const auto piece = m_Board.GetCellContent(fromCell); piece)
        {
            return false;
        }
    }

    return true;
}

auto PawnMoveValidator::IsMoveValid(const BoardCell& fromCell,
    const BoardCell& toCell) -> bool
{
    const auto pawn = m_Board.GetCellContent(fromCell);
    const auto& [pawnType, pawnColor] = pawn.AsPack();

    const auto enemy = m_Board.GetCellContent(toCell);
    const auto& [enemyType, enemyColor] = enemy.AsPack();

    const auto move = Move{ m_Board, fromCell, toCell };
    const auto& [moveRank, moveFile, moveType, isAttack]
        = move.AsPack();

    if (!move)
    {
        throw std::runtime_error{ "[PawnMoveValidator] Move to the same cell" };
    }

    const auto isWhiteSuitable = pawnColor && (isAttack && moveFile == 1
        && (moveRank == -1 || moveRank == 1) || (moveFile == 2 && moveRank == 0
        && fromCell.File == m_WhiteStartFile));

    const auto isBlackSuitable = !pawnColor && (isAttack && moveFile == -1
        && (moveRank == -1 || moveRank == 1) || (moveFile == -2 && moveRank == 0
        && fromCell.File == m_BlackStartFile));

    return isWhiteSuitable || isBlackSuitable;
}

auto RookMoveValidator::IsMoveValid(const BoardCell& fromCell,
    const BoardCell& toCell) -> bool 
{
    const auto move = Move{ m_Board, fromCell, toCell };

    return move.GetType() == MoveType::Side && IsPathEmpty(fromCell, toCell);
}

auto KnightMoveValidator::IsMoveValid(const BoardCell& fromCell,
    const BoardCell& toCell) -> bool
{
    const auto move = Move{ m_Board, fromCell, toCell };
    const auto& [moveRank, moveFile, moveType, isAttack]
        = move.AsPack();

    return (moveRank == 1 && moveFile == 2) || (moveRank == 2 && moveFile == 1);
}

auto BishipMoveValidator::IsMoveValid(const BoardCell& fromCell,
    const BoardCell& toCell) -> bool
{
    const auto move = Move{ m_Board, fromCell, toCell };

    return move.GetType() == MoveType::Diagonal && IsPathEmpty(fromCell, toCell);
}
