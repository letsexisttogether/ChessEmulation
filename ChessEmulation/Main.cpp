#include <iostream>
#include <thread>
#include <chrono>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Logic/PieceElements/Piece/Piece.hpp"
#include "Logic/Enums/Side.hpp" 
#include "Logic/Control/Controllers/MouseController/MouseController.hpp"

int main()
{
    sf::RenderWindow window{ sf::VideoMode{ 1440, 1080 }, "SFML application", sf::Style::Close };
    window.setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("D:/Important/Programming/Solo/Projects/ChessEmulation/Resources/queen.png"))
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

    return 0;
}