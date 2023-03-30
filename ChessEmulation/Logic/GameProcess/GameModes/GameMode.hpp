#pragma once

#include <vector>

#include "Logic/PieceElements/Move/PieceMove.hpp"

class GameMode
{
public:
	GameMode() = delete;
	GameMode(const GameMode&) = default;
	GameMode(GameMode&&) = default;

	GameMode(std::vector<PieceMove>&& allMoves);

	virtual ~GameMode() = default;

	inline const std::vector<PieceMove>& GetAllMoves() const noexcept { return m_AllPossibleMoves; }

	GameMode& operator = (const GameMode&) = default;
	GameMode& operator = (GameMode&&) = default;

private:
	std::vector<PieceMove> m_AllPossibleMoves{};
};