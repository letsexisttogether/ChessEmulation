#pragma once

#include <memory>
#include <unordered_map>

#include "Graphic/TextureLoader/TextureLoader.hpp"
#include "Logic/PieceElements/Piece/Piece.hpp"

class PieceCreator
{
public:
    using StorageIndex = PieceType;
    using PieceStorage = std::unordered_map<StorageIndex, Piece>;

    using TextureLoader = TextureLoader<StorageIndex, std::string>;

public:
    PieceCreator() = delete;
    PieceCreator(const PieceCreator&) = delete;
    PieceCreator(PieceCreator&&) = delete;

    PieceCreator(TextureLoader* textureLoader, PieceStorage&& piecesExamples);

    ~PieceCreator() = default;

    Piece* CreatePiece(const StorageIndex index) const noexcept(false); 

private:
    const PieceStorage m_PiecesExamples;
    std::unique_ptr<TextureLoader> m_TextureLoader;
};
