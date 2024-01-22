#pragma once

#include <vector>
#include <unordered_map>

#include "Application/Scenes/Scene.hpp"
#include "Logic/Match/Match.hpp"
#include "Logic/Move/Handlers/MoveHandler.hpp"
#include "UI/Buttons/Button.hpp"

class GameScene : public Scene
{
public:
    using ButtonsContainer = std::vector<Button>;
    using MoveHandlers = 
        std::unordered_map<MoveEffect, std::unique_ptr<MoveHandler>>;

public:
    GameScene() = delete;
    GameScene(const GameScene&) = delete;
    GameScene(GameScene&&) = delete;

    GameScene(Controller* controller, Match&& match,
        MoveHandlers&& handlers, 
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
    const MoveHandler& GetHandler(const MoveEffect effect) const noexcept(false);

private:
    Match m_Match;
    MoveHandlers m_Handlers;
    ButtonsContainer m_Buttons{};
};
