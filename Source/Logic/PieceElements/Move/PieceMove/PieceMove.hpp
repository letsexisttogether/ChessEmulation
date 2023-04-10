#pragma once

#include <utility>

#include "Logic/PieceElements/Move/Enums/MovePossibility.hpp"
#include "Logic/PieceElements/Move/MoveCheckers/MoveChecker.hpp"


class PieceMove
{
public:
	PieceMove() = delete;
	PieceMove(const PieceMove&) = delete;
	PieceMove(PieceMove&&) = delete;

	PieceMove(const MovePossibility movePossibility, const std::pair<uint8_t, uint8_t> distance);

	~PieceMove() = default;

	PieceMove& operator = (const PieceMove&) = delete;
	PieceMove& operator = (PieceMove&&) = delete;

private:
	MovePossibility m_MovePossibility;
	std::pair<uint8_t, uint8_t> m_Distance; 
};