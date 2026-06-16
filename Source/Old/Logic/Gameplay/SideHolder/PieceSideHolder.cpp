#include "PieceSideHolder.hpp"

PieceSideHolder::PieceSideHolder(const PieceSide side)
    : m_Side{ side }
{}

PieceSide PieceSideHolder::GetSide() const noexcept
{
    return m_Side;
}

PieceSide PieceSideHolder::GetOppositeSide() const noexcept
{
    return ((m_Side == PieceSide::WHITE) ? 
        (PieceSide::BLACK) : (PieceSide::WHITE));
}

void PieceSideHolder::FlipSide() noexcept
{
    m_Side = GetOppositeSide();
}

