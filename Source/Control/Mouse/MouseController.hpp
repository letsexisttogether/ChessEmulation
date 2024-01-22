#pragma once 

#include "Control/Controller.hpp"

class MouseController : public Controller
{
public:
    MouseController() = delete;
    MouseController(const MouseController&) = delete;
    MouseController(MouseController&&) = delete;

    MouseController(Window& window, const TexturePointer texture);

    ~MouseController() = default;

    void Control() noexcept(false) override;

    bool IsIntersected(const Intersectable& intersectabla)
        const noexcept override;

    MouseController& operator = (const MouseController&) = delete;
    MouseController& operator = (MouseController&&) = delete;

private:
    // Change it later
    void UpdatePosition() noexcept;
};
