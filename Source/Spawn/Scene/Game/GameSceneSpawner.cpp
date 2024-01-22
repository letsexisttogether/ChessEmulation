#include "GameSceneSpawner.hpp"

#include <iostream>
#include <memory>

#include "Control/Mouse/MouseController.hpp"
#include "Logic/Move/Moves/DefaultMove/MoveDirection.hpp"
#include "Logic/Move/Moves/MoveEffect/MoveEffect.hpp"
#include "Logic/Move/Handlers/Transfer/TransferHandler.hpp"

GameSceneSpawner::GameSceneSpawner(Controller::Window& window)
    : m_Window{ window }
{}

Scene* GameSceneSpawner::SpawnScene() noexcept(false)
{
    return new GameScene
    { 
        SpawnController(),
        SpawnMatch(),
        SpawnHandlers(),
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
                    moves.push_back
                    (
                        new BasicMove{ { MoveDirection::UP, { 8, 8 }  } }
                    );
                    break;
                case 2:
                case 7:
                    type = PieceType::KNIGHT;
                    break;
                case 3:
                case 6:
                    type = PieceType::BISHOP;
                    break;
                case 4:
                    type = PieceType::QUEEN;
                    break;
                case 5:
                    type = PieceType::KING;
                    break;
            } 

            switch (file)
            {
                case 2:
                    type = PieceType::PAWN;
                    moves.push_back
                    (
                        new BasicMove{ { MoveDirection::UP, { 1, 1 }  } }
                    );
                case 1:
                    side = PieceSide::WHITE;
                    map = &whiteTextures;
                    break;
                case 7:
                    type = PieceType::PAWN;
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

GameScene::MoveHandlers GameSceneSpawner::SpawnHandlers() 
    const noexcept
{
    GameScene::MoveHandlers handlers{};

    handlers[MoveEffect::TRANSFER] = std::make_unique<TransferHandler>();
    handlers[MoveEffect::ATTACK] = std::make_unique<TransferHandler>();

    return handlers;
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
