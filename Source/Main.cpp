#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "Logic/Board/Cell/BoardCell.hpp"
#include "Logic/PieceElements/Piece/Side/PieceSide.hpp"
#include "Logic/PieceElements/Piece/Type/PieceType.hpp"
#include "Spawn/Associative/Loader/TextureFile/TextureFileLoader.hpp"
#include "Spawn/Associative/Template/Piece/PieceTemplate.hpp"
#include "Spawn/Default/Board/BoardSpawner.hpp"

int main()
{
    try
    {
        BoardSpawner::ObjStorage* objStorage = new BoardSpawner::ObjStorage
        {
            BoardSpawner::ObjStorage::Container
            {
                { 
                    PieceSide::WHITE, 
                    { 
                        PieceType::ROOK,
                        PieceType::KNIGHT,
                        PieceType::BISHOP,

                        PieceType::QUEEN,
                        PieceType::KING,

                        PieceType::BISHOP,
                        PieceType::KNIGHT,
                        PieceType::ROOK,

                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,
                    }
                },
                { 
                    PieceSide::BLACK, 
                    { 
                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,
                        PieceType::PAWN,

                        PieceType::ROOK,
                        PieceType::KNIGHT,
                        PieceType::BISHOP,

                        PieceType::QUEEN,
                        PieceType::KING,

                        PieceType::BISHOP,
                        PieceType::KNIGHT,
                        PieceType::ROOK,
                    }
                }
            }
        };

        PieceTemplate::TextureSpawner* whiteTextures = 
            new TextureFileLoader<PieceType>
            {
                TextureFileLoader<PieceType>::ObjStorage
                {
                    {
                        { PieceType::ROOK, "Textures/White/Pawn.png" },
                        { PieceType::KNIGHT, "Textures/White/Knight.png" },
                        { PieceType::BISHOP, "Textures/White/Bishop.png" },
                        { PieceType::QUEEN, "Textures/White/Queen.png" },
                        { PieceType::KING, "Textures/White/King.png" },
                        { PieceType::PAWN, "Textures/White/Pawn.png" },
                    }
                }
            };

        PieceTemplate::TextureSpawner* blackTextures = 
            new TextureFileLoader<PieceType>
            {
                TextureFileLoader<PieceType>::ObjStorage
                {
                    {
                        { PieceType::ROOK, "Textures/Black/Pawn.png" },
                        { PieceType::KNIGHT, "Textures/Black/Knight.png" },
                        { PieceType::BISHOP, "Textures/Black/Bishop.png" },
                        { PieceType::QUEEN, "Textures/Black/Queen.png" },
                        { PieceType::KING, "Textures/Black/King.png" },
                        { PieceType::PAWN, "Textures/Black/Pawn.png" },
                    }
                }
            };

        BoardSpawner::PieceSpawnerStorage* pieceSpawners = 
            new BoardSpawner::PieceSpawnerStorage
        {
            BoardSpawner::PieceSpawnerStorage::InContainer
            { 
                new std::pair<PieceSide, BoardSpawner::PieceSpawner*>
                {
                    PieceSide::WHITE,
                    new PieceTemplate
                    {
                        PieceTemplate::PieceExamples
                        {
                            Piece
                            {
                                PieceSide::WHITE, PieceType::ROOK,
                                Piece::InMovesContainer
                                {
                                    // Add Rook moves
                                }
                            }
                        },
                        whiteTextures
                    }
                },
            }
        }
    }
    catch(std::exception& exp)
    {
    }

    return 0;
}