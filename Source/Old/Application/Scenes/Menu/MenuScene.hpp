#pragma once

#include "Application/Scenes/Scene.hpp"

class MenuScene : public Scene
{
public:
    MenuScene();

    ~MenuScene() = default;

    void UpdateLogic() noexcept(false) override;
};
