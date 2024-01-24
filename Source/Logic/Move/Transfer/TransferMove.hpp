#pragma once

#include "Logic/Move/BasicMove.hpp"

#include "Logic/Board/Board.hpp"

class TransferMove : public BasicMove
{
public:
	TransferMove() = delete;
	TransferMove(const TransferMove&) = default;
	TransferMove(TransferMove&&) = default;

	TransferMove(const DefaultMove& defaultMove);

	~TransferMove() = default;

	bool IsConditionSatisfied(Board& board, BoardCell& initial,
        BoardCell& final, const bool shouldCheckKing)
        noexcept(false) override;

    void DoMove(Board& board, BoardCell& initial, BoardCell& final)
        noexcept override;

    void UndoMove(Board& board, BoardCell& initial, BoardCell& final)
        noexcept override;

    void CompleteMove(Match& match) noexcept override;

    BasicMove* Clone() const noexcept override;

	TransferMove& operator = (const TransferMove&) = delete;
	TransferMove& operator = (TransferMove&&) = delete;

protected:
    bool IsBasicAlright(BoardCell& initial, 
        BoardCell& final) const noexcept override;

protected:
    BoardCell::PiecePointer m_PieceSave{};
};

