#include "BoardCell.hpp"

#include <stdexcept>

#include "Application/Application.hpp"
#include "Application/Scenes/Game/GameScene.hpp"


BoardCell::BoardCell(const BoardCellIndex& index)
    : m_Index{ index }
{}

BoardCell::BoardCell(const BoardCellIndex& index, 
    const Position position, 
    const Size size,
    const PiecePointer piece)
    : Intersectable{ position, size }, 
    m_Index{ index }, m_Piece{ piece }
{}

Piece& BoardCell::GetPiece() noexcept
{
    return *m_Piece;
}

const Piece& BoardCell::GetPiece() const noexcept
{
    return *m_Piece;
}

void BoardCell::SetPiece(const PiecePointer piece) noexcept
{
    m_Piece = piece;

	FitPiece();
}

void BoardCell::TransferPiece(BoardCell& cell) noexcept(false)
{
    CheckPiece();

    // I do it like this for now, because there's no any dead pieces handling
    if (!cell.IsFree())
    {
        cell.MakeFree();
    }

    cell.SetPiece(m_Piece);
    
    MakeFree();
}

bool BoardCell::IsFree() const noexcept
{
    return !m_Piece;
}

void BoardCell::MakeFree() noexcept
{
	m_Piece.reset();
}

void BoardCell::OnInteract() noexcept(false) 
{
    Scene& scene = Application::GetInstance().GetScene();

    GameScene& gameScene = static_cast<GameScene&>(scene); 
    Match& match = gameScene.GetMatch();

    if (!IsFree())
    {
        match.GetGameObserver().SetCell(this);
    }
}

DefaultMove BoardCell::operator - (const BoardCell& cell) const noexcept(false)
{
	const BoardCellIndex::Rank vericalDiff = 
        m_Index.GetRank() - cell.m_Index.GetRank();
	const BoardCellIndex::File horizontalDiff = 
        m_Index.GetFile() - cell.m_Index.GetFile();

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

std::size_t BoardCell::IndexHash::operator() (const BoardCell& cell) 
    const noexcept
{
    const std::size_t h1 = std::hash<BoardCellIndex::Rank>{}(
            cell.GetIndex().GetRank());
    const std::size_t h2 = std::hash<BoardCellIndex::File>{}(
            cell.GetIndex().GetFile());

	return h1 ^ (h2 << 1);
}

bool BoardCell::IndexEqual::operator() (const BoardCell& fCell, 
        const BoardCell& sCell) const noexcept
{
    return fCell.GetIndex() == sCell.GetIndex();
}

void BoardCell::FitPiece() noexcept(false)
{
    CheckPiece();

    /*
    const sf::Vector2u pieceHalfSize{ m_Piece->GetTexture().getSize() / 2u };
    const sf::Vector2u cellHalfSize{ m_Texture->getSize() / 2u };
    const sf::Vector2f& currentCellPos = getPosition();

    const sf::Vector2f pieceNewPosition{ currentCellPos.x + cellHalfSize.x - 
        pieceHalfSize.x, currentCellPos.y + cellHalfSize.y - pieceHalfSize.y };

	m_Piece->setPosition(pieceNewPosition);
    
    */
}

void BoardCell::CheckPiece() const noexcept(false)
{
	if (!m_Piece)
	{
		throw std::runtime_error{ "Missing piece on the cell" };
	}
}
