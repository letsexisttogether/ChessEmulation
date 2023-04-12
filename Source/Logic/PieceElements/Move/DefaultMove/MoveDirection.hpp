#pragma once

enum class MoveDirection : std::uint8_t
{
	NONE,
	
	UP,
	DOWN,
	RIGHT,
	LEFT,

	UP_RIGHT,
	UP_LEFT,
	DOWN_RIGHT,
	DOWN_LEFT,
};