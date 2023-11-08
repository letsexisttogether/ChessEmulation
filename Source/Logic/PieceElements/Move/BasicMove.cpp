#include "BasicMove.hpp"

#include <exception>
#include <iostream>

#include "Logic/Board/Board.hpp"
#include "Logic/PieceElements/Move/DefaultMove/MoveDirection.hpp"

BasicMove::BasicMove(const Board& board, const DefaultMove& defaultMove)
	: m_Board{ board }, m_DefaultMove{ defaultMove }
{}

MoveEffect BasicMove::CheckRequirements(const BoardCell& initial, 
            const BoardCell& final) const noexcept
{
    const MoveEffect possibleEffect = DefinePossibleMoveEffect(initial, final); 
    
    const bool isEffectNone = possibleEffect == MoveEffect::NONE;
    const bool isDistanceWrong = !CheckDistance(initial, final);
    const bool isAnyObstacles = !CheckObstacles(initial, final);

    if (isEffectNone || isDistanceWrong || isAnyObstacles)
    {
        return MoveEffect::NONE;
    }

    return possibleEffect;
}

bool BasicMove::CheckSameSide(const BoardCell& initial, 
        const BoardCell& final) const noexcept
{
    const bool isFinalFree = final.IsFree();
    const Side initPieceSide = initial.GetPiece()->GetSide();
    const Side finalPieceSide = ((isFinalFree) ? 
            (initPieceSide) : (final.GetPiece()->GetSide()));

    return !isFinalFree && initPieceSide == finalPieceSide;
}

bool BasicMove::CheckDistance(const BoardCell& initial, 
        const BoardCell& final) const noexcept
{
    const DefaultMove possibleMove = initial - final;

    const DefaultMove::Distance& objDistance = m_DefaultMove.GetDistance();
    const DefaultMove::Distance& possibleMoveDistance = possibleMove.GetDistance();

    const bool isDistanceAllowed = (objDistance.first >= possibleMoveDistance.first)
        && (objDistance.second >= possibleMoveDistance.second);
    const bool isSameDirection = 
        m_DefaultMove.GetDirection() == possibleMove.GetDirection();

    return isSameDirection && isDistanceAllowed;
}

bool BasicMove::CheckObstacles(const BoardCell& initial, 
        const BoardCell& final) const noexcept
{
    const DefaultMove possibleMove = initial - final;
    const MoveDirection direction = possibleMove.GetDirection();

    BoardCellIndex additionIndex{};

    if (direction == MoveDirection::UP_RIGHT 
            || direction == MoveDirection::UP_LEFT
            || direction == MoveDirection::UP)
    {
        additionIndex.SetRank(1); 
    }
    else if (direction == MoveDirection::DOWN_RIGHT 
            || direction == MoveDirection::DOWN_LEFT
            || direction == MoveDirection::DOWN)
    {
        additionIndex.SetRank(-1);
    }

    if (direction == MoveDirection::UP_RIGHT 
            || direction == MoveDirection::DOWN_RIGHT
            || direction == MoveDirection::RIGHT)
    {
        additionIndex.SetFile(1);
    }
    else if (direction == MoveDirection::UP_LEFT 
            || direction == MoveDirection::DOWN_LEFT 
            || direction == MoveDirection::LEFT)
    {
        additionIndex.SetFile(-1);
    }

    for (BoardCellIndex startIndex = initial.GetIndex() + additionIndex, 
            endIndex = final.GetIndex(); 
            additionIndex && startIndex != endIndex; 
            startIndex = startIndex + additionIndex)
    {
        try
        {
            const BoardCell& cell = m_Board[startIndex];

            if (!cell.IsFree())
            {
                return false;
            }
        }
        catch(std::exception& exp)
        {
            return false;
        }

    }

    return true;
}


MoveEffect BasicMove::DefinePossibleMoveEffect(const BoardCell& initial, 
        const BoardCell& final) const noexcept
{
    if (CheckSameSide(initial, final))
    {
        return MoveEffect::NONE;
    }

    return ((initial.IsFree()) ? (MoveEffect::TRANSFER) : (MoveEffect::ATTACK));
}
