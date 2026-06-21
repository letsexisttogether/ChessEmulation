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

        auto board = Board
        {
            Board::RawBoard
            {
                0x23456432, // Rank 1: R, N, B, Q, K, B, N, R (White)
                0x11111111, // Rank 2: Pawns (White)
                0x00000000, // Rank 3: Empty
                0x00000000, // Rank 4: Empty
                0x00000000, // Rank 5: Empty
                0x00000000, // Rank 6: Empty
                0x99999999, // Rank 7: Pawns (Black)
                0xABCDECBA  // Rank 8: R, N, B, Q, K, B, N, R (Black)
            }
        };

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

