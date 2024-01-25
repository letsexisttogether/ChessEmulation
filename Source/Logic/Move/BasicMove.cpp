#include "BasicMove.hpp"

#include <iostream>
#include <sys/stat.h>

#include "Logic/Board/Board.hpp"
#include "Logic/Board/WalkThrougher/WalkThrougher.hpp"

BasicMove::BasicMove(const DefaultMove& defaultMove)
    : m_DefaultMove{ defaultMove }
{}

bool BasicMove::IsUnderDistance(BoardCell& initial, BoardCell& final)
    const noexcept
{
    const DefaultMove possibleMove = final - initial;

    return m_DefaultMove.IsUnderDistance(possibleMove); 
}

bool BasicMove::IsAnyObstacles(Board& board, BoardCell& initial, 
        BoardCell& final) const noexcept
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


    WalkThrougher walker{ initial, final, { 8, 8 } };

    for (BoardCellIndex index = walker.GetNext(); !walker.IsEndReached();
        index = walker.GetNext())
    {
        if (!walker.IsInBoundries())
        {
            return true;
        }
        try
        {
            const BoardCell& cell  = board[index];
            if (!cell.IsFree())
            {
                return true;
            }
        }
        catch(std::exception& exp)
        {
            std::cerr << exp.what() << std::endl;

            std::cout << "Index: " << 
                static_cast<std::int32_t>(index.GetRank()) << ' '
                << static_cast<std::int32_t>(index.GetFile()) << '\n';

            return true;
        }
    }


    return false;
}
