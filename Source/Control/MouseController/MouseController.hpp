#pragma once 

#include "Control/Controller.hpp"
#include "SFML/Window/Window.hpp"

class MouseController : public Controller
{
public:
    MouseController() = delete;
    MouseController(const MouseController&);
    MouseController(MouseController&&) = default;

    MouseController(const sf::Window& window);

    ~MouseController() = default;

    const Controller::Position& GetPosition() const noexcept override;
    void SetPosition(const Controller::Position& position) noexcept override;

    bool IsActive(const sf::Event& event) const noexcept override;

    MouseController& operator = (const MouseController&) = delete;
    MouseController& operator = (MouseController&&) = delete;

private:
    const sf::Window& m_Window;
};
