#include "DefaultMove.hpp"

DefaultMove::DefaultMove(const MoveDirection direction, 
        const Distance& distance)
	: m_Direction{ direction }, m_Distance{ distance }
{}

bool DefaultMove::operator == (const DefaultMove& move) 
    const noexcept
{
    return (m_Distance.first == move.m_Distance.first
        && m_Distance.second == move.m_Distance.second
        && m_Direction == move.m_Direction);
}
