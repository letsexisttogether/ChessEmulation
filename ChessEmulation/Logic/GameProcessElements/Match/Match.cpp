#include "Match.hpp"

Match::Match(Board&& mainBoard, Board&& deadBoard, const Player& whitePlayer, const Player& blackPlayer, const Side turn)
	: m_MainBoard{ std::move(mainBoard) }, m_DeadBoard{ std::move(deadBoard) },
	m_WhitePlayer{ whitePlayer }, m_BlackPlayer{ blackPlayer }, m_CurrentTurn{ turn }
{}

void Match::ChangeTurn() noexcept
{
	m_CurrentTurn == ((m_CurrentTurn == Side::BLACK) ? (Side::WHITE) : (Side::BLACK));
}

const Player& Match::GetCurrentPlayer() const noexcept
{
	return ((m_CurrentTurn == Side::BLACK) ? (m_BlackPlayer) : (m_WhitePlayer));
}
