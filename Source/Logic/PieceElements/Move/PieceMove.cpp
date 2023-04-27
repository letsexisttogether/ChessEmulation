#include "PieceMove.hpp"

#include "Logic/BoardElements/Board/Board.hpp"

PieceMove::PieceMove(const DefaultMove& defaultMove)
	: m_DefaultMove{ defaultMove }
{}

bool PieceMove::CheckRequirements(const Board& board,
	const BoardCell& initial, const BoardCell& final) const noexcept(false)
{
	if (!final.IsFree() && initial.GetPiece().GetSide() == final.GetPiece().GetSide())
	{
		return false;
	}

	const DefaultMove move{ final - initial };

	for (CellIndex i{ initial.GetIndex() + move }; i != final.GetIndex(); i += move)
	{
		if (!board[i].IsFree())
		{
			return false;
		}
	}

	return true;
}

void PieceMove::HandleMove(BoardCell& initial, BoardCell& final) const noexcept
{
	if (!final.IsFree())
	{	
		// DeadBoard logic
	}

	final.SetPiece(initial);
}
