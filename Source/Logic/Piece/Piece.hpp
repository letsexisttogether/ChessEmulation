#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <vector>

#include "Graphic/Drawable/Drawable.hpp"
#include "Logic/Move/BasicMove.hpp"
#include "Type/PieceType.hpp"
#include "Side/PieceSide.hpp"

class Piece : public Drawable
{
public:
    using MovePointer = std::unique_ptr<BasicMove>;

    using InMovesContainer = std::vector<BasicMove*>;
    using MovesContainer = std::vector<MovePointer>;

public:
	Piece() = default;
	Piece(const Piece& piece);
	Piece(Piece&& piece);

    Piece(const PieceSide side, const PieceType type,
        const InMovesContainer& moves);

    Piece(const PieceSide side, const PieceType type, 
        const TexturePointer texture,
        const InMovesContainer& moves = {},
        const Position position = Position{});

	virtual ~Piece() = default;

    MovesContainer& GetMoves() noexcept;
    const MovesContainer& GetMoves() const noexcept;

	inline const PieceSide GetSide() const noexcept { return m_Side; }
    inline const PieceType GetType() const noexcept { return m_Type; }

    bool WasMoved() const noexcept;
    void SetWasMoved(const bool wasMoved) noexcept;
	
	Piece& operator = (const Piece& piece);
	Piece& operator = (Piece&& piece);

private:
	PieceSide m_Side{};
    PieceType m_Type{};

    bool m_WasMoved{};
    MovesContainer m_Moves{};

};

