#pragma once 

#include "Control/Controller.hpp"

class MouseController : public Controller
{
public:
    MouseController() = delete;
    MouseController(const MouseController&) = delete;
    MouseController(MouseController&&) = delete;

    MouseController(const TexturePointer texture);

    ~MouseController() = default;

    void Control(const sf::Event event) noexcept(false) override;

    MouseController& operator = (const MouseController&) = delete;
    MouseController& operator = (MouseController&&) = delete;

private:
    // Change it later
    void UpdatePosition() noexcept;
};
