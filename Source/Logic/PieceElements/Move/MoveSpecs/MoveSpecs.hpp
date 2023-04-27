#pragma once

#include <utility>
#include <memory>

#include "MoveDirection.hpp"

class MoveSpecs
{
public:
	using Distance = std::pair<std::uint8_t, char>;

public:
	MoveSpecs() = delete;
	MoveSpecs(const MoveSpecs&) = default;
	MoveSpecs(MoveSpecs&&) = default;

	MoveSpecs(const MoveDirection movePossibility, const Distance& distance);

	inline const MoveDirection& GetMoveDirection() const noexcept { return m_MovePossibility; }
	
	inline const Distance& GetDistance() const noexcept { return m_Distance; }
	
	~MoveSpecs() = default;

	MoveSpecs& operator = (const MoveSpecs&) = default;
	MoveSpecs& operator = (MoveSpecs&&) = default;

private:
	const MoveDirection m_MovePossibility;
	const Distance m_Distance; 
};