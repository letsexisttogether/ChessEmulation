#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Side.hpp"
#include "Logic/PieceElements/Move/PieceMove.hpp"

class BoardCell;

class Piece : public sf::Drawable
{
public:
	Piece() = delete;
	Piece(const Piece&) = delete;
	Piece(Piece&&) = delete;

	Piece(const sf::Texture& texture, Side side);

	virtual ~Piece() = default;

    // MoveResult

	inline const sf::Vector2f& GetScreenPosition() const noexcept { return m_Sprite.getPosition(); }
	void SetScreenPosition(const sf::Vector2f& position) noexcept;

	inline const Side& GetSide() const noexcept { return m_Side; }
	inline sf::Vector2u GetTextureSize() const noexcept { return m_Sprite.getTexture()->getSize(); }
	
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	Piece& operator = (const Piece&) = delete;
	Piece& operator = (Piece&&) = delete;
	
protected:
	Side m_Side{};
    BoardCell& m_Cell;
	sf::Sprite m_Sprite{};
    std::vector<PieceMove> m_Moves;


	// Includes default moves and attacks
	// std::vector<PieceMove> m_AllPossibleMoves{};
	// 
	// std::vector<PieceMove> m_AllowedAttacks{};
	// std::vector<PieceMove> m_AllowedMoves{};
};




