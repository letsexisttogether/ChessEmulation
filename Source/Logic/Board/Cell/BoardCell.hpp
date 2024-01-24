#pragma once

#include <memory>

#include "Index/BoardCellIndex.hpp"
#include "Logic/Piece/Piece.hpp"

class BoardCell : public Intersectable
{
public:
    using PiecePointer = std::shared_ptr<Piece>;

public:
	BoardCell() = delete;
	BoardCell(const BoardCell&) = delete;
	BoardCell(BoardCell&& cell);

    BoardCell(const BoardCellIndex& index);

    BoardCell(const BoardCellIndex& index, 
        const Position position,
        const Size size,
        const PiecePointer piece = nullptr);

	~BoardCell() = default;

    BasicMove* TryMove(Board& board, BoardCell& final) 
        noexcept(false);

    const BoardCellIndex& GetIndex() const noexcept;

    PiecePointer GetPiecePointer() noexcept;
    Piece& GetPiece() noexcept(false);
    const Piece& GetPiece() const noexcept(false);
	void SetPiece(const PiecePointer piece) noexcept;

    void TransferPiece(BoardCell& cell) noexcept;

	bool IsFree() const noexcept;
    void CheckPiece() const noexcept(false);
	void MakeFree() noexcept;

    void OnInteract() noexcept(false) override;

 	BoardCell& operator = (const BoardCell&) = delete;
	BoardCell& operator = (BoardCell&&) = delete;

	DefaultMove operator - (const BoardCell& cell) const noexcept(false);

public:
	struct IndexHash
	{
  		std::size_t operator() (const BoardCell& cell) const noexcept;
	};

	struct IndexEqual 
	{
  		bool operator() (const BoardCell& fCell, 
            const BoardCell& sCell) const noexcept;
	};

private: 
	void FitPiece() noexcept(false);

protected:
	const BoardCellIndex m_Index;

	PiecePointer m_Piece{};
};