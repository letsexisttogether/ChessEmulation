#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "Application/Application.hpp"
#include "Graphic/Sprite/Sprite.hpp"

class Controller
{ 
public:
    Controller() = default; 

    virtual ~Controller() = default;

    virtual void Control() noexcept(false) = 0;
};


/**
* @brief Representitive of controlling the game with mouse
*/
class MouseController final : public Controller, public Sprite

{
public:
    MouseController() = delete;
    MouseController(const MouseController&) = delete;
    MouseController(MouseController&&) = delete;

    MouseController(const TexturePointer texture) noexcept(false);

    ~MouseController() = default;

    void Control() noexcept(false) override;

    bool IsIntersected(const Intersectable& intersectabla)
        const noexcept override;

    MouseController& operator = (const MouseController&) = delete;
    MouseController& operator = (MouseController&&) = delete;

private:
    Intersectable* GetPossibleIntersectable() const noexcept(false); 
    
    // Change it later
    void UpdatePosition() noexcept;

private:
    Application::Window& m_Window;
};
