#pragma once

#include <memory>
#include <string>

#include "Logic/PieceElements/Piece/Side.hpp"
#include "Logic/Controllers/MouseController/MouseController.hpp"

class Player
{
public:
	Player() = delete;
	Player(const Player&) = default;
	Player(Player&&) = default;

	Player(std::string&& name, Controller * const controller, const Side side);

	~Player() = default;

	const std::string& GetName() const noexcept { return m_Name; }
	
	const Side& GetSide() const noexcept { return m_Side; }
	
	const Controller& GetController() const noexcept { return *m_Controller; }

	
	Player& operator = (const Player&) = delete;
	Player& operator = (Player&&) = delete;

private:
	std::string m_Name;
	Side m_Side;
	std::shared_ptr<Controller> m_Controller;
};