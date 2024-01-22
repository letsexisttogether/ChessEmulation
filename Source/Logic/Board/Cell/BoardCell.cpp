#include "BoardCell.hpp"

#include <iostream>
#include <stdexcept>

#include "Application/Application.hpp"
#include "Application/Scenes/Game/GameScene.hpp"

BoardCell::BoardCell(BoardCell&& cell)
    : m_Index{ cell.m_Index }
{
    SetOrigin(cell.GetOrigin());
    SetSize(cell.GetSize());

    cell.TransferPiece(*this);
}

BoardCell::BoardCell(const BoardCellIndex& index)
    : m_Index{ index }
{}

BoardCell::BoardCell(const BoardCellIndex& index, 
    const Position position, 
    const Size size,
    const PiecePointer piece)
    : m_Index{ index }, m_Piece{ piece }
{
    // Change later due to virtual inheritance
    SetOrigin(position);
    SetSize(size);

    if (!IsFree())
    {
        FitPiece();
    }
}

const BoardCellIndex& BoardCell::GetIndex() const noexcept
{
    return m_Index;
}

Piece& BoardCell::GetPiece() noexcept(false)
{
    CheckPiece();

    return *m_Piece;
}

const Piece& BoardCell::GetPiece() const noexcept(false)
{
    CheckPiece();

    return *m_Piece;
}

void BoardCell::SetPiece(const PiecePointer piece) noexcept
{
    m_Piece = piece;

	FitPiece();
}

void BoardCell::TransferPiece(BoardCell& cell) noexcept
{
    if (IsFree())
    {
        return;
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

    match.GetGameObserver().SetCell(this);
    
    std::cout << "Rank (x): " << static_cast<std::int32_t>(m_Index.GetRank()) << ' '
        << "The file (y): " << static_cast<std::int32_t>(m_Index.GetFile()) << '\n';
}

DefaultMove BoardCell::operator - (const BoardCell& cell) const noexcept(false)
{
	const BoardCellIndex::Rank vericalDiff = 
        m_Index.GetFile() - cell.m_Index.GetFile();
	const BoardCellIndex::File horizontalDiff = 
        m_Index.GetRank() - cell.m_Index.GetRank();

	if (!vericalDiff && !horizontalDiff)
	{
		return DefaultMove{ MoveDirection::NONE, 
			DefaultMove::Distance{ vericalDiff, vericalDiff } };
	}

	if(!vericalDiff)
	{
		return DefaultMove{ ((horizontalDiff < 0) ? 
                (MoveDirection::RIGHT) : (MoveDirection::LEFT)), 
			DefaultMove::Distance{ vericalDiff, horizontalDiff } };
	}
	if (!horizontalDiff)
	{
		return DefaultMove{ ((vericalDiff < 0) ? 
                (MoveDirection::UP) : (MoveDirection::DOWN)), 
			DefaultMove::Distance{ vericalDiff, horizontalDiff } };
	}

	if (vericalDiff < 0)
	{
		return DefaultMove{ ((horizontalDiff < 0) ? 
                (MoveDirection::UP_RIGHT) : (MoveDirection::UP_LEFT)), 
			DefaultMove::Distance{ vericalDiff, horizontalDiff } };
	}

	return DefaultMove{ ((horizontalDiff < 0) ? 
            (MoveDirection::DOWN_RIGHT) : (MoveDirection::DOWN_LEFT)), 
		DefaultMove::Distance{ vericalDiff, horizontalDiff } };
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

    m_Piece->SetOrigin(m_Origin);
    m_Piece->SetSize(m_Size);
}

void BoardCell::CheckPiece() const noexcept(false)
{
	if (!m_Piece)
	{
		throw std::runtime_error{ "Missing piece on the cell" };
	}
}
