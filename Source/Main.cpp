#include "Application/Application.hpp"

int main()
{
    Application& application = Application::GetInstance();

    application.CarryTheBoatsAndTheLogs();

    return EXIT_SUCCESS;
} 