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
        noexcept(false) override;

    void UndoMove(Board& board, BoardCell& initial, BoardCell& final)
        noexcept(false) override;

    void CompleteMove(Match& match) noexcept(false) override;

    BasicMove* Clone() const noexcept override;

    void SpawnLegalMoves(Board& board, 
        BoardCell& initial, 
        std::vector<MovePair>& moves) 
        noexcept(false) override;

	TransferMove& operator = (const TransferMove&) = delete;
	TransferMove& operator = (TransferMove&&) = delete;

    bool IsBasicAlright(const BoardCell& initial, 
        const BoardCell& final) const noexcept override;

protected:
    BoardCell::PiecePointer m_PieceSave{};
};

