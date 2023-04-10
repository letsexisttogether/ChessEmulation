#include "DefaultMove.hpp"

DefaultMove::DefaultMove(const MovePossibility movePossibility, const std::pair<uint8_t, uint8_t>& distance,)
	: m_MovePossibility{ movePossibility }, m_Distance{ distance }
{}
