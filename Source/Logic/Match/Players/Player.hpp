#pragma once

#include "Logic/Gameplay/SideHolder/PieceSideHolder.hpp"

class Match;
class BasicMove;

class Player
{
public:
    Player() = delete;
    Player(const Player&) = default;
    Player(Player&&) = default;
    
    Player(Match& match, const PieceSide side);

    ~Player() = default;

    virtual BasicMove* GetMove() noexcept(false);

protected:
    Match& m_Match;

    const PieceSideHolder m_Side;
};
