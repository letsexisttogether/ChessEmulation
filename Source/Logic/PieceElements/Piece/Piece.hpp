#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <vector>

#include "Type/PieceType.hpp"
#include "Side/PieceSide.hpp"
#include "Logic/PieceElements/Move/BasicMove.hpp"

class Piece : public sf::Sprite
{
public:
    using MovePointer = std::unique_ptr<BasicMove>;

    using InMovesContainer = std::vector<BasicMove*>;
    using MovesContainer = std::vector<MovePointer>;

public:
	Piece() = default;
	Piece(const Piece& piece);
    // Implement later in the future
	Piece(Piece&& piece);

    Piece(const PieceSide side, const PieceType type, 
            const InMovesContainer& moves);

	virtual ~Piece() = default;

    MoveEffect TryMove(const BoardCell& initial, 
            const BoardCell& final) const noexcept;

	inline const PieceSide GetSide() const noexcept { return m_Side; }
    inline const PieceType GetType() const noexcept { return m_Type; }
	
	Piece& operator = (const Piece& piece);
	Piece& operator = (Piece&& piece);
	
protected:
	PieceSide m_Side{};
    PieceType m_Type{};
    MovesContainer m_Moves{};

    // Old ideas, let's just leave them as that

	// Includes default moves and attacks
	// std::vector<PieceMove> m_AllPossibleMoves{};
	// 
	// std::vector<PieceMove> m_AllowedAttacks{};
	// std::vector<PieceMove> m_AllowedMoves{};
};




