#include "Application.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "Logic/Board.hpp"
#include "Graphics/Auxilary.hpp"

using namespace std::chrono_literals;

Application& Application::GetInstance() noexcept
{
    static Application instance{};

    return instance;
}

auto Application::CarryTheBoatsAndTheLogs() noexcept -> std::int32_t
{
    try
    {
        // Initialize

        while(false)
        {
            std::cout << "The application is working" << std::endl;
        }

        auto board = Board::CreateDefaultBoard();

        PrintBoard(board);

        board.Move({ 'e', 2 }, { 'e', 3 });
        board.Move({ 'd', 8 }, { 'b', 6 });

        PrintBoard(board);
    }
    catch(std::exception& exp)
    {
        std::cerr << exp.what() << std::endl;

        return EXIT_FAILURE;
    }

    std::this_thread::sleep_for(1s);

    std::cout << "Have a nice day" << std::endl;

    return EXIT_SUCCESS;
}

