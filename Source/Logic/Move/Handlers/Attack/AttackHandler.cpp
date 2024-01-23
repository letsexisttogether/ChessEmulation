#include "Logic/Move/Handlers/Attack/AttackHandler.hpp"

#include "Logic/Board/Board.hpp"

void AttackHandler::Handle(Match& match) noexcept(false)
{
    TransferHandler::Handle(match);

    m_FinalPieceStorage.reset();
}

void AttackHandler::DoMove(Board& board, BoardCell& initial, 
    BoardCell& final) noexcept(false)
{
    m_FinalPieceStorage = final.GetPiecePointer();

    TransferHandler::DoMove(board, initial, final);
}

void AttackHandler::UndoMove(Board& board, BoardCell& initial, 
    BoardCell& final) noexcept(false)
{
    TransferHandler::UndoMove(board, initial, final);

    final.SetPiece(m_FinalPieceStorage);
}
