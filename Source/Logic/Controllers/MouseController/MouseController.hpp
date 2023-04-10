#pragma once

#include "../Controller.hpp"

class MouseController : public Controller
{
public:
	MouseController(const std::vector<std::shared_ptr<Piece>>& controlables, const sf::Window& window);

	void Control() noexcept override;
	void CheckControl(const sf::Event& event) noexcept override;

private:
	bool TakeCondition(const sf::Event& event, std::shared_ptr<Piece> controlable) const noexcept override;
	bool ReleaseContition(const sf::Event& event) const noexcept override;

	void TakeControl(std::shared_ptr<Piece> controlable) noexcept override;
	void ReleaseControl() noexcept override;
};