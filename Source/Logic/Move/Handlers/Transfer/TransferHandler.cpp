#include "TransferHandler.hpp"

#include <stdexcept>

#include "Logic/Board/Board.hpp"
#include "Logic/Gameplay/GameObserver/GameObserver.hpp"


void TransferHandler::Handle(Board& board, const GameObserver& gameObsever)
        const noexcept(false)
{
    if (!gameObsever.IsMoveBeingMade())
    {
        throw std::runtime_error { "Observer does not contain enough cells" };
    }

    GameObserver::CellPair cells{ gameObsever.GetCellPair() };

    BoardCell& initial = *cells.first;
    BoardCell& final = *cells.second;

    initial.TransferPiece(final);
}
