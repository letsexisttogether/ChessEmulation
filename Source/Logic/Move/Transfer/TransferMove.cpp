#include "TransferMove.hpp"

#include <iostream>

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
    BoardCell& final) noexcept(false)
{
    BoardObserver& observer = board.GetObserver();

    if (!final.IsFree())
    {
        m_PieceSave = final.GetPiecePointer();

        std::cout << "Kill: " 
            << static_cast<std::int32_t>(final.GetIndex().GetRank()) << ' '
            << static_cast<std::int32_t>(final.GetIndex().GetFile()) << '\n';

        observer.DeleteCell(final.GetIndex(), 
            m_PieceSave->GetSide());
    }

    initial.TransferPiece(final);

    final.GetPiece().SetWasMoved(true);

    observer.UpdateCell(initial.GetIndex(), final);
}

void TransferMove::UndoMove(Board& board, BoardCell& initial, 
    BoardCell& final) noexcept(false)
{
    BoardObserver& observer = board.GetObserver();


    final.TransferPiece(initial);

    initial.GetPiece().SetWasMoved(false);

    observer.UpdateCell(final.GetIndex(), initial);

    if (m_PieceSave)
    {
        final.SetPiece(m_PieceSave);

        std::cout << "Restore: " 
            << static_cast<std::int32_t>(final.GetIndex().GetRank()) << ' '
            << static_cast<std::int32_t>(final.GetIndex().GetFile()) << '\n';

        observer.AddCell(final);    

        m_PieceSave.reset();
    }
}

void TransferMove::CompleteMove(Match& match) noexcept(false)
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
    BoardCell& initial, MovePairContainer& moves) 
    noexcept(false)
{
    const BoardCellIndex temp{ m_DefaultMove };
    const BoardCellIndex initialIndex{ initial.GetIndex() };
    const BoardCellIndex finalIndex{ initialIndex + temp };

    WalkThrougher walker{ initial.GetIndex(), finalIndex, 
        { 8, 8 } };

    for (BoardCellIndex index = walker.GetNext(); 
        walker.IsInBoundries();
        index = walker.GetNext())
    {
        BoardCell& cell = board[index];

        const DefaultMove defaultMove{ cell - initial };

        BasicMove* move
        {
            new TransferMove{ defaultMove } 
        };

        if (move->IsConditionSatisfied(board, initial, cell, true))
        {
            moves.push_back({ move, index });
        }
        else 
        {
            return;
        }

        if (walker.IsEndReached())
        {
            return;
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

