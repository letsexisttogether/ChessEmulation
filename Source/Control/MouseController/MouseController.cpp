#include "MouseController.hpp"

#include <SFML/Window/Mouse.hpp>

MouseController::MouseController(const MouseController& controller)
    : m_Window{ controller.m_Window } 
{}

MouseController::MouseController(const sf::Window& window)
    : m_Window{ window }
{}

const Controller::Position& MouseController::GetPosition() const noexcept
{
    const static Position mousePosition{ sf::Mouse::getPosition(m_Window) };

    return mousePosition;
}

void MouseController::SetPosition(const Controller::Position& position) noexcept
{
    sf::Mouse::setPosition(position, m_Window);
}

bool MouseController::IsActive(const sf::Event& event) const noexcept
{
    return event.type == sf::Event::MouseButtonReleased 
        && event.mouseButton.button == sf::Mouse::Left;
}
