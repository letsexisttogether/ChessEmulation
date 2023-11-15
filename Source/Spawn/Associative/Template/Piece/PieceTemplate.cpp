#include "PieceTemplate.hpp"


PieceTemplate::PieceTemplate(const Container& container, TextureSpawner* spawner)
    : Super{ container }, m_TextureSpawner{ spawner }
{}

PieceTemplate::PieceTemplate(Container&& container, TextureSpawner* spawner)
    : Super{ std::move(container) }, m_TextureSpawner{ spawner }
{}


Piece* PieceTemplate::GetInstance(const PieceType& trait) 
    noexcept(false) 
{
    Piece* piece = Super::GetInstance(trait);

    piece->setTexture(*m_TextureSpawner->GetInstance(trait));

    return piece;
}
