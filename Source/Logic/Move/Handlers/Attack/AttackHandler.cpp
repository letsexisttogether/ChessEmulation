#include "Logic/Move/Handlers/Attack/AttackHandler.hpp"

#include <stdexcept>

#include "Logic/Board/Board.hpp"
#include "Logic/Gameplay/GameObserver/GameObserver.hpp"

void AttackHandler::Handle(Board& board, GameObserver& gameObsever)
    const noexcept(false)
{
    if (!gameObsever.IsMoveBeingMade())
    {
        throw std::runtime_error { "Observer does not contain enough cells" };
    }

    GameObserver::CellPointerPair cells{ gameObsever.GetCellPair() };

    BoardCell& initial = *cells.first;
    BoardCell& final = *cells.second;

    final.MakeFree();

    initial.TransferPiece(final);
}
