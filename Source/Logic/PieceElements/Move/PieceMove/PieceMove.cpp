#include "PieceMove.hpp"

PieceMove::PieceMove(const MovePossibility movePossibility, const std::pair<uint8_t, uint8_t> distance,
	MoveChecker* const checker)
	: m_MovePossibility{ movePossibility }, m_Distance{ distance }, m_Checker{ checker }
{}
