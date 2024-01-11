#pragma once

#include <memory>

#include "Logic/PieceElements/Piece/Piece.hpp"
#include "Index/BoardCellIndex.hpp"

class BoardCell
{
public:
    using PiecePointer = std::shared_ptr<Piece>;
    using TexturePointer = std::shared_ptr<sf::Texture>;

public:
	BoardCell() = delete;

    // Change it latter mb
	BoardCell(const BoardCell&) = default;
	BoardCell(BoardCell&& cell) = default;

    BoardCell(const BoardCellIndex& index);

    BoardCell(const BoardCellIndex& index, sf::Texture* const texture);


	BoardCell(const BoardCellIndex& index, sf::Texture* const texture,
		Piece* const piece);

	~BoardCell() = default;

	inline const BoardCellIndex& GetIndex() const noexcept { return m_Index; }

	inline const Piece* const GetPiece() 
        const noexcept { return m_Piece.get(); }
	void SetPiece(Piece* const piece) noexcept;

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
  		bool operator() (const BoardCell& fCell, 
                const BoardCell& sCell) const noexcept;
	};

protected: 
	void FitPiece() noexcept(false);

protected:
	const BoardCellIndex m_Index;
    
    TexturePointer m_Texture;

	PiecePointer m_Piece{};
};