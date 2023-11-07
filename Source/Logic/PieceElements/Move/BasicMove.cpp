#include "BasicMove.hpp"

#include "Logic/Board/Board.hpp"

BasicMove::BasicMove(const Board& board, const DefaultMove& defaultMove)
	: m_Board{ board }, m_DefaultMove{ defaultMove }
{}

MoveEffect BasicMove::CheckRequirements(const BoardCell& initial, 
            const BoardCell& final) const noexcept
{
    const MoveEffect possibleEffect = DefinePossibleMoveEffect(initial, final); 

    if (possibleEffect == MoveEffect::NONE 
        || !CheckDistance(initial, final)
        || !CheckObstacles(initial, final))
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
    const DefaultMove possibleMove = final - initial;

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

    // BoardCellIndex::o
    //   
    // const MoveDirection direction = possibleMove.GetDirecton();
    // if (directon == MoveDirection::UP_RIGHT 
    //     || direction == MoveDirection::UP_LEFT)
    // {
    //     
    // }
    
    return false;
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
