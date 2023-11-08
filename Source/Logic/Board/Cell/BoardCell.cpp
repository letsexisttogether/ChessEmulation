#include "BoardCell.hpp"

BoardCell::BoardCell(const BoardCellIndex &index, const sf::Texture &texture, 
        const std::shared_ptr<Piece>& piece)
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

	const sf::Vector2u pieceHalfSize{ m_Piece->GetTextureSize() / 2u };
	const sf::Vector2u cellHalfSize{ m_Sprite.getTexture()->getSize() / 2u };
	const sf::Vector2f& currentCellPos = m_Sprite.getPosition();

	const sf::Vector2f pieceNewPosition{ currentCellPos.x + cellHalfSize.x - 
        pieceHalfSize.x, currentCellPos.y + cellHalfSize.y - pieceHalfSize.y };

	m_Piece->SetScreenPosition(pieceNewPosition);
}

DefaultMove BoardCell::operator - (const BoardCell &cell) const noexcept(false)
{
	const std::int8_t vericalDiff = m_Index.GetRank() - cell.m_Index.GetRank();
	const std::int8_t horizontalDiff = m_Index.GetFile() - cell.m_Index.GetFile();

	if (!vericalDiff && !horizontalDiff)
	{
		return DefaultMove{ MoveDirection::NONE, 
			DefaultMove::Distance{ vericalDiff, vericalDiff } };
	}

	if(!vericalDiff)
	{
		return DefaultMove{ ((horizontalDiff < 0) ? 
                (MoveDirection::RIGHT) : (MoveDirection::LEFT)), 
			DefaultMove::Distance{ vericalDiff, std::abs(horizontalDiff) } };
	}
	if (!horizontalDiff)
	{
		return DefaultMove{ ((vericalDiff < 0) ? 
                (MoveDirection::UP) : (MoveDirection::DOWN)), 
			DefaultMove::Distance{ std::abs(vericalDiff), horizontalDiff } };
	}

	if (vericalDiff < 0)
	{
		return DefaultMove{ ((horizontalDiff < 0) ? 
                (MoveDirection::UP_RIGHT) : (MoveDirection::UP_LEFT)), 
			DefaultMove::Distance{ std::abs(vericalDiff), std::abs(horizontalDiff) } };
	}

	return DefaultMove{ ((horizontalDiff < 0) ? 
            (MoveDirection::DOWN_RIGHT) : (MoveDirection::DOWN_LEFT)), 
		DefaultMove::Distance{ vericalDiff, std::abs(horizontalDiff) } };
}

std::size_t BoardCell::IndexHash::operator() (const BoardCell& cell) const noexcept
{
    const std::size_t h1 = std::hash<uint8_t>{}(cell.GetIndex().GetRank());
    const std::size_t h2 = std::hash<char>{}(cell.GetIndex().GetFile());
	return h1 ^ (h2 << 1);
}

bool BoardCell::IndexEqual::operator() (const BoardCell& fCell, const BoardCell& sCell) const noexcept
{
    return fCell.GetIndex() == sCell.GetIndex();
}