#include "BasicMove.hpp"

#include <exception>
#include <iostream>

#include "Logic/Board/Board.hpp"
#include "Logic/Move/Moves/MoveEffect/MoveEffect.hpp"

BasicMove::BasicMove(const DefaultMove& defaultMove)
	:  m_DefaultMove{ defaultMove }
{}

MoveEffect BasicMove::Try(const Board& board, const BoardCell& initial,
    const BoardCell& final) const noexcept(false)
{

    if (IsBasicAdhered(initial, final) && IsUnderDistance(initial, final) 
        && !IsAnyObstacles(board, initial, final))
    {
        return DefinePossibleMoveEffect(initial, final);
    }

    return MoveEffect::NONE;
}

BasicMove* BasicMove::Clone() const noexcept
{
    return new BasicMove{ *this };
}

bool BasicMove::IsBasicAdhered(const BoardCell& initial,
    const BoardCell& final) const noexcept(false)
{
    return !IsSameSide(initial, final);
}

bool BasicMove::IsUnderDistance(const BoardCell& initial, 
    const BoardCell& final) const noexcept(false)
{
    const DefaultMove possibleMove = initial - final;

    return m_DefaultMove.IsUnderDistance(possibleMove); 
}

bool BasicMove::IsAnyObstacles(const Board& board,
    const BoardCell& initial, const BoardCell& final) 
    const noexcept(false)
{
    const DefaultMove possibleMove = initial - final;

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
            std::cerr << '\n' << exp.what() << std::endl;
        }
    }

    return false;
}

MoveEffect BasicMove::DefinePossibleMoveEffect(const BoardCell& initial,
    const BoardCell& final) const noexcept(false)
{
    return ((final.IsFree()) ? 
        (MoveEffect::TRANSFER) : (MoveEffect::ATTACK));
}

bool BasicMove::IsSameSide(const BoardCell& initial,
    const BoardCell& final) const noexcept(false)
{
    if (final.IsFree())
    {
        return false;
    }

    const Piece& initialPiece = initial.GetPiece();
    const Piece& finalPiece = final.GetPiece();

    return initialPiece.GetSide() == finalPiece.GetSide();
}

