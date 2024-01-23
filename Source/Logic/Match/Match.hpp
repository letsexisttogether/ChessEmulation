#pragma once 

#include "Logic/Board/Board.hpp"
#include "Logic/Gameplay/GameObserver/GameObserver.hpp"
#include "Logic/Gameplay/SideHolder/PieceSideHolder.hpp"

// Representation of a default match
class Match
{
public:
    using TurnCount = std::uint16_t;

public:
    Match() = delete;
    Match(const Match&) = delete;
    Match(Match&& match);

    Match(Board&& board);

    ~Match() = default;

    Board& GetBoard() noexcept;
    const Board& GetBoard() const noexcept;

    GameObserver& GetGameObserver() noexcept;
    const GameObserver& GetGameObserver() const noexcept;

    // I hope me from the future will get more experienced 
    // and now can deal with returning const or non-const 
    // if we return an easy-copyable field
    const PieceSide GetTurnSide() const noexcept;

    const TurnCount GetTurnCount() const noexcept;

private:
    Board m_Board;
    GameObserver m_GameObserver{};

    PieceSideHolder m_TurnSide{};   
    TurnCount m_TurnCount{};
    
};
