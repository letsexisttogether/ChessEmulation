#pragma once

#include <utility>

#include "MovePossibility.hpp"

class PieceMove
{
public:
	PieceMove() = delete;
	PieceMove(const PieceMove&) = delete;
	PieceMove(PieceMove&&) = delete;

	PieceMove(const MovePossibility movePosibility, const std::pair<uint8_t, uint8_t> distance);

	~PieceMove() = default;

	PieceMove& operator = (const PieceMove&) = delete;
	PieceMove& operator = (PieceMove&&) = delete;

private:
	MovePossibility m_MovePossibility;
	std::pair<uint8_t, uint8_t> m_Distance;
};