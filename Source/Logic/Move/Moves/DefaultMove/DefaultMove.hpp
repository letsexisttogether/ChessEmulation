#pragma once

#include <utility>

#include "MoveDirection.hpp"

class DefaultMove
{
public:
    using Distance = std::pair<std::uint8_t, std::uint8_t>;

public:
	DefaultMove() = delete;
	DefaultMove(const DefaultMove&) = default;
	DefaultMove(DefaultMove&&) = default;

	DefaultMove(const MoveDirection direction, 
            const Distance& distance);

	inline const MoveDirection& GetDirection() const noexcept 
        { return m_Direction; }
	
	inline const Distance& GetDistance() const noexcept 
        { return m_Distance; }
	
	~DefaultMove() = default;

	DefaultMove& operator = (const DefaultMove&) = default;
	DefaultMove& operator = (DefaultMove&&) = default;

private:
	MoveDirection m_Direction;
	Distance m_Distance; 
};