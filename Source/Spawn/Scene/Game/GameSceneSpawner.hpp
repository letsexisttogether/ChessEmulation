#pragma once

#include <unordered_map>
#include <vector>

#include "Application/Scenes/Game/GameScene.hpp"
#include "Control/Controller.hpp"
#include "Spawn/Scene/SceneSpawner.hpp"
#include "UI/Buttons/Button.hpp"

// Hardcoding is bad, I will get away from it later
class GameSceneSpawner : public SceneSpawner
{
public:
    using TexturePointer = Sprite::TexturePointer;
    using TextureMap = std::unordered_map<PieceType, Sprite::TexturePointer>;

public:
    GameSceneSpawner() = delete;

    GameSceneSpawner(Controller::Window& window);

    Scene* SpawnScene() noexcept(false) override;

private:
    Match SpawnMatch() const noexcept(false);

    Board SpawnBoard() const noexcept(false);
    Board::CellSet SpawnCells() const noexcept;
    TextureMap LoadPieceTextures(const std::string& path) const noexcept;

    GameScene::MoveHandlers SpawnHandlers() const noexcept;
    GameScene::ButtonsContainer SpawnButtons() const noexcept;
    Controller* SpawnController() const noexcept;

private:
    const std::string m_ResourcesPath
    {
       "D:/Important/Projects/ChessEmulation/Resourses/" 
    };

    sf::RenderWindow& m_Window;
};
