#include "PieceMove.hpp"

#include "Logic/BoardElements/Board/Board.hpp"

PieceMove::PieceMove(const DefaultMove& defaultMove)
	: m_DefaultMove{ defaultMove }
{}

bool PieceMove::CheckRequirements(const Board& board,
	const BoardCell& initial, const BoardCell& final) const noexcept(false)
{
	const auto& iPiece = initial.GetPiece();
	const auto& fPiece = final.GetPiece();

	if (!final.IsFree() && iPiece.GetSide() == fPiece.GetSide())
	{
		return false;
	}

	const DefaultMove move{ final - initial };

	for (CellIndex i{ initial.GetIndex() }; i != final.GetIndex(); i += move)
	{
		const auto& currentCell = board[i];
	}


	return true;
}
