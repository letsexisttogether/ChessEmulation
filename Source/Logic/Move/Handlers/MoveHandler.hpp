#pragma once 

#include "Logic/Match/Match.hpp"

class MoveHandler
{
public:
    MoveHandler() = default;

    virtual ~MoveHandler() = default;

    virtual void Handle(Match& match) noexcept(false);

protected:
    virtual void DoMove(Board& board, BoardCell& initial, 
        BoardCell& final) noexcept(false) = 0;

    virtual void UndoMove(Board& board, BoardCell& initial, 
        BoardCell& final) noexcept(false) = 0;

    virtual void FinishMove(Match& match) noexcept(false);
};

