#include "Player.hpp"

#include "Logic/Match/Match.hpp"

Player::Player(Match& match, const PieceSide side)
    : m_Match{ match }, m_Side{ side }
{}

BasicMove* Player::GetMove() noexcept(false)
{
    GameObserver& gameObsever = m_Match.GetGameObserver();

    if (BoardCell* initial = gameObsever.GetInitial();
        initial && initial->GetPiece().GetSide() != m_Side.GetSide())
    {
        gameObsever.ClearInitial();

        return nullptr;
    }

    if (!gameObsever.IsMoveBeingMade())
    {
        return nullptr;
    }

    GameObserver& constGameObserver = m_Match.GetGameObserver();

    Board& board = m_Match.GetBoard();
    BoardCell& initial = *constGameObserver.GetInitial();
    BoardCell& final = *constGameObserver.GetFinal();
    
    BasicMove* move = initial.TryMove(board, final);

    if (!move)
    {
        gameObsever.ClearCells();
    }

    return move;
}
