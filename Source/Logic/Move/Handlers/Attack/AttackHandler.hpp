#pragma once

#include "Logic/Move/Handlers/Transfer/TransferHandler.hpp"

class AttackHandler : public TransferHandler
{
public:
    AttackHandler() = default;
    AttackHandler(const AttackHandler&) = default;
    AttackHandler(AttackHandler&&) = default;

    ~AttackHandler() = default;

    void Handle(Match& match) noexcept(false) override;

protected:
    void DoMove(Board& board, BoardCell& initial, 
        BoardCell& final) noexcept(false) override;

    void UndoMove(Board& board, BoardCell& initial, 
        BoardCell& final) noexcept(false) override;

private:
    std::shared_ptr<Piece> m_FinalPieceStorage{};
};
