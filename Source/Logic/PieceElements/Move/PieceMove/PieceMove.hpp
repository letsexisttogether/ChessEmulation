#pragma once

#include <utility>
#include <memory>

#include "Logic/PieceElements/Move/Enums/MovePossibility.hpp"
#include "Logic/PieceElements/Move/MoveCheckers/MoveChecker.hpp"

class PieceMove
{
public:
	PieceMove() = delete;
	PieceMove(const PieceMove&) = delete;
	PieceMove(PieceMove&&) = delete;

	PieceMove(const MovePossibility movePossibility, const std::pair<uint8_t, uint8_t> distance, 
		MoveChecker* const checker);

	inline const MovePossibility& GetMovePossibility() const noexcept { return m_MovePossibility; }
	
	inline const std::pair<uint8_t, uint8_t>& GetDistance() const noexcept { return m_Distance; }
	
	inline const MoveChecker& GetChecker() const noexcept { return *m_Checker; }

	~PieceMove() = default;

	PieceMove& operator = (const PieceMove&) = delete;
	PieceMove& operator = (PieceMove&&) = delete;

private:
	MovePossibility m_MovePossibility;
	std::pair<uint8_t, uint8_t> m_Distance; 
	std::unique_ptr<MoveChecker> m_Checker;
};