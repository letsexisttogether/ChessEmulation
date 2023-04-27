#include "MoveSpecs.hpp"

MoveSpecs::MoveSpecs(const MoveDirection movePossibility, const Distance& distance)
	: m_MovePossibility{ movePossibility }, m_Distance{ distance }
{}
