#pragma once

#include "Application/Application.hpp"

class SceneSpawner
{
public:
    SceneSpawner() = default;
    
    virtual ~SceneSpawner() = default;

    virtual Scene* SpawnScene() noexcept(false) = 0;
};

