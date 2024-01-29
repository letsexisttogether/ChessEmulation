#include "BoardFileReader.hpp"

#include <SFML/Graphics.hpp>
#include <stdexcept>

BoardFileReader::BoardFileReader(const std::string& fileName, 
    const Piece::InMovesContainer& moves,
    Board::PositionSpawner* const positionSpawner)
    : m_FileStream{ fileName }, m_Moves{ moves },
    m_PositionSpawner{ positionSpawner }
{}

Board BoardFileReader::GetBoard() noexcept(false)
{
    Board board{ m_PositionSpawner };

    CheckSignature();
    
    for (std::string line; m_FileStream >> line; )
    {
        if (line.empty())
        {
            continue;
        }

        const std::string lineSubstr{ line.substr(3) };
        std::istringstream lineRef{ lineSubstr };

        switch (char actionIdentifier = line[0])
        {
            case 't':
                LoadTexture(lineSubstr);
                break;

            case 'p':
                CreatePiece(lineRef);
                break;

            case 'c':
                CreateCell(board, lineRef);
                break;

            case 'b':
                SetBoardTexture(board, lineRef);
                break;

            default:
                throw std::runtime_error{ "Unknown letter was found in the file" };
        }
    }


    return board;
}

void BoardFileReader::LoadTexture(const std::string& filePath) 
    noexcept(false)
{
    sf::Texture* texture = new sf::Texture{};
    texture->loadFromFile(filePath);

    m_Textures.push_back(texture);
}

void BoardFileReader::CreatePiece(std::istringstream& pieceArguments) 
    noexcept(false)
{
    std::int32_t pieceSide{};
    std::int32_t pieceType{};
    std::size_t textureIndex{}; 

    pieceArguments >> pieceSide >> pieceType >> textureIndex;

    Piece::InMovesContainer moves{};

    for (std::size_t moveIndex; !pieceArguments.eof(); )
    {
        pieceArguments >> moveIndex;

        moves.push_back(m_Moves[moveIndex]);
    }

    m_Pieces.push_back(new Piece
    {
        static_cast<PieceSide>(pieceSide),
        static_cast<PieceType>(pieceType),
        moves,
        m_Textures[textureIndex]
    });
}

void BoardFileReader::CreateCell(Board& board, std::istringstream& cellAruments) 
    noexcept(false)
{
    BoardCellIndex::Rank rank{};
    BoardCellIndex::File file{};
    std::size_t textureIndex{};

    cellAruments >> rank >> file >> textureIndex;

    BoardCell cell{ BoardCellIndex{ rank, file }, m_Textures[textureIndex] };

    if (!cellAruments.eof())
    {
        std::size_t pieceIndex;

        cellAruments >> pieceIndex;

        cell.SetPiece(m_Pieces[pieceIndex]);
    }

    board.AddCell(std::move(cell));
}

void BoardFileReader::SetBoardTexture(Board& board, 
        std::istringstream& boardArguments)
    noexcept(false)
{
    std::size_t textureIndex{};
    
    boardArguments >> textureIndex;

    board.SetTexture(m_Textures[textureIndex]);
}

void BoardFileReader::CheckSignature() noexcept(false)
{
    std::string signature{};
    m_FileStream >> signature;


    if (signature != "BRDCA")
    {
        throw std::exception{ "The file is missing the signature" };
    }
}

void BoardFileReader::CleanUp() noexcept
{
    m_FileStream.seekg(std::streamsize(0), std::ios::beg);

    m_Textures.clear();
    m_Pieces.clear();
}
