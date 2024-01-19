#pragma once

#include "Logic/PieceElements/Piece/Side/PieceSide.hpp"

class PieceSideHolder
{
public:
    PieceSideHolder() = delete;
    PieceSideHolder(const PieceSideHolder&) = default;
    PieceSideHolder(PieceSideHolder&&) = default;

    PieceSideHolder(const PieceSide side)
        : m_Side{ side }
    {}
    
    ~PieceSideHolder() = default;

    inline PieceSide GetSide() const noexcept { return m_Side; }
    // void SetSide(const PieceSide side) noexcept;

    PieceSide GetOppositeSide() const noexcept
    {
        return ((m_Side == PieceSide::WHITE) ? 
            (PieceSide::BLACK) : (PieceSide::WHITE));
    }

    void SetOppositeSide() noexcept
    {
        m_Side = GetOppositeSide();
    }

    PieceSideHolder& operator = (const PieceSideHolder&) = default;
    PieceSideHolder& operator = (PieceSideHolder&&) = default;

private:
    PieceSide m_Side{};
};
