#include "Application.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

#include "Logic/Board.hpp"
#include "Logic/MoveValidator.hpp"
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

        while (false)
        {
            std::cout << "The application is working" << std::endl;
        }

        auto board = Board::CreateDefaultBoard();

        PrintBoard(board);

        board.Move({ 'e', 2 }, { 'e', 3 });
        board.Move({ 'd', 8 }, { 'b', 6 });

        PrintBoard(board);

        auto moveValidator = MoveValidator{ board };

        const auto isEmpty = moveValidator.IsPathEmpty({ 'b', 2 }, { 'b', 7 });
        const auto isEmpty1 = moveValidator.IsPathEmpty({ 'd', 1 }, { 'h', 5 });

        /*
        Black box:
         1. The system receives two cells: fromCell, torankDiffCell.
         2. The system outputs whether the move is possible.
        
        Detailed:
         1. The system receives two cells.
         The system ...
         2. Checks what piece is on fromCell.
         3. Fetches the rules for the piece.
         4. Checks the rules
        */
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

