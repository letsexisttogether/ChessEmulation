#pragma once

#include "Logic/Board.hpp"

class MoveValidator
{
public:
    MoveValidator(const Board& board) noexcept;

    virtual auto IsMoveValid(const BoardCell& fromCell,
        const BoardCell& toCell) -> bool;

// protected:
    auto IsPathEmpty(BoardCell fromCell, const BoardCell& toCell)
        const -> bool;

protected:
    const Board& m_Board;
};

class PawnMoveValidator final : public MoveValidator
{
public:
    using MoveValidator::MoveValidator;

public:
    auto IsMoveValid(const BoardCell& fromCell,
        const BoardCell& toCell) -> bool override;

private:
    CNST::File m_WhiteStartFile{ 2 };
    CNST::File m_BlackStartFile{ 7 };
};

class RookMoveValidator final : public MoveValidator
{
public:
    using MoveValidator::MoveValidator;

public:
    auto IsMoveValid(const BoardCell& fromCell,
        const BoardCell& toCell) -> bool override;
};

class KnightMoveValidator final : public MoveValidator
{
public:
    using MoveValidator::MoveValidator;

public:
    auto IsMoveValid(const BoardCell& fromCell,
        const BoardCell& toCell) -> bool override;
};

class BishipMoveValidator final : public MoveValidator
{
public:
    using MoveValidator::MoveValidator;

public:
    auto IsMoveValid(const BoardCell& fromCell,
        const BoardCell& toCell) -> bool override;
};
