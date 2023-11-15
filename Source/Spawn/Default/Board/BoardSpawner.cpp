#include "BoardSpawner.hpp"

BoardSpawner::BoardSpawner(ObjStorage* piecesOrder, PtrStorage* piecesSpawners,
        CellSpawner* cellSpawner, const Counter blankCellsCount)
    : m_PieceOrder{ piecesOrder }, m_PieceSpawners{ piecesSpawners },
    m_CellSpawner{ cellSpawner }, m_BlankCellsCount{ blankCellsCount }
{}

Board BoardSpawner::GetInstance() noexcept(false)
{
    Board board{};

    FillCells(board, PieceSide::WHITE);

    FillWithBlank(board);

    FillCells(board, PieceSide::BLACK);

    return board;
}

void BoardSpawner::FillCells(Board& board, const PieceSide side) noexcept(false)
{
    PieceSpawner* pieceSpawner = m_PieceSpawners->GetInstance(side);

    for (const PieceType pieceType : m_PieceOrder->GetInstance(side))
    {
        BoardCell cell{ m_CellSpawner->GetInstance() };
        cell.SetPiece(pieceSpawner->GetInstance(pieceType));

        board.AddCell(std::move(cell));
    }
}

void BoardSpawner::FillWithBlank(Board& board) noexcept(false)
{
    for (Counter i = 0; i <= m_BlankCellsCount; ++i)
    {
        board.AddCell(m_CellSpawner->GetInstance());
    }
}