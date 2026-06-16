#pragma once

#include <vector>
#include <unordered_map>

#include "Application/Scenes/Scene.hpp"
#include "Logic/Match/Match.hpp"
#include "UI/Buttons/Button.hpp"

class GameScene : public Scene
{
public:
    using ButtonsContainer = std::vector<Button>;

public:
    GameScene() = delete;
    GameScene(const GameScene&) = delete;
    GameScene(GameScene&&) = delete;

    GameScene(Controller* controller, Match&& match,
        ButtonsContainer&& buttons);

    ~GameScene() = default;

    void UpdateLogic() noexcept(false) override;

    IntersectablesContainer GetIntersectables() 
        const noexcept override;

    DrawablesContainer GetDrawables() 
        const noexcept override;

    Match& GetMatch() noexcept;
    const Match& GetMatch() const noexcept;

    GameScene& operator = (const GameScene&) = delete;
    GameScene& operator = (GameScene&&) = delete;

private:
    void CheckGameState() noexcept(false);

private:
    Match m_Match;
    ButtonsContainer m_Buttons{};
};
