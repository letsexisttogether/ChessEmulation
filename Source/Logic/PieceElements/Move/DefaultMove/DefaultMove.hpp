#pragma once

#include <utility>
#include <memory>

#include "Logic/PieceElements/Move/DefaultMove/MoveDirection.hpp"

class DefaultMove
{
public:
	using Distance = std::pair<std::uint8_t, char>;

public:
	DefaultMove() = delete;
	DefaultMove(const DefaultMove&) = default;
	DefaultMove(DefaultMove&&) = default;

	DefaultMove(const MoveDirection movePossibility, const Distance& distance);

	inline const MoveDirection& GetMoveDirection() const noexcept { return m_MovePossibility; }
	
	inline const Distance& GetDistance() const noexcept { return m_Distance; }
	
	~DefaultMove() = default;

	DefaultMove& operator = (const DefaultMove&) = default;
	DefaultMove& operator = (DefaultMove&&) = default;

private:
	const MoveDirection m_MovePossibility;
	const Distance m_Distance; 
};