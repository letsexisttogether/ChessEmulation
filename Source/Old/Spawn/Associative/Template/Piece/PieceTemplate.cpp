#include "PieceTemplate.hpp"


PieceTemplate::PieceTemplate(const PieceExamples& examples, TextureSpawner* spawner)
    : m_TextureSpawner{ spawner }
{
    for (const Piece& piece : examples)
    {
        m_Container[piece.GetType()] = piece;
    }
}

PieceTemplate::PieceTemplate(PieceExamples&& examples, TextureSpawner* spawner)
    : m_TextureSpawner{ spawner }
{
    for (const Piece& piece : examples)
    {
        m_Container[piece.GetType()] = std::move(piece);
    }
}

Piece* PieceTemplate::GetInstance(const PieceType& trait) 
    noexcept(false) 
{
    Piece* piece = Super::GetInstance(trait);

    piece->setTexture(*m_TextureSpawner->GetInstance(trait));

    return piece;
}
