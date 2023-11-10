#pragma once

#include <memory>
#include <utility>

#include "Graphic/Intersectable/Intersectable.hpp"
#include "Logic/PieceElements/Piece/Piece.hpp"
#include "Index/BoardCellIndex.hpp"

class BoardCell : public Intersectable
{
public:
    using PiecePointer = Piece*;
public:
	BoardCell() = delete;

    // Change it latter mb
	BoardCell(const BoardCell&) = default;
	BoardCell(BoardCell&& cell) = default;

    BoardCell(const BoardCellIndex& index);

	BoardCell(const BoardCellIndex& index, const sf::Texture& texture,
		const PiecePointer& piece);

	~BoardCell() = default;

	inline const BoardCellIndex& GetIndex() const noexcept { return m_Index; }

	inline const PiecePointer GetPiece() const noexcept { return m_Piece; }
	void SetPiece(const PiecePointer piece) noexcept;

	bool IsFree() const noexcept { return !m_Piece; }
	void FreeCell() noexcept;

    // void OnIntersect(const Controller& controller) noexcept override;

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
  		bool operator() (const BoardCell& fCell, const BoardCell& sCell) const noexcept;
	};

protected: 
	void FitPiece() noexcept(false);

protected:
	const BoardCellIndex m_Index;
	PiecePointer m_Piece{};
};