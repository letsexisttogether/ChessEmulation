#include "GameSceneSpawner.hpp"

#include <iostream>
#include <memory>

#include "Control/Mouse/MouseController.hpp"
#include "Logic/Move//Knight/KnightMove.hpp"
#include "Logic/Move/Pawn/Attack/PawnAttackMove.hpp"
#include "Logic/Move/Pawn/DoubleTransfer/PawnDoubleTransferMove.hpp"
#include "Logic/Move/Pawn/Transfer/PawnTransferMove.hpp"
#include "Logic/Move/Transfer/TransferMove.hpp"

GameSceneSpawner::GameSceneSpawner(Controller::Window& window)
    : m_Window{ window }, 
    m_ResourcesPath{ "D:/Important/Projects/ChessEmulation/Resourses/" }
{
    m_Moves.push_back(new TransferMove{ { 0, 7 } });
    m_Moves.push_back(new TransferMove{ { 0, -7 } });
    m_Moves.push_back(new TransferMove{ { 7, 0 } });
    m_Moves.push_back(new TransferMove{ { -7, -0 } });

    m_Moves.push_back(new TransferMove{ { 7, 7 } });
    m_Moves.push_back(new TransferMove{ { 7, -7 } });
    m_Moves.push_back(new TransferMove{ { -7, 7 } });
    m_Moves.push_back(new TransferMove{ { -7, -7 } });

    m_Moves.push_back(new KnightMove{ { 1, 2 } });
    m_Moves.push_back(new KnightMove{ { 1, -2 } });
    m_Moves.push_back(new KnightMove{ { -1, 2 } });
    m_Moves.push_back(new KnightMove{ { -1, -2 } });
    m_Moves.push_back(new KnightMove{ { 2, 1 } });
    m_Moves.push_back(new KnightMove{ { 2, -1 } });
    m_Moves.push_back(new KnightMove{ { -2, 1 } });
    m_Moves.push_back(new KnightMove{ { -2, -1 } });

    m_Moves.push_back(new PawnDoubleTransferMove{ { 0, 2 } });
    m_Moves.push_back(new PawnTransferMove{ { 0, 1 } });
    m_Moves.push_back(new PawnAttackMove{ { 1, 1 } });
    m_Moves.push_back(new PawnAttackMove{ { -1, 1 } });

    m_Moves.push_back(new PawnDoubleTransferMove{ { 0, -2 } });
    m_Moves.push_back(new PawnTransferMove{ { 0, -1 } });
    m_Moves.push_back(new PawnAttackMove{ { 1, -1 } });
    m_Moves.push_back(new PawnAttackMove{ { -1, -1 } });

    m_Moves.push_back(new TransferMove{ { 0, 1 } });
    m_Moves.push_back(new TransferMove{ { 0, -1 } });
    m_Moves.push_back(new TransferMove{ { 1, 0 } });
    m_Moves.push_back(new TransferMove{ { -1, -0 } });

    m_Moves.push_back(new TransferMove{ { 1, 1 } });
    m_Moves.push_back(new TransferMove{ { 1, -1 } });
    m_Moves.push_back(new TransferMove{ { -1, 1 } });
    m_Moves.push_back(new TransferMove{ { -1, -1 } });
}

Scene* GameSceneSpawner::SpawnScene() noexcept(false)
{
    return new GameScene
    { 
        SpawnController(),
        SpawnMatch(),
        SpawnButtons()
    };
}

Match GameSceneSpawner::SpawnMatch() const noexcept(false)
{
    return Match{ SpawnBoard() }; 
}

Board GameSceneSpawner::SpawnBoard() const noexcept(false)
{
    TexturePointer boardTexture{ new sf::Texture{} };
    boardTexture->loadFromFile(m_ResourcesPath + "Boards/Board.png");

    return { SpawnCells(), boardTexture, { 540.f, 540.f } };
}

GameScene::ButtonsContainer GameSceneSpawner::SpawnButtons() 
    const noexcept
{
    GameScene::ButtonsContainer buttons{};

    TexturePointer exitButtonTexture{ new sf::Texture{} };
    exitButtonTexture->loadFromFile(m_ResourcesPath + "Buttons/ExitButton.png");

    buttons.push_back(
        {
            exitButtonTexture,
            { 1830, 140 },
            [this] ()
            {
                m_Window.close();
            }
        });

    return buttons;
}

Board::CellSet GameSceneSpawner::SpawnCells() const noexcept
{
    Board::CellSet cells{}; 
    
    const Sprite::Size cellSize{ 112.f, 112.f };
    const Sprite::Position boardStartPosition{ 146.f, 146.f };

    TextureMap whiteTextures
    { 
        LoadPieceTextures(m_ResourcesPath + "Pieces/White/") 
    };
    TextureMap blackTextures
    { 
        LoadPieceTextures(m_ResourcesPath + "Pieces/Black/") 
    };

    for (BoardCellIndex::Rank rank = 1; rank <= 8; ++rank)
    {
        for (BoardCellIndex::File file = 8; file >= 1; --file)
        {
            const Sprite::Position cellPosition
            { 
                boardStartPosition.x + (rank - 1) * cellSize.x,
                boardStartPosition.y + (8 - file) * cellSize.y,
            };

            std::shared_ptr<Piece> piece{};

            TextureMap* map{};
            PieceSide side{};
            PieceType type{};
            Piece::InMovesContainer moves{};

            switch (rank)
            {
                case 1:
                case 8:
                    type = PieceType::ROOK;
                    for (std::size_t i = 0; i <= 3; ++i)
                    {
                        moves.push_back(m_Moves[i]);
                    }                    
                    break;
                case 2:
                case 7:
                    type = PieceType::KNIGHT;
                    for (std::size_t i = 8; i <= 15; ++i)
                    {
                        moves.push_back(m_Moves[i]);
                    }
                    break;
                case 3:
                case 6:
                    type = PieceType::BISHOP;
                    for (std::size_t i = 4; i <= 7; ++i)
                    {
                        moves.push_back(m_Moves[i]);
                    }
                    break;
                case 4:
                    type = PieceType::QUEEN;
                    for (std::size_t i = 0; i <= 7; ++i)
                    {
                        moves.push_back(m_Moves[i]);
                    }
                    break;
                case 5:
                    type = PieceType::KING;
                    for (std::size_t i = 24; i <= 30; ++i)
                    {
                        moves.push_back(m_Moves[i]);
                    }
                    break;
            } 

            switch (file)
            {
                case 2:
                    type = PieceType::PAWN;
                    moves.clear();
                    for (std::size_t i = 16; i <= 19; ++i)
                    {
                        moves.push_back(m_Moves[i]);
                    }
                case 1:
                    side = PieceSide::WHITE;
                    map = &whiteTextures;
                    break;
                case 7:
                    type = PieceType::PAWN;
                    moves.clear();
                    for (std::size_t i = 20; i <= 23; ++i)
                    {
                        moves.push_back(m_Moves[i]);
                    }
                case 8:
                    side = PieceSide::BLACK;
                    map = &blackTextures;
                    break;
            }

            if (file <= 2 || file >= 7)
            {
                piece = std::make_shared<Piece>(side, type, 
                    (*map)[type], moves);
            }

            cells.insert(BoardCell
            { 
                BoardCellIndex{ rank, file },
                cellPosition,
                cellSize,
                piece,
            });
        }
    }

    return cells;
}

GameSceneSpawner::TextureMap 
    GameSceneSpawner::LoadPieceTextures(const std::string& path)
    const noexcept
{
    std::unordered_map<PieceType, TexturePointer> textures{};

    TexturePointer rook{ new sf::Texture{} };
    rook->loadFromFile(path + "Rook.png");

    textures[PieceType::ROOK] = rook;    

    TexturePointer knight{ new sf::Texture{} };
    knight->loadFromFile(path + "Knight.png");

    textures[PieceType::KNIGHT] = knight;    

    TexturePointer bishop{ new sf::Texture{} };
    bishop->loadFromFile(path + "Bishop.png");

    textures[PieceType::BISHOP] = bishop;

    TexturePointer king{ new sf::Texture{} };
    king->loadFromFile(path + "King.png");

    textures[PieceType::KING] = king;

    TexturePointer queen{ new sf::Texture{} };
    queen->loadFromFile(path + "Queen.png");

    textures[PieceType::QUEEN] = queen;

    TexturePointer pawn{ new sf::Texture{} };
    pawn->loadFromFile(path + "Pawn.png");

    textures[PieceType::PAWN] = pawn;

    return textures;
}

Controller* GameSceneSpawner::SpawnController() const noexcept
{
    TexturePointer controllerTexture{ new sf::Texture{} };
    controllerTexture->loadFromFile(m_ResourcesPath + "Controllers/Cursor.png");

    return new MouseController{ m_Window, controllerTexture };
}
