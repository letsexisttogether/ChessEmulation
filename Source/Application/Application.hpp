#pragma once

#include "Scenes/Scene.hpp"

class SceneSpawner;

// Manages the scenes SetUp(), CleanUp() and Switch()
class Application
{
public:
    using ScenePointer = Scene*;
public:
    Application() = delete;

    Application(SceneSpawner* const initialSceneSpawner);

    ~Application(); 

    void CarryTheBoatsAndTheLogs() noexcept;

    Scene* const GetScene() const noexcept;

private:
    ScenePointer m_Scene;
};
