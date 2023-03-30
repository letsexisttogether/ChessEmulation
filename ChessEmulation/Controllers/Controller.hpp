#pragma once

#include <vector>

#include "Logic/PieceElements/Piece/Piece.hpp"

class Controller 
{
public:
	Controller(const std::vector<std::shared_ptr<Piece>>& controlables, const sf::Window& window);

	virtual ~Controller() = 0;

	virtual void Control() noexcept = 0;
	virtual void CheckControl(const sf::Event& event) noexcept = 0;

protected:
	virtual bool TakeCondition(const sf::Event& event, std::shared_ptr<Piece> controlable) const noexcept = 0;
	virtual bool ReleaseContition(const sf::Event& event) const noexcept = 0;
		
	virtual void TakeControl(std::shared_ptr<Piece> controlable) noexcept = 0;
	virtual void ReleaseControl() noexcept = 0;

protected:
	const sf::Window& m_Window{};
	const std::vector<std::shared_ptr<Piece>>& m_Controlables{};
	std::shared_ptr<Piece> m_UnderCountrol{};
};