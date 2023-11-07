#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <utility>

#include "Logic/PieceElements/Piece/Piece.hpp"
#include "Index/BoardCellIndex.hpp"

class BoardCell
{
public:
	BoardCell() = delete;

    // Change it latter mb
	BoardCell(const BoardCell&) = default;
	BoardCell(BoardCell&& cell) = default;

	BoardCell(const BoardCellIndex& index, const sf::Texture& texture,
		const std::shared_ptr<Piece>& piece);

	~BoardCell() = default;

	inline const BoardCellIndex& GetIndex() const noexcept { return m_Index; }

	inline const std::shared_ptr<Piece>& GetPiece() const noexcept { return m_Piece; }
	void SetPiece(const std::shared_ptr<Piece>& piece) noexcept;

	inline bool IsFree() const noexcept { return static_cast<bool>(m_Piece); }
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
	std::shared_ptr<Piece> m_Piece;
	
	sf::Sprite m_Sprite;
};