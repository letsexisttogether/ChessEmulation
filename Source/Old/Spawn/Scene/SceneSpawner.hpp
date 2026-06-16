#pragma once

#include <memory>

#include "Application/Application.hpp"

class SceneSpawner
{
public:
    SceneSpawner() = default;
    
    virtual ~SceneSpawner() = default;

    virtual std::unique_ptr<Scene> SpawnScene() noexcept(false) = 0;
};

