#include "GameMode.hpp"

GameMode::GameMode(std::vector<PieceMove>&& allMoves)
	: m_AllPossibleMoves{ std::move(allMoves) }
{}