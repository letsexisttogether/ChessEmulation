#include "MoveHandler.hpp"

void MoveHandler::Handle(Match& match) noexcept(false)
{
    Board& board  = match.GetBoard();
    BoardCell& initial = *match.GetGameObserver().GetInitial();
    BoardCell& final = *match.GetGameObserver().GetFinal();

    DoMove(board, initial, final);

    if (false)
    {
        UndoMove(board, initial, final);
    }
    else
    {
        FinishMove(match);
    }
}

void MoveHandler::FinishMove(Match& match) noexcept(false)
{
    match.GetGameObserver().ClearCells();
    match.GetTurnSide().FlipSide();
}
