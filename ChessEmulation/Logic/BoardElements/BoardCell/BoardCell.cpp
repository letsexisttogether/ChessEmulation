#include "BoardCell.hpp"

BoardCell::BoardCell(const std::pair<uint8_t, char> index, std::shared_ptr<sf::Texture> texture, const std::shared_ptr<Piece> piece)
	: m_Index{ index }, m_Sprite{ *texture }, m_Piece{ piece }
{}

void BoardCell::SetPiece(const std::shared_ptr<Piece> piece) noexcept
{
	m_Piece = piece; 

	FitPiece();
}

void BoardCell::FreeCell() noexcept
{
	m_Piece = nullptr;
}

void BoardCell::FitPiece() noexcept(false)
{
	if (!m_Piece)
	{
		throw std::exception{ "Missing piece on the cell" };
	}

	const sf::Vector2u& pieceHalfSize = m_Piece->GetSize() / 2u;
	const sf::Vector2u& cellHalfSize = m_Sprite.getTexture()->getSize() / 2u;
	const sf::Vector2f& currentCellPos = m_Sprite.getPosition();

	const sf::Vector2f pieceNewPosition{ currentCellPos.x + cellHalfSize.x - pieceHalfSize.x,
		currentCellPos.y + cellHalfSize.y - pieceHalfSize.y };

	m_Piece->SetScreenPosition(pieceNewPosition);

}
