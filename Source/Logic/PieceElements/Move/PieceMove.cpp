#include "PieceMove.hpp"

#include "Logic/BoardElements/Board/Board.hpp"

PieceMove::PieceMove(const DefaultMove& defaultMove)
	: m_DefaultMove{ defaultMove }
{}

bool PieceMove::CheckRequirements(const Board& board,
	const BoardCell& initial, const BoardCell& final,
    const std::uint16_t currentMove) const noexcept
{
	return true;
}
