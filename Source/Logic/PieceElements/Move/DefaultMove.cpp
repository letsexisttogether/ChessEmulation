#include "DefaultMove.hpp"

#include "Logic/BoardElements/Board/Board.hpp"

DefaultMove::DefaultMove(const MoveSpecs& defaultMove)
	: m_DefaultMove{ defaultMove }
{}

bool DefaultMove::CheckRequirements(const Board& board,
	const BoardCell& initial, const BoardCell& final) const noexcept(false)
{
	if (!final.IsFree() && initial.GetPiece().GetSide() == final.GetPiece().GetSide())
	{
		return false;
	}

	const MoveSpecs move{ final - initial };

	for (CellIndex i{ initial.GetIndex() + move }; i != final.GetIndex(); i += move)
	{
		if (!board[i].IsFree())
		{
			return false;
		}
	}

	return true;
}

void DefaultMove::HandleMove(Board& board, BoardCell& initial, BoardCell& final) const noexcept
{
	if (!final.IsFree())
	{	
		// DeadBoard logic
	}

	final.SetPiece(initial);
}
