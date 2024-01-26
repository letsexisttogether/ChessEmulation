#include "BasicMove.hpp"

#include <iostream>
#include <sys/stat.h>

#include "Logic/Board/Board.hpp"
#include "Logic/Board/WalkThrougher/WalkThrougher.hpp"

BasicMove::BasicMove(const DefaultMove& defaultMove)
    : m_DefaultMove{ defaultMove }
{}

bool BasicMove::TryAct(Board& board, BoardCell& initial,
    BoardCell& final, const bool shouldCheckKing)
{
    const PieceSide initialSide = initial.GetPiece().GetSide();

    DoMove(board, initial, final);
    
    bool success = true;

    if (false)
    {
        success = board.IsKingSafe(initialSide);
    }

    UndoMove(board, initial, final);

    return success;
}


bool BasicMove::IsUnderDistance(const BoardCell& initial, 
    const BoardCell& final) const noexcept(false)
{
    const DefaultMove possibleMove = final - initial;

    return m_DefaultMove.IsUnderDistance(possibleMove); 
}

bool BasicMove::IsAnyObstacles(const Board& board, const BoardCell& initial, 
        const BoardCell& final) const noexcept
{
    const DefaultMove possibleMove = final - initial;

    BoardCellIndex additionIndex{ 0, 0 }; 

    if (DefaultMove::Rank rank = possibleMove.GetRank();
        rank > 0)
    {
        additionIndex.SetRank(1);
    }
    else if (rank < 0)
    {
        additionIndex.SetRank(-1);
    }
    if (DefaultMove::File file = possibleMove.GetFile();
        file > 0)
    {
        additionIndex.SetFile(1);
    }
    else if (file < 0)
    {
        additionIndex.SetFile(-1);
    }


    WalkThrougher walker{ initial.GetIndex(), 
        final.GetIndex(), { 8, 8 } };

    for (BoardCellIndex index = walker.GetNext(); !walker.IsEndReached();
        index = walker.GetNext())
    {
        if (!walker.IsInBoundries())
        {
            return true;
        }

        const BoardCell& cell  = board[index];
        if (!cell.IsFree())
        {
            return true;
        }
    }

    return false;
}
