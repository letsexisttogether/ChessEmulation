#include "Application/Application.hpp"

int main()
{
    auto& application = Application::GetInstance();

    application.CarryTheBoatsAndTheLogs();

    return EXIT_SUCCESS;
} 
