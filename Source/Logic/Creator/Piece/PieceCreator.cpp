#include "PieceCreator.hpp"

#include <algorithm>
#include <stdexcept>

PieceCreator::PieceCreator(TextureLoader* textureLoader, 
        PieceStorage&& piecesExamples)
    : m_TextureLoader{ textureLoader}, 
    m_PiecesExamples{ std::move(piecesExamples) }
{}

Piece* PieceCreator::CreatePiece(const StorageIndex index)
    const noexcept(false)

{
    const auto& iter = m_PiecesExamples.find(index);

    if (iter == m_PiecesExamples.end())
    {   
        throw std::exception
        {
            "There's not such a piece template in the current storage"
        };
    }
    
    Piece* piece = new Piece{ iter->second };

    if (!piece->getTexture())
    {
        piece->setTexture(*m_TextureLoader->LoadTexture(index));
    }

    return piece;
}
