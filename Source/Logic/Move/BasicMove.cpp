#include "BasicMove.hpp"

#include <iostream>

#include "Logic/Board/Board.hpp"

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

    for (BoardCellIndex index{ initial.GetIndex() + additionIndex }, 
        endIndex = final.GetIndex(); 
        additionIndex && index != endIndex; 
        index += additionIndex)
    {
        try
        {
            const BoardCell& cell = board[index];

            if (!cell.IsFree())
            {
                return true;
            }
        }
        catch(std::exception& exp)
        {
            return true;
        }
    }

    return false;
}
