#include <iostream>
#include <thread>
#include <chrono>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Logic/PieceElements/Piece/Piece.hpp"
#include "Logic/Controllers/MouseController/MouseController.hpp"
#include "Logic/BoardElements/Board/Board.hpp"

int main()
{
    {
        const auto loadTexture = [](sf::Texture& texture, const std::string& path) 
        {
            if (!texture.loadFromFile(path))
            {
                std::cout << "The path is incorrect" << std::endl;
            }
        };

        sf::Texture whiteCellTexture{};
        loadTexture(whiteCellTexture, "D:/Important/Programming/Solo/Projects/ChessEmulation/Resourses/queen.png");

        BoardCell cell{ CellIndex{ 1, 'a' }, whiteCellTexture, std::unique_ptr<Piece>{ new Piece{ whiteCellTexture, Side::WHITE } } };

        std::cout << "Pre end\n";
    }

    std::cout << "End" << std::endl; 
    return 0;
}