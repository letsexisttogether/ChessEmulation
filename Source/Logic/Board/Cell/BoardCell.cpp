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

BasicMove* BoardCell::TryMove(Board& board, BoardCell& final) 
    noexcept(false)
{
    CheckPiece();

    Piece::MovesContainer& moves = m_Piece->GetMoves();
    for (Piece::MovePointer& move : moves)
    {
        if (move->IsConditionSatisfied(board, *this, final, true))
        {
            return move.get();
        }
    }

    return nullptr;
}

BasicMove::MovePairContainer BoardCell::GetLegalMoves(Board& board)
    noexcept(false)
{
    CheckPiece();

    std::cout << "I TRY TO GET ALL THE MOVES FOR "
        << static_cast<std::int32_t>(m_Piece->GetType()) << ' '
        << " of " << static_cast<std::int32_t>(m_Piece->GetSide()) << '\n';

    BasicMove::MovePairContainer moves{};

    for (Piece::MovePointer& move : m_Piece->GetMoves())
    {
        move->SpawnLegalMoves(board, *this, moves);
    }

    std::cout << "I STOPED GETTING ALL THE MOVES\n";

    return moves;
}

const BoardCellIndex& BoardCell::GetIndex() const noexcept
{
    return m_Index;
}

BoardCell::PiecePointer BoardCell::GetPiecePointer() noexcept
{
    return m_Piece;
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

void BoardCell::CheckPiece() const noexcept(false)
{
	if (!m_Piece)
	{
        std::cout << "Missing\nRank (x): " << static_cast<std::int32_t>(m_Index.GetRank()) << ' '
            << "The file (y): " << static_cast<std::int32_t>(m_Index.GetFile()) << '\n';

		throw std::runtime_error
        { 
            "BoardCell: Missing piece on the cell" 
        };

	}
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

DefaultMove BoardCell::operator - (const BoardCell& cell) 
    const noexcept(false)
{
    const DefaultMove::Rank horizontalDiff = 
         m_Index.GetRank() - cell.m_Index.GetRank();
    const DefaultMove::File verticalDiff = 
        m_Index.GetFile() - cell.m_Index.GetFile();

    return { horizontalDiff, verticalDiff };
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

