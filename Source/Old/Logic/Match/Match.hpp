#pragma once 

#include "Logic/Board/Board.hpp"
#include "Logic/Gameplay/GameObserver/GameObserver.hpp"
#include "Logic/Gameplay/SideHolder/PieceSideHolder.hpp"
#include "Logic/Match/Players/AI/AI.hpp"
#include "Logic/Match/Players/Player.hpp"
#include "Logic/Piece/Side/PieceSide.hpp"
#include "Logic/Piece/Type/PieceType.hpp"

// Representation of a default match
class Match
{
public:
    using TurnCount = std::uint16_t;

private:
    using PlayerPointer = std::unique_ptr<Player>;

public:
    Match() = delete;
    Match(const Match&) = delete;
    Match(Match&& match);

    Match(Board&& board);

    ~Match() = default;

    void NotifyAboutMove() noexcept;

    Board& GetBoard() noexcept;
    const Board& GetBoard() const noexcept;

    GameObserver& GetGameObserver() noexcept;
    const GameObserver& GetGameObserver() const noexcept;

    PieceSideHolder& GetTurnSide() noexcept;
    const PieceSideHolder& GetTurnSide() const noexcept;

    const TurnCount GetTurnCount() const noexcept;

    Player& GetCurrentPlayer() noexcept;

private:
    Board m_Board;
    GameObserver m_GameObserver{};

    PieceSideHolder m_TurnSide{};   
    TurnCount m_TurnCount{};
   
    PlayerPointer m_WhitePlayer
    { 
        new Player{ *this, PieceSide::WHITE } 
    };

    PlayerPointer m_BlackPlayer
    { 
        new AI
        { 
            *this, PieceSide::BLACK,
            {
                { PieceType::KING, 120 }, 
                { PieceType::QUEEN, 80 }, 
                { PieceType::ROOK, 30 }, 
                { PieceType::BISHOP, 30 }, 
                { PieceType::KNIGHT, 50 }, 
                { PieceType::PAWN, 10 }
            }
        } 
    };
};
