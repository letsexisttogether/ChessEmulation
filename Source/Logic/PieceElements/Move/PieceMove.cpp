#include "PieceMove.hpp"

PieceMove::PieceMove(const MovePossibility movePosibility, const std::pair<uint8_t, uint8_t> distance)
	: m_MovePossibility{ movePosibility }, m_Distance{ distance }
{}
