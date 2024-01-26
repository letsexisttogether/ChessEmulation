#include "KnightMove.hpp"
#include "Logic/Board/WalkThrougher/WalkThrougher.hpp"

#include <iostream>

KnightMove::KnightMove(const DefaultMove& defaultMove)
    : TransferMove{ defaultMove }
{}

BasicMove* KnightMove::Clone() const noexcept
{
    return new KnightMove{ *this };
}

void KnightMove::SpawnLegalMoves(Board& board, BoardCell& initial, 
    MovePairContainer& moves) noexcept(false)
{
    const BoardCellIndex temp{ m_DefaultMove };
    const BoardCellIndex initialIndex = initial.GetIndex();
    const BoardCellIndex finalIndex = initialIndex + temp;

    BasicMove* move = Clone();

    WalkThrougher walk{ finalIndex, finalIndex, { 8, 8 } };

    if (!walk.IsInBoundries())
    {
        return;
    }

    BoardCell& final = board[finalIndex];

    if(move->IsConditionSatisfied(board, initial, final, false))
    {
        std::cout << "PUT A NEW MOVE" << std::endl
            << static_cast<std::int32_t>(finalIndex.GetRank()) << ' ' 
            << static_cast<std::int32_t>(finalIndex.GetFile()) << '\n';

        moves.push_back({ move, finalIndex });
    }
}

bool KnightMove::IsUnderDistance(const BoardCell& initial, 
    const BoardCell& final) const noexcept 
{
    const DefaultMove possibleMove = final - initial;

    return m_DefaultMove == possibleMove; 
}

bool KnightMove::IsAnyObstacles(const Board& board,
    const BoardCell& initial, const BoardCell& final) 
    const noexcept
{
    return false;
}

