#include "GameMode.hpp"

#include "Logic/Board/Cell/BoardCell.hpp"
#include "Logic/Gameplay/BoardObserver/BoardObserver.hpp"
#include "Logic/Gameplay/SideHolder/PieceSideHolder.hpp"
#include "Logic/Match/Match.hpp"

bool GameMode::IsKingSave(const Match& match) const noexcept(false)
{
    const BoardObserver observer{};
    // const GameObserver observer = match.GetBoard().GetBoardObserver();

    const PieceSideHolder holder{ match.GetTurnSide() };

    const BoardCell& kingCell = observer
        .GetPiece(holder.GetSide(), PieceType::KING);

    for (const BoardCell* cell : observer.GetAlivePieces(holder.GetOppositeSide()))
    {
        const MoveEffect moveEffect = 
            cell->GetPiece().TryMove(match);

        if (moveEffect == MoveEffect::ATTACK)
        {
            return true;
        }
    } 

    return false;
}
