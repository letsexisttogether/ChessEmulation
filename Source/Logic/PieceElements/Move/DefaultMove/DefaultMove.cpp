#include "DefaultMove.hpp"

DefaultMove::DefaultMove(const MoveDirection movePossibility, const Distance& distance)
	: m_MovePossibility{ movePossibility }, m_Distance{ distance }
{}
