#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <utility>

#include "Logic/Pieces/Piece/Piece.hpp"

class BoardCell
{
public:
	BoardCell() = delete;
	BoardCell(const BoardCell&) = delete;
	BoardCell(BoardCell&&) = delete;

	BoardCell(const std::pair<uint8_t, char> index, std::shared_ptr<sf::Texture> texture,
		const std::shared_ptr<Piece> piece);

	const inline std::pair<uint8_t, char>& GetIndex() const noexcept { return m_Index; }
	const inline std::shared_ptr<Piece>& GetPiece() const noexcept { return m_Piece; }

	inline bool IsFree() const noexcept { return static_cast<bool>(m_Piece); }

 	BoardCell& operator = (const BoardCell&) = delete;
	BoardCell& operator = (BoardCell&&) = delete;

private:
	std::pair<uint8_t, char> m_Index;
	std::shared_ptr<sf::Texture> m_Texture;

	std::shared_ptr<Piece> m_Piece;
};