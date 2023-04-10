#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Side.hpp"
#include "Logic/PieceElements/Move/PieceMove/PieceMove.hpp"

class Piece : public sf::Drawable
{
public:
	Piece() = delete;
	Piece(const Piece&) = delete;
	Piece(Piece&&) = delete;

	Piece(const sf::Texture& texture, Side side);

	virtual ~Piece() = default;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	inline const sf::Vector2f& GetScreenPosition() const noexcept { return m_Sprite.getPosition(); }
	void SetScreenPosition(const sf::Vector2f& position) noexcept;

	inline const Side& GetSide() const noexcept { return m_Side; }
	inline const sf::Vector2u& GetSize() const noexcept { return m_Sprite.getTexture()->getSize(); }
	
	Piece& operator = (const Piece&) = delete;
	Piece& operator = (Piece&&) = delete;
	
protected:
	Side m_Side{};
	sf::Sprite m_Sprite{};

	// Includes default moves and attacks
	std::vector<PieceMove> m_AllPossibleMoves{};

	std::vector<PieceMove> m_AllowedAttacks{};
	std::vector<PieceMove> m_AllowedMoves{};
};




