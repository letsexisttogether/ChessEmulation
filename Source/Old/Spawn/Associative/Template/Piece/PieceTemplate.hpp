#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <string>

#include "Logic/PieceElements/Piece/Piece.hpp"
#include "Spawn/Associative/Template/AssosiativeTemplate.hpp"

class PieceTemplate : public AssociativeTemplate<PieceType, Piece>
{
public:
    using Super = AssociativeTemplate<PieceType, Piece>;

    using PieceExamples = std::vector<Piece>;

    using TextureSpawner = AssociativeSpawner<PieceType, sf::Texture*>;

public:
    PieceTemplate() = delete;
    PieceTemplate(const PieceTemplate&) = delete;
    PieceTemplate(PieceTemplate&&) = delete;

    PieceTemplate(const PieceExamples& examples, TextureSpawner* spawner);
    PieceTemplate(PieceExamples&& examples, TextureSpawner* spawner);

    ~PieceTemplate() = default;
    
    Piece* GetInstance(const PieceType& trait) noexcept(false) override;

    PieceTemplate& operator = (const PieceTemplate&) 
        = delete;
    PieceTemplate& operator = (PieceTemplate&&) 
        = delete;

private:
    std::unique_ptr<TextureSpawner> m_TextureSpawner;
};

