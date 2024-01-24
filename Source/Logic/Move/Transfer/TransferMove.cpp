#include "TransferMove.hpp"

#include "Logic/Match/Match.hpp"

TransferMove::TransferMove(const DefaultMove& move)
    : BasicMove{ move }
{}

bool TransferMove::IsConditionSatisfied(Match& match) 
    noexcept(false)
{
    Board& board = match.GetBoard();
    BoardCell& initial = *match.GetGameObserver().GetInitial();
    BoardCell& final = *match.GetGameObserver().GetFinal();
    
    if (!IsBasicAlright(initial, final) 
        || !IsUnderDistance(initial,final) 
        || IsAnyObstacles(board, initial, final))
    {
        return false;
    }

    DoMove(board, initial, final);
    
    // const bool success = board.IsKingSave();
    // UndoMove(board, initial, final);

    return true;
}

void TransferMove::DoMove(Board& board, BoardCell& initial, 
    BoardCell& final) noexcept
{
    if (!final.IsFree())
    {
        m_PieceSave = final.GetPiecePointer();
    }

    initial.TransferPiece(final);
}

void TransferMove::UndoMove(Board& board, BoardCell& initial, 
    BoardCell& final) noexcept
{
    final.TransferPiece(initial);

    if (m_PieceSave)
    {
        final.SetPiece(m_PieceSave);

        m_PieceSave.reset();
    }
}

void TransferMove::CompleteMove(Match& match) noexcept
{
    Board& board = match.GetBoard(); 
    BoardCell& initial = *match.GetGameObserver().GetInitial();
    BoardCell& final = *match.GetGameObserver().GetFinal();

    DoMove(board, initial, final);

    // match.GetBoard().Notify()

    // match.NotifyAboutMove();
}

BasicMove* TransferMove::Clone() const noexcept 
{
    return new TransferMove{ *this };
}


bool TransferMove::IsBasicAlright(BoardCell& initial, 
    BoardCell& final) const noexcept 
{
    if (final.IsFree())
    {
        return true;
    }

    return initial.GetPiece().GetSide() 
        != final.GetPiece().GetSide();
}
