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
    const auto loadTexture = [](sf::Texture& texture, const std::string& path) 
    {
        if (texture.loadFromFile(path))
        {
            std::cout << "The path is incorrect" << std::endl;
        }
    };

    sf::Texture whiteCellTexture{};
    loadTexture(whiteCellTexture, "D:/Important/Programming/Solo/Projects/ChessEmulation/Resourses/queen.png");


    std::shared_ptr<Piece> piece{ std::make_shared<Piece>(whiteCellTexture, Side::WHITE) };

    Board::CellSet set{};

    set.insert(BoardCell{ BoardCell::Index { 1, 'a' }, whiteCellTexture, piece});
    set.insert(BoardCell{ BoardCell::Index { 2, 'b' }, whiteCellTexture, nullptr });
    set.insert(BoardCell{ BoardCell::Index { 3, 'c' }, whiteCellTexture, nullptr });

    Board board{ std::move(set) };

    try
    {
        auto& cell = board[BoardCell::Index{ 2, 'b' }];

        const auto& currenPiece = cell.GetPiece();

        std::cout << static_cast<std::uint16_t>(currenPiece->GetSide()) << '\n';

        const auto& index = cell.GetIndex();
        std::cout << "Column: " << static_cast<std::uint16_t>(index.first) 
            << " Row: " << index.second << std::endl;
    }
    catch(const std::exception& exp)
    {
        std::cerr << exp.what() << '\n';
    }
    

    return 0;
}