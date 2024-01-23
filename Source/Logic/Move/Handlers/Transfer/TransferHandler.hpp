#pragma once

#include "Logic/Move/Handlers/MoveHandler.hpp"

class TransferHandler : public MoveHandler
{
public:
    TransferHandler() = default;
    TransferHandler(const TransferHandler&) = default;
    TransferHandler(TransferHandler&&) = default;

    ~TransferHandler() = default;

protected:
    void DoMove(Board& board, BoardCell& initial, 
        BoardCell& final) noexcept(false) override;

    void UndoMove(Board& board, BoardCell& initial, 
        BoardCell& final) noexcept(false) override;
};

