#include "Application.hpp"
#include "Spawn/Scene/SceneSpawner.hpp"

#include <iostream>

Application::Application(SceneSpawner* const initialSceneSpawner)
{
    initialSceneSpawner->SetApplication(this);

    m_Scene = initialSceneSpawner->SpawnScene();
}

Application::~Application()
{
    delete m_Scene;
}

void Application::CarryTheBoatsAndTheLogs() noexcept
{
    while(m_Scene->IsWorking())
    {
        try
        {
           m_Scene->UpdateLogic(); 

           std::int32_t buttonIndex{};

            std::cout << "Enter a button buttonIndex: ";

            std::cin >> buttonIndex;

            std::cout << std::endl;

            m_Scene->ActivateButton(buttonIndex);
        }
        catch (std::exception& exp)
        {
            std::cerr << exp.what() << std::endl;
        }
    }

    std::cout << "Have a nice day" << std::endl;
}

Scene* const Application::GetScene() const noexcept
{
    return m_Scene;
}
