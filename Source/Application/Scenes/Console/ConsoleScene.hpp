#pragma once 

#include "Application/Scenes/Scene.hpp"

class ConsoleScene : public Scene
{
public:
    ConsoleScene() = delete;
    ConsoleScene(const ConsoleScene&) = delete;
    ConsoleScene(ConsoleScene&&) = delete;

    ConsoleScene(const std::string& name, std::vector<Button>&& buttons);

    ~ConsoleScene() = default;

    void UpdateLogic() noexcept(false) override;

    void UpdateGraphic() noexcept(false) override;
};
