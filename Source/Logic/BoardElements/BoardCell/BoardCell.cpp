#include "BoardCell.hpp"

BoardCell::BoardCell(const std::pair<uint8_t, char>& index, const std::shared_ptr<sf::Texture> texture, const std::shared_ptr<Piece> piece)
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

bool BoardCell::operator < (const BoardCell &cell) const noexcept
{
    return (m_Index.first < cell.m_Index.first && m_Index.second == cell.m_Index.second
		|| m_Index.first == cell.m_Index.first && m_Index.second < cell.m_Index.second);
}

bool BoardCell::operator > (const BoardCell &cell) const noexcept
{
    return (m_Index.first > cell.m_Index.first && m_Index.second == cell.m_Index.second
		|| m_Index.first == cell.m_Index.first && m_Index.second > cell.m_Index.second);
}

bool BoardCell::operator == (const BoardCell &cell) const noexcept
{
    return m_Index == cell.m_Index;
}

bool BoardCell::operator != (const BoardCell &cell) const noexcept
{
    return !(*this == cell);
}

DefaultMove BoardCell::operator - (const BoardCell &cell) const noexcept(false)
{
	const int8_t vericalDiff = m_Index.first - cell.m_Index.first;
	const int8_t horizontalDiff = m_Index.second - cell.m_Index.second;

	if (!vericalDiff && !horizontalDiff)
	{
		return DefaultMove{ MoveDirection::NONE, 
			std::pair<uint8_t, uint8_t>{ vericalDiff, vericalDiff } };
	}

	if(!vericalDiff)
	{
		return DefaultMove{ ((horizontalDiff > 0) ? (MoveDirection::RIGHT) : (MoveDirection::LEFT)), 
			std::pair<uint8_t, uint8_t>{ vericalDiff, std::abs(horizontalDiff) } };
	}
	if (!horizontalDiff)
	{
		return DefaultMove{ ((vericalDiff > 0) ? (MoveDirection::DOWN) : (MoveDirection::UP)), 
			std::pair<uint8_t, uint8_t>{ std::abs(vericalDiff), horizontalDiff } };
	}

	if (vericalDiff < 0)
	{
		return DefaultMove{ ((horizontalDiff > 0) ? (MoveDirection::UP_RIGHT) : (MoveDirection::UP_LEFT)), 
			std::pair<uint8_t, uint8_t>{ vericalDiff, std::abs(horizontalDiff) } };
	}

	return DefaultMove{ ((horizontalDiff > 0) ? (MoveDirection::DOWN_RIGHT) : (MoveDirection::DOWN_LEFT)), 
		std::pair<uint8_t, uint8_t>{ vericalDiff, std::abs(horizontalDiff) } };
}
