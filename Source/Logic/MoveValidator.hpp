#pragma once

#include <vector>
#include <unordered_set>

#include "Logic/Board.hpp"
#include "Logic/Move.hpp"

class MoveValidator
{
public:
    MoveValidator(const Board& board) noexcept;

    virtual auto IsMoveValid(const BoardCell fromCell,
        const BoardCell toCell) -> bool;

protected:
    auto IsPathEmpty(const BoardCell& fromCell,
        const BoardCell& toCell) -> bool;

protected:
    const Board& m_Board;
};

class PawnMoveValidator final : public MoveValidator
{
public:
    PawnMoveValidator(const Board& board) noexcept;

    auto IsMoveValid(const BoardCell fromCell,
        const BoardCell toCell) -> bool override;

private:
    CNST::File m_WhiteStartFile{ 2 };
    CNST::File m_BlackStartFile{ 7 };
};
