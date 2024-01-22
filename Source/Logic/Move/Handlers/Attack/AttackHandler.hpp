#pragma once

#include "Logic/Move/Handlers/MoveHandler.hpp"

class AttackHandler : public MoveHandler
{
public:
    AttackHandler() = default;
    AttackHandler(const AttackHandler&) = default;
    AttackHandler(AttackHandler&&) = default;

    ~AttackHandler() = default;

    void Handle(Board& board, GameObserver& gameObsever)
        const noexcept(false);

    AttackHandler& operator = (const AttackHandler&) = default;
    AttackHandler& operator = (AttackHandler&&) = default;
};
