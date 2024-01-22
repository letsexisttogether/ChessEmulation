#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <vector>

#include "Logic/Move/Moves/BasicMove.hpp"
#include "Graphic/Sprite/Sprite.hpp"
#include "Type/PieceType.hpp"
#include "Side/PieceSide.hpp"

class Piece : public Sprite 
{
public:
    using MovePointer = std::unique_ptr<BasicMove>;

    using InMovesContainer = std::vector<BasicMove*>;
    using MovesContainer = std::vector<MovePointer>;

public:
	Piece() = default;
	Piece(const Piece& piece);
	Piece(Piece&& piece);

    Piece(const PieceSide side, const PieceType type,
        const InMovesContainer& moves);

    Piece(const PieceSide side, const PieceType type, 
        const TexturePointer texture,
        const InMovesContainer& moves = {},
        const Position position = Position{});

	virtual ~Piece() = default;

    MoveEffect TryMove(const Match& match) const noexcept;

	inline const PieceSide GetSide() const noexcept { return m_Side; }
    inline const PieceType GetType() const noexcept { return m_Type; }
	
	Piece& operator = (const Piece& piece);
	Piece& operator = (Piece&& piece);
	
protected:
	PieceSide m_Side{};
    PieceType m_Type{};

    MovesContainer m_Moves{};
};

