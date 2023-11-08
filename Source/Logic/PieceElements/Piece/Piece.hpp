#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Side.hpp"
#include "Logic/PieceElements/Move/BasicMove.hpp"

class Piece : public sf::Drawable
{
public:
    using MovePointer = BasicMove*;
    using MovesContainer = std::vector<MovePointer>;

public:
	Piece() = delete;
	Piece(const Piece&) = delete;
	Piece(Piece&&) = delete;

	Piece(const sf::Texture& texture, const Side side);
    Piece(const Side side, const MovesContainer& moves);

	virtual ~Piece() = default;

    // MoveResult
    MoveEffect TryMove(const BoardCell& initial, 
            const BoardCell& final) const noexcept;

	inline const sf::Vector2f& GetScreenPosition() const noexcept { return m_Sprite.getPosition(); }
	void SetScreenPosition(const sf::Vector2f& position) noexcept;

	inline const Side& GetSide() const noexcept { return m_Side; }
	inline sf::Vector2u GetTextureSize() const noexcept { return m_Sprite.getTexture()->getSize(); }
	
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	Piece& operator = (const Piece&) = delete;
	Piece& operator = (Piece&&) = delete;
	
protected:
	Side m_Side{};
	sf::Sprite m_Sprite{};
    MovesContainer m_Moves{};



    // Old ideas, let's just leave them as that

	// Includes default moves and attacks
	// std::vector<PieceMove> m_AllPossibleMoves{};
	// 
	// std::vector<PieceMove> m_AllowedAttacks{};
	// std::vector<PieceMove> m_AllowedMoves{};
};




