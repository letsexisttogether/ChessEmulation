#include "TransferMove.hpp"

#include "Logic/Board/WalkThrougher/WalkThrougher.hpp"
#include "Logic/Match/Match.hpp"

TransferMove::TransferMove(const DefaultMove& move)
    : BasicMove{ move }
{}

bool TransferMove::IsConditionSatisfied(Board& board, BoardCell& initial, 
    BoardCell& final, const bool shouldCheckKing)
    noexcept(false)
{
    if (!IsBasicAlright(initial, final) 
        || !IsUnderDistance(initial,final) 
        || IsAnyObstacles(board, initial, final))
    {
        return false;
    }

    return TryAct(board, initial, final, shouldCheckKing);
}

void TransferMove::DoMove(Board& board, BoardCell& initial, 
    BoardCell& final) noexcept
{
    BoardObserver& observer = board.GetObserver();

    if (!final.IsFree())
    {
        m_PieceSave = final.GetPiecePointer();

        observer.DeleteCell(final.GetIndex(), 
            m_PieceSave->GetSide());
    }

    initial.TransferPiece(final);

    final.GetPiece().SetWasMoved(true);

    observer.UpdateCell(initial.GetIndex(), final);
}

void TransferMove::UndoMove(Board& board, BoardCell& initial, 
    BoardCell& final) noexcept
{
    BoardObserver& observer = board.GetObserver();

    final.TransferPiece(initial);

    initial.GetPiece().SetWasMoved(false);

    observer.UpdateCell(final.GetIndex(), initial);

    if (m_PieceSave)
    {
        final.SetPiece(m_PieceSave);

        observer.AddCell(final);    

        m_PieceSave.reset();
    }
}

void TransferMove::CompleteMove(Match& match) noexcept
{
    Board& board = match.GetBoard(); 
    BoardCell& initial = *match.GetGameObserver().GetInitial();
    BoardCell& final = *match.GetGameObserver().GetFinal();

    if (!final.IsFree() && final.GetPiece()
        .GetType() == PieceType::KING)
    {
        return; 
    }

    DoMove(board, initial, final);

    m_PieceSave.reset();

    match.NotifyAboutMove();
}

BasicMove* TransferMove::Clone() const noexcept 
{
    return new TransferMove{ *this };
}

void TransferMove::SpawnLegalMoves(Board& board, 
    BoardCell& initial, 
    std::vector<std::unique_ptr<BasicMove>>& moves) 
    noexcept(false)
{
    const BoardCellIndex final{ m_DefaultMove };

    WalkThrougher walker{ initial.GetIndex(), final, { 8, 8 } };

    for (BoardCellIndex index = walker.GetNext(); !walker.IsEndReached();
        index = walker.GetNext())
    {
        if (!walker.IsInBoundries())
        {
            return;
        }

        BoardCell& cell  = board[index];
        if (!cell.IsFree())
        {
            return;
        }

        std::unique_ptr<BasicMove> move
        {
            new TransferMove{ cell - initial } 
        };

        if (move->IsBasicAlright(initial, cell) 
                || TryAct(board, initial, cell, true))
        {
            moves.push_back(std::move(move));
        }
    }
}

bool TransferMove::IsBasicAlright(const BoardCell& initial, 
    const BoardCell& final) const noexcept
{
    if (final.IsFree())
    {
        return true;
    }

    return initial.GetPiece().GetSide() 
        != final.GetPiece().GetSide();
}

