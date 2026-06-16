#pragma once

#include <fstream>
#include <sstream>

#include "Logic/Board/Board.hpp"

class BoardFileReader
{
public:
    BoardFileReader() = delete;
    BoardFileReader(const BoardFileReader&) = delete;
    BoardFileReader(BoardFileReader&&) = delete;

    BoardFileReader(const std::string& fileName, 
        const Piece::InMovesContainer& moves, 
        Board::PositionSpawner* const positionSpawner);

    ~BoardFileReader() = default;

    Board GetBoard() noexcept(false);

    BoardFileReader& operator = (const BoardFileReader&) = delete;
    BoardFileReader& operator = (BoardFileReader&&) = delete;

private:
    void LoadTexture(const std::string& filePath) 
        noexcept(false);
    void CreatePiece(std::istringstream& pieceArguments) 
        noexcept(false);
    void CreateCell(Board& board, std::istringstream& cellAruments) 
        noexcept(false);
    void SetBoardTexture(Board& board, std::istringstream& boardArguments)
        noexcept(false);

    void CheckSignature() noexcept(false);

    void CleanUp() noexcept;

private:
    std::ifstream m_FileStream;

    Piece::InMovesContainer m_Moves;
    Board::PositionSpawner* m_PositionSpawner;

    std::vector<sf::Texture*> m_Textures{};
    std::vector<Piece*> m_Pieces{};
};
