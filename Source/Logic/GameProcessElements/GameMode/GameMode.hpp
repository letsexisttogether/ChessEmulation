#pragma once

#include <vector>

#include "Logic/PieceElements/Move/PieceMove.hpp"
#include "Logic/BoardElements/BoardCell/BoardCell.hpp"

class GameMode
{
public:
	GameMode() = delete;
	GameMode(const GameMode&) = default;
	GameMode(GameMode&&) = default;

	GameMode(std::vector<PieceMove>&& allMoves);
	
	virtual ~GameMode() = default;

	inline const std::vector<PieceMove>& GetAllMoves() const noexcept { return m_AllPossibleMoves; }

	bool IsKingInSafe(const std::vector<BoardCell>& cells);

	std::vector<PieceMove> GetPossbileMoves(const std::shared_ptr<BoardCell>& start, const std::shared_ptr<BoardCell>& end);


	// Совершилось действите

	// std::vector<PieceMove> moves = 

	GameMode& operator = (const GameMode&) = delete;
	GameMode& operator = (GameMode&&) = delete;

private:
	std::vector<PieceMove> m_AllPossibleMoves{};
};