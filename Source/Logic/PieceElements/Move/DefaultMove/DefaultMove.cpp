#include "DefaultMove.hpp"

DefaultMove::DefaultMove(const MoveDirection movePossibility, const std::pair<uint8_t, uint8_t>& distance)
	: m_MovePossibility{ movePossibility }, m_Distance{ distance }
{}
