#include <iostream>
#include <thread>
#include <chrono>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Logic/PieceElements/Piece/Piece.hpp"
#include "Logic/Controllers/MouseController/MouseController.hpp"
#include "Logic/BoardElements/BoardCell/BoardCell.hpp"

void MainCopy()
{
sf::RenderWindow window{ sf::VideoMode{ 1440, 1080 }, "SFML application", sf::Style::Close };
    window.setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("D:/Important/Programming/Solo/Projects/ChessEmulation/Resourses/queen.png"))
    {
        std::cout << "The path is incorrect\n";
    }

    std::shared_ptr<Piece> blackQueen{ new Piece{ texture, Side::BLACK } };
    std::shared_ptr<Piece> whiteQueen{ new Piece{ texture, Side::WHITE } };
    whiteQueen->SetScreenPosition(sf::Vector2f{ 150.f, 300.f });


    std::vector<std::shared_ptr<Piece>> pieces{ blackQueen, whiteQueen };

    std::unique_ptr<Controller> controller{ new MouseController{ pieces, window } };

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            controller->CheckControl(event);
        }

        controller->Control();

        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

        window.clear();
        window.draw(*blackQueen);
        window.draw(*whiteQueen);
        window.display();

        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

        float fps = (float)1e9 / (float)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << fps << '\n';
    }
}

void Test(const BoardCell& initial, const BoardCell& final, const DefaultMove expectedResult)
{
    const DefaultMove move = initial - final;

    const auto direction = move.GetMovePossibility();
    const auto distance = move.GetDistance();

    const bool isEqual = (direction == expectedResult.GetMovePossibility() 
        && distance == expectedResult.GetDistance());

    if (isEqual)
    {
        std::cout << "Success" << std::endl;
    }
    else 
    {
        std::cout << "Failure";
        std::cout << "\nDirection: " << static_cast<uint16_t>(direction);
        std::cout << "\nDistance: " << static_cast<std::uint16_t>(distance.first) 
            << ' ' << static_cast<std::uint16_t>(distance.second) << std::endl; 
    }
}

int main()
{
    const auto loadTexture = [](sf::Texture& texture, const std::string& path) 
    {
        if (texture.loadFromFile(path))
        {
            std::cout << "The path is incorrect" << std::endl;
        }
    };

    sf::Texture whiteCellTexture{};
    loadTexture(whiteCellTexture, "D:/Important/Programming/Solo/Projects/ChessEmulation/Resourses/white_cell.png");

    sf::Texture blackCellTexture{};
    loadTexture(blackCellTexture, "D:/Important/Programming/Solo/Projects/ChessEmulation/Resourses/black_cell.png");

    const BoardCell whiteCell{ std::pair<uint8_t, char>{ 2u, 'c' }, whiteCellTexture, nullptr };
    
    const auto& index = whiteCell.GetIndex();
    
    const BoardCell blackCell{ std::pair<uint8_t, char>{ 5u, 'b' }, blackCellTexture, nullptr };
    const DefaultMove expected{ MoveDirection::UP_LEFT, std::pair<uint8_t, uint8_t>{ 3u, 1u } };

    Test(whiteCell, blackCell, expected);

    return 0;
}