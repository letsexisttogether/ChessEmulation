#include "Logic/Move/Handlers/MoveHandler.hpp"

class TransferHandler : public MoveHandler
{
public:
    TransferHandler() = default;
    TransferHandler(const TransferHandler&) = default;
    TransferHandler(TransferHandler&&) = default;

    ~TransferHandler() = default;

    void Handle(Board& board, const GameObserver& gameObsever)
        const noexcept(false) override;

    TransferHandler& operator = (const TransferHandler&) = default;
    TransferHandler& operator = (TransferHandler&&) = default;
};
