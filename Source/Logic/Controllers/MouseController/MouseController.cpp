#include "MouseController.hpp"

#include <algorithm>
#include <SFML/Graphics.hpp>

MouseController::MouseController(const std::vector<std::shared_ptr<Piece>>& controlables, const sf::Window& window)
	: Controller{ controlables, window }
{}

void MouseController::Control() noexcept
{
	if (!m_UnderCountrol)
	{
		return;
	}

	const sf::Vector2i mousePosition{ sf::Mouse::getPosition(m_Window) };
	const sf::Vector2i windowSize{ m_Window.getSize() };
	const sf::Vector2i pieceSize{ m_UnderCountrol->GetSize() };
	const sf::Vector2i pieceHalfSize{ m_UnderCountrol->GetSize() / 2u };

	const sf::Vector2i possiblePosition{ mousePosition.x - pieceHalfSize.x, mousePosition.y - pieceHalfSize.y };
	const sf::Vector2i properPosition{ std::min(std::max(possiblePosition.x, 0), windowSize.x - pieceSize.x),
		std::min(std::max(possiblePosition.y, 0), windowSize.y - pieceSize.x) };

	m_UnderCountrol->SetScreenPosition(static_cast<sf::Vector2f>(properPosition));
}

void MouseController::CheckControl(const sf::Event& event) noexcept
{
	for (auto& existingControlable : m_Controlables)
	{
		if (TakeCondition(event, existingControlable))
		{
			TakeControl(existingControlable);
			break;
		}
	}

	if (ReleaseContition(event))
	{
		ReleaseControl();
	}
}

bool MouseController::TakeCondition(const sf::Event& event, std::shared_ptr<Piece> controlable) const noexcept
{
	if (m_UnderCountrol)
	{
		return false;
	}

	const sf::Vector2i mousePos{ sf::Mouse::getPosition(m_Window) };
	const sf::Vector2f& piecePosition = controlable->GetScreenPosition();
	const sf::Vector2u& pieceSize = controlable->GetSize();

	bool isMouseOnPiece = (mousePos.x >= piecePosition.x && mousePos.x <= piecePosition.x + pieceSize.x
		&& mousePos.y >= piecePosition.y && mousePos.y <= piecePosition.y + pieceSize.y);
	bool isEventCorrect = (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left));

	return isMouseOnPiece && isEventCorrect;
}

bool MouseController::ReleaseContition(const sf::Event& event) const noexcept
{
	return (m_UnderCountrol &&
		(event.type == sf::Event::MouseButtonReleased
			&& !sf::Mouse::isButtonPressed(sf::Mouse::Left))
		|| (event.type == sf::Event::MouseButtonPressed
			&& sf::Mouse::isButtonPressed(sf::Mouse::Right)));
}

void MouseController::TakeControl(std::shared_ptr<Piece> controlable) noexcept
{
	m_UnderCountrol = controlable;
}

void MouseController::ReleaseControl() noexcept
{
	m_UnderCountrol.reset();
}
