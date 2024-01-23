#include "Match.hpp"

#include <utility>

Match::Match(Match&& match)
    : m_Board{ std::move(match.m_Board) }, 
    m_GameObserver{ match.m_GameObserver },
    m_TurnSide{ match.m_TurnSide },
    m_TurnCount{ match.m_TurnCount }
{}

Match::Match(Board&& board)
    : m_Board{ std::move(board) }
{}
 
Board& Match::GetBoard() noexcept
{
    return m_Board;
}

const Board& Match::GetBoard() const noexcept
{
    return m_Board;
}

GameObserver& Match::GetGameObserver() noexcept
{
    return m_GameObserver;
}

const GameObserver& Match::GetGameObserver() const noexcept
{
    return m_GameObserver;
}

PieceSideHolder& Match::GetTurnSide() noexcept
{
    return m_TurnSide;
}

const PieceSideHolder& Match::GetTurnSide() const noexcept
{
    return m_TurnSide;
}


const Match::TurnCount Match::GetTurnCount() 
    const noexcept
{
    return m_TurnCount;
}
