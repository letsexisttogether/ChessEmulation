#pragma once

#include "Logic/BoardElements/Board/Board.hpp"
#include "Logic/PieceElements/Piece/Side.hpp"
#include "Logic/Player/Player.hpp"

class Match
{
public:
    using TurnCounter = std::uint16_t;
public:
	Match() = delete;
	Match(const Match&) = default;
	Match(Match&&) = default;
	
	Match(Board&& mainBoard, Board&& deadBoard, 
		const Player& whitePlayer, const Player& blackPlayer, const Side side);
	
	~Match() = default;
	
	void ChangeTurn() noexcept;

	const Player& GetCurrentPlayer() const noexcept;

	Match& operator = (const Match&) = delete;
	Match& operator = (Match&&) = delete;

private:
    Side m_CurrentTurn;
    TurnCounter m_TurnCounter{};

	Board m_MainBoard;
	Board m_DeadBoard;
	
	Player m_WhitePlayer;
	Player m_BlackPlayer;
	

	friend class GameProcess;
};
