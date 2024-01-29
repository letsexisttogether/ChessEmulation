#include "BoardObserver.hpp"

#include "Logic/Gameplay/SideHolder/PieceSideHolder.hpp"
#include "Logic/Move/Moves/BasicMove.hpp"
#include "Logic/Move/Moves/MoveEffect/MoveEffect.hpp"
#include <iterator>
#include <stdexcept>

void BoardObserver::AddPiece(BoardCell* cell) noexcept(false)
{
    CheckCell(cell); 

    const Piece* piece = &cell->GetPiece();

    CellContainer& container = GetCells(piece->GetSide());
    container.push_back(cell);
}

void BoardObserver::UpdatePiece(BoardCell* cell) noexcept(false)
{
    CheckCell(cell);

    const Piece& piece = cell->GetPiece();
    const PieceSide side = piece.GetSide();
    const PieceType type = piece.GetType();

    const std::size_t index = FindCell(side, type);
    
    CellContainer& container = GetCells(side);
    container[index] = cell;
}

void BoardObserver::DeletePiece(const PieceSide side, 
    const PieceType type) noexcept(false)
{
    const std::size_t index = FindCell(side, type);
    
    CellContainer& container = GetCells(side);

    container.erase(container.begin() + index);
}

const Piece& BoardObserver::GetPiece(const PieceSide side, 
    const PieceType type) const noexcept(false)
{
    const std::size_t index = FindCell(side, type);

    const CellContainer& container = GetContainer(side);

    return container[index]->GetPiece();
}

BoardObserver::PiecesContainer 
    BoardObserver::GetPieces(const PieceSide side) const noexcept
{
    PiecesContainer pieces{};

    for (const BoardCell* cell : GetContainer(side))
    {
        pieces.push_back(&cell->GetPiece());
    }

    return pieces;
}

bool BoardObserver::IsKingSave(const Board& board, 
    const PieceSide side) const noexcept(false)
{
    const PieceSideHolder holder{ side };

    const BoardCell* kingCell = 
        GetContainer(side)[FindCell(side, PieceType::KING)];

    for (const BoardCell* cell : 
        GetContainer(holder.GetOppositeSide()))
    {
        if (const MoveEffect moveEffect = 
            cell->GetPiece().TryMove(board, *cell, *kingCell);
            moveEffect != MoveEffect::NONE)
        {
            return true;
        }
    }

    return false;
}

BoardObserver::CellContainer& 
    BoardObserver::GetCells(const PieceSide side) 
    noexcept
{
    return const_cast<CellContainer&>(GetCells(side));
}

const BoardObserver::CellContainer& 
    BoardObserver::GetContainer(const PieceSide side) 
    const noexcept
{
    if (side == PieceSide::WHITE)
    {
        return m_White;
    }

    return m_Black;
}

std::size_t BoardObserver::FindCell(const PieceSide side, 
    const PieceType type) const noexcept(false)
{
    const CellContainer& container = GetContainer(side);

    const auto& iter = std::find_if(container.begin(), container.end(),
        [=] (const BoardCell* cell)
        {
            const Piece& piece = cell->GetPiece();

            return piece.GetType() == type;
        });

    return std::distance(container.begin(), iter);
}

void BoardObserver::CheckCell(const BoardCell* cell) 
    const noexcept(false)
{
    if (cell->IsFree())
    {
        throw std::runtime_error{ "BoardObserver: The cell is empty" };
    }
}

