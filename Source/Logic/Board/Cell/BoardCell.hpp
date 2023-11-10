#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <utility>

#include "Logic/PieceElements/Piece/Piece.hpp"
#include "Index/BoardCellIndex.hpp"

class BoardCell
{
public:
    using PiecePointer = Piece*;
public:
	BoardCell() = delete;

    // Change it latter mb
	BoardCell(const BoardCell&) = default;
	BoardCell(BoardCell&& cell) = default;

    // TODO: add c_tor for index without specifying texture and piece;

	BoardCell(const BoardCellIndex& index, const sf::Texture& texture,
		const PiecePointer& piece);

	~BoardCell() = default;

	inline const BoardCellIndex& GetIndex() const noexcept { return m_Index; }

	inline const PiecePointer& GetPiece() const noexcept { return m_Piece; }
	void SetPiece(const PiecePointer& piece) noexcept;

	bool IsFree() const noexcept { return !m_Piece; }
	void FreeCell() noexcept;

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
	PiecePointer m_Piece;
	
	sf::Sprite m_Sprite;
};