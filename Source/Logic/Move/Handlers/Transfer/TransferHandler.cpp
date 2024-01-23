#include "TransferHandler.hpp"

void TransferHandler::DoMove(Board& board, BoardCell& initial, 
    BoardCell& final) noexcept(false)
{
    initial.TransferPiece(final);

    final.GetPiece().SetWasMoved(true);
}

void TransferHandler::UndoMove(Board& board, BoardCell& initial, 
    BoardCell& final) noexcept(false)
{
    final.TransferPiece(initial);

    initial.GetPiece().SetWasMoved(false);
}

