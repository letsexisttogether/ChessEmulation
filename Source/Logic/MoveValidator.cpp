#include "MoveValidator.hpp"

#include <cstdlib>
#include <stdexcept>

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

auto MoveValidator::IsMoveValid(const BoardCell fromCell,
    const BoardCell toCell) -> bool
{
    // Assuming fromCell contains Pawn

    /*
    auto movesGenerator = PawnMoveGenerator(m_Board);
    auto validCells = movesGenerator.GenerateMoves(fromCell);
    */

    return true;
}

PawnMoveValidator::PawnMoveValidator(const Board& board) noexcept
    : MoveValidator{ board } {}

auto PawnMoveValidator::IsMoveValid(const BoardCell fromCell,
    const BoardCell toCell) -> bool
{
    const auto pawn = m_Board.GetCellContent(fromCell);
    const auto& [pawnType, pawnColor] = pawn.AsPack();

    const auto enemy = m_Board.GetCellContent(toCell);
    const auto& [enemyType, enemyColor] = enemy.AsPack();

    const auto move = Move{ m_Board, fromCell, toCell };
    const auto& [moveRank, moveFile, moveType, isMoveAttacking]
        = move.AsPack();

    if (!move)
    {
        throw std::runtime_error{ "[PawnMoveValidator] Move to the same cell" };
    }

    const auto moveRankAbs = std::abs(moveRank);
    const auto moveFileAbs = std::abs(moveFile);

    const auto isAtStart = (pawnColor && fromCell.File == m_WhiteStartFile)
        || (!pawnColor && fromCell.File == m_BlackStartFile);

    if (isAtStart && moveRankAbs > 2) 
    {
        return false;
    }

    // Invalid conditions:
    // 1. Not at starting point and abs(file) > 1
    // 2. At starting point and rank != 0
    // 3. At starting point by there's a piece on the way;
}
