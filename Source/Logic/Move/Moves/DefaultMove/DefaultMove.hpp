#pragma once

#include <utility>

#include "MoveDirection.hpp"

class DefaultMove
{
public:
    using File = std::int8_t;
    using Rank = std::int8_t;

    using Distance = std::pair<Rank, File>;

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

    bool operator == (const DefaultMove& move) const noexcept;

private:
	MoveDirection m_Direction;
	Distance m_Distance; 
};