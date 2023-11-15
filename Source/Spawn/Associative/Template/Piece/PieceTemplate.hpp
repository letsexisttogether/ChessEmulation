#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <string>

#include "Logic/PieceElements/Piece/Piece.hpp"
#include "Spawn/Associative/Template/AssosiativeTemplate.hpp"

class PieceTemplate : public AssociativeTemplate<PieceSide, Piece>
{
public:
    using Super = AssociativeTemplate<PieceSide, Piece>;
    using typename Super::Container;

    using TextureSpawner = AssociativeSpawner<PieceSide, sf::Texture*>;

public:
    PieceTemplate() = delete;
    PieceTemplate(const PieceTemplate&) = delete;
    PieceTemplate(PieceTemplate&&) = delete;

    PieceTemplate(const Container& container, TextureSpawner* spawner)
        : Super{ container }, m_TextureSpawner{ spawner }
    {}
    PieceTemplate(Container&& container, TextureSpawner* spawner)
        : Super{ std::move(container) }, m_TextureSpawner{ spawner }
    {}

    ~PieceTemplate() = default;
    
    Piece* GetInstance(const PieceSide& trait) noexcept(false) override
    {
        Piece* piece = Super::GetInstance(trait);

        piece->setTexture(*m_TextureSpawner->GetInstance(trait));

        return piece;
    }

    PieceTemplate& operator = (const PieceTemplate&) 
        = delete;
    PieceTemplate& operator = (PieceTemplate&&) 
        = delete;

private:
    std::unique_ptr<TextureSpawner> m_TextureSpawner;
};

