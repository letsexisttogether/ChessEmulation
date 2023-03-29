#include "Controller.hpp"

Controller::Controller(const std::vector<std::shared_ptr<Piece>>& controlables, const sf::Window& window)
	: m_Controlables{ controlables }, m_Window{ window }
{}

Controller::~Controller()
{}