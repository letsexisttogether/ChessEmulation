#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <utility>

#include "Logic/PieceElements/Piece/Piece.hpp"
#include "CellIndex/CellIndex.hpp"

class BoardCell
{
public:
	BoardCell() = delete;
	BoardCell(const BoardCell&) = default;
	BoardCell(BoardCell&&) = default;

	BoardCell(const CellIndex& index, const sf::Texture& texture,
		const std::shared_ptr<Piece>& piece);

	~BoardCell() = default;

	inline const CellIndex& GetIndex() const noexcept { return m_Index; }

	inline const std::shared_ptr<Piece>& GetPiece() const noexcept { return m_Piece; }
	void SetPiece(const std::shared_ptr<Piece>& piece) noexcept;

	inline bool IsFree() const noexcept { return static_cast<bool>(m_Piece); }
	void FreeCell() noexcept;

 	BoardCell& operator = (const BoardCell&) = delete;
	BoardCell& operator = (BoardCell&&) = delete;

	DefaultMove operator - (const BoardCell& cell) const noexcept;

public:
	struct Hash
	{
  		std::size_t operator()(const BoardCell& cell) const noexcept;
	};

	struct Equal 
	{
  		bool operator()(const BoardCell& fCell, const BoardCell& sCell) const noexcept;
	};

protected: 
	void FitPiece() noexcept(false);

protected:
	const CellIndex m_Index;
	const sf::Sprite m_Sprite;
	
	std::shared_ptr<Piece> m_Piece;
};