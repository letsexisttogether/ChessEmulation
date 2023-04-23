#include "BoardCell.hpp"

BoardCell::BoardCell(BoardCell&& cell)
	: m_Index{ cell.m_Index }, m_Sprite{ cell.m_Sprite }, m_Piece{ std::move(cell.m_Piece) }
{}

BoardCell::BoardCell(const CellIndex& index, const sf::Texture& texture, std::unique_ptr<Piece>&& piece)
    : m_Index{ index }, m_Sprite{ texture }, m_Piece{ std::move(piece) }
{}

// It should be depricated later
void BoardCell::SetPiece(BoardCell& cell) noexcept
{
	m_Piece = std::move(cell.m_Piece); 

	FitPiece();
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

	const sf::Vector2f pieceNewPosition{ currentCellPos.x + cellHalfSize.x - pieceHalfSize.x,
		currentCellPos.y + cellHalfSize.y - pieceHalfSize.y };

	m_Piece->SetScreenPosition(pieceNewPosition);
}

DefaultMove BoardCell::operator - (const BoardCell &cell) const noexcept
{
	const std::int8_t vericalDiff = m_Index.GetHorizontal() - cell.m_Index.GetHorizontal();
	const std::int8_t horizontalDiff = m_Index.GetVertical() - cell.m_Index.GetVertical();

	if (!vericalDiff && !horizontalDiff)
	{
		return DefaultMove{ MoveDirection::NONE, 
			DefaultMove::Distance{ vericalDiff, vericalDiff } };
	}

	if(!vericalDiff)
	{
		return { ((horizontalDiff < 0) ? (MoveDirection::RIGHT) : (MoveDirection::LEFT)), 
			DefaultMove::Distance{ vericalDiff, std::abs(horizontalDiff) } };
	}
	if (!horizontalDiff)
	{
		return { ((vericalDiff < 0) ? (MoveDirection::UP) : (MoveDirection::DOWN)), 
			DefaultMove::Distance{ std::abs(vericalDiff), horizontalDiff } };
	}

	if (vericalDiff < 0)
	{
		return { ((horizontalDiff < 0) ? (MoveDirection::UP_RIGHT) : (MoveDirection::UP_LEFT)), 
			DefaultMove::Distance{ std::abs(vericalDiff), std::abs(horizontalDiff) } };
	}

	return { ((horizontalDiff < 0) ? (MoveDirection::DOWN_RIGHT) : (MoveDirection::DOWN_LEFT)), 
		DefaultMove::Distance{ vericalDiff, std::abs(horizontalDiff) } };
}

std::size_t BoardCell::Hash::operator() (const BoardCell& cell) const noexcept
{
    const std::size_t h1 = std::hash<uint8_t>{}(cell.GetIndex().GetVertical());
    const std::size_t h2 = std::hash<char>{}(cell.GetIndex().GetHorizontal());
	return h1 ^ (h2 << 1);
}

bool BoardCell::Equal::operator() (const BoardCell& fCell, const BoardCell& sCell) const noexcept
{
    return fCell.GetIndex() == sCell.GetIndex();
}
