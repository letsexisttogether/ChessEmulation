#include "BoardCell.hpp"

BoardCell::BoardCell(const Index &index, const sf::Texture &texture, const std::shared_ptr<Piece>& piece)
    : m_Index{ index }, m_Sprite{ texture }, m_Piece{ piece }
{}

void BoardCell::SetPiece(const std::shared_ptr<Piece>& piece) noexcept
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

	const sf::Vector2u pieceHalfSize { m_Piece->GetTextureSize() / 2u };
	const sf::Vector2u cellHalfSize = { m_Sprite.getTexture()->getSize() / 2u };
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

bool BoardCell::operator == (const BoardCell::Index &index) const noexcept
{
    return m_Index == index;
}

bool BoardCell::operator != (const BoardCell::Index &index) const noexcept
{
    return !(*this == index);
}

DefaultMove BoardCell::operator - (const BoardCell &cell) const noexcept
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
		return DefaultMove{ ((horizontalDiff < 0) ? (MoveDirection::RIGHT) : (MoveDirection::LEFT)), 
			std::pair<uint8_t, uint8_t>{ vericalDiff, std::abs(horizontalDiff) } };
	}
	if (!horizontalDiff)
	{
		return DefaultMove{ ((vericalDiff < 0) ? (MoveDirection::UP) : (MoveDirection::DOWN)), 
			std::pair<uint8_t, uint8_t>{ std::abs(vericalDiff), horizontalDiff } };
	}

	if (vericalDiff < 0)
	{
		return DefaultMove{ ((horizontalDiff < 0) ? (MoveDirection::UP_RIGHT) : (MoveDirection::UP_LEFT)), 
			std::pair<uint8_t, uint8_t>{ std::abs(vericalDiff), std::abs(horizontalDiff) } };
	}

	return DefaultMove{ ((horizontalDiff < 0) ? (MoveDirection::DOWN_RIGHT) : (MoveDirection::DOWN_LEFT)), 
		std::pair<uint8_t, uint8_t>{ vericalDiff, std::abs(horizontalDiff) } };
}

BoardCell::Index BoardCell::operator + (const DefaultMove &move) const noexcept(false)
{
	switch (const auto& distance = move.GetDistance(); move.GetMoveDirection())
	{
	case MoveDirection::UP:
		return Index{ m_Index.first + distance.first, m_Index.second };
	case MoveDirection::DOWN:
		return Index{ m_Index.first - distance.first, m_Index.second };
	case MoveDirection::RIGHT:
		return Index{ m_Index.first, m_Index.second + distance.second};
	case MoveDirection::LEFT:
		return Index{ m_Index.first, m_Index.second - distance.second };

	case MoveDirection::UP_RIGHT:
		return Index{ m_Index.first + distance.first, m_Index.second + distance.second };
	case MoveDirection::UP_LEFT:
		return Index{ m_Index.first + distance.first, m_Index.second - distance.second };
	case MoveDirection::DOWN_RIGHT:
		return Index{ m_Index.first - distance.first, m_Index.second + distance.second };
	case MoveDirection::DOWN_LEFT:
		return Index{ m_Index.first - distance.first, m_Index.second - distance.second };

	default:
		throw std::runtime_error("Unknown move direction passed");
		break;
	}

    return {};
}

std::size_t BoardCell::IndexHash::operator()(const BoardCell& cell) const noexcept
{
    const std::size_t h1 = std::hash<uint8_t>{}(cell.GetIndex().first);
    const std::size_t h2 = std::hash<char>{}(cell.GetIndex().second);
	return h1 ^ (h2 << 1);
}

bool BoardCell::IndexEqual::operator()(const BoardCell& fCell, const BoardCell& sCell) const noexcept
{
    return fCell.GetIndex() == sCell.GetIndex();
}
