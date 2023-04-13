#pragma once

#include <utility>
#include <memory>

#include "Logic/PieceElements/Move/DefaultMove/MoveDirection.hpp"

class DefaultMove
{
public:
	DefaultMove() = delete;
	DefaultMove(const DefaultMove&) = default;
	DefaultMove(DefaultMove&&) = default;

	DefaultMove(const MoveDirection movePossibility, const std::pair<uint8_t, uint8_t>& distance);

	inline const MoveDirection& GetMovePossibility() const noexcept { return m_MovePossibility; }
	
	inline const std::pair<uint8_t, uint8_t>& GetDistance() const noexcept { return m_Distance; }
	
	~DefaultMove() = default;

	DefaultMove& operator = (const DefaultMove&) = default;
	DefaultMove& operator = (DefaultMove&&) = default;

private:
	MoveDirection m_MovePossibility;
	std::pair<uint8_t, uint8_t> m_Distance; 
};