#include "Player.hpp"

Player::Player(std::string&& name, Controller* const controller, const Side side)
	: m_Name{ std::move(name) }, m_Controller{ controller }, m_Side{ side }
{}
