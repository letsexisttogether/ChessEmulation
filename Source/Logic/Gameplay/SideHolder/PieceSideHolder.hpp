#pragma once

#include "Logic/Piece/Side/PieceSide.hpp"

class PieceSideHolder
{
public:
    PieceSideHolder() = default;
    PieceSideHolder(const PieceSideHolder&) = default;
    PieceSideHolder(PieceSideHolder&&) = default;

    PieceSideHolder(const PieceSide side);
    
    ~PieceSideHolder() = default;

    PieceSide GetSide() const noexcept;

    PieceSide GetOppositeSide() const noexcept;

    void FlipSide() noexcept;

    PieceSideHolder& operator = (const PieceSideHolder&) = default;
    PieceSideHolder& operator = (PieceSideHolder&&) = default;

private:
    PieceSide m_Side{ PieceSide::WHITE };
};
