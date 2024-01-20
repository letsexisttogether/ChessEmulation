#include "BasicMove.hpp"

#include <exception>
#include <iostream>

#include "Logic/Match/Match.hpp"
#include "Logic/Move/Moves/MoveEffect/MoveEffect.hpp"

BasicMove::BasicMove(const DefaultMove& defaultMove)
	:  m_DefaultMove{ defaultMove }
{}

MoveEffect BasicMove::Try(const Match& match) 
    const noexcept
{
    const Board& board = match.GetBoard();

    const GameObserver::CellReferencePair cellPair
    { 
        match.GetGameObserver().GetCellPair() 
    };
    const BoardCell& initial = cellPair.first;
    const BoardCell& final = cellPair.second;
    
    if (IsUnderDistance(initial, final) 
        && !IsAnyObstacles(board, initial, final))
    {
        return DefinePossibleMoveEffect(match);
    }

    return MoveEffect::NONE;
}

BasicMove* BasicMove::Clone() const noexcept
{
    return new BasicMove{ *this };
}

bool BasicMove::IsUnderDistance(const BoardCell& initial, 
    const BoardCell& final) const noexcept
{
    const DefaultMove possibleMove = initial - final;

    const DefaultMove::Distance& objDistance = m_DefaultMove.GetDistance();
    const DefaultMove::Distance& possibleMoveDistance = possibleMove.GetDistance();

    const bool isDistanceAllowed = (objDistance.first >= possibleMoveDistance.first)
        && (objDistance.second >= possibleMoveDistance.second);

    const bool isSameDirection = 
        (m_DefaultMove.GetDirection() == possibleMove.GetDirection());

    return isSameDirection && isDistanceAllowed;
}

bool BasicMove::IsAnyObstacles(const Board& board,
    const BoardCell& initial, const BoardCell& final) 
    const noexcept
{
    const DefaultMove possibleMove = initial - final;
    const MoveDirection direction = possibleMove.GetDirection();

    BoardCellIndex additionIndex{ 1, 1 };

    if (direction == MoveDirection::DOWN_RIGHT 
        || direction == MoveDirection::DOWN_LEFT
        || direction == MoveDirection::DOWN)
    {
        additionIndex.SetRank(-1);
    }

    if (direction == MoveDirection::UP_LEFT 
        || direction == MoveDirection::DOWN_LEFT 
        || direction == MoveDirection::LEFT)
    {
        additionIndex.SetFile(-1);
    }

    for (BoardCellIndex index = initial.GetIndex() + additionIndex, 
        endIndex = final.GetIndex(); 
        additionIndex && index != endIndex; 
        index = index + additionIndex)
    {
        try
        {
            const BoardCell& cell = board[index];

            if (!cell.IsFree())
            {
                return false;
            }
        }
        catch(std::exception& exp)
        {
            std::cerr << '\n' << exp.what() << std::endl;
        }
    }

    return true;
}

MoveEffect BasicMove::DefinePossibleMoveEffect(const Match& match) 
    const noexcept(false)
{
    const GameObserver::CellReferencePair cellPair
    { 
        match.GetGameObserver().GetCellPair() 
    };

    const BoardCell& initial = cellPair.first;
    const BoardCell& final = cellPair.second;

    if (IsSameSide(initial, final))
    {
        return MoveEffect::NONE;
    }

    return ((final.IsFree()) ? (MoveEffect::TRANSFER) : (MoveEffect::ATTACK));
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
