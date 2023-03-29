#pragma once

#include <SFML/Graphics.hpp>

#include "Side.hpp"

class Piece : public sf::Drawable
{
public:
	Piece() = delete;
	Piece(const Piece&) = delete;
	Piece(Piece&&) = delete;

	Piece(const sf::Texture& texture, Side side);

	virtual ~Piece() = default;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	inline const sf::Vector2f& GetScreenPosition() const noexcept { return m_Sprite.getPosition(); }
	void SetScreenPosition(const sf::Vector2f& position) noexcept;

	inline const Side& GetSide() const noexcept { return m_Side; }
	inline const sf::Vector2u& GetSize() const noexcept { return m_Sprite.getTexture()->getSize(); }
	
	Piece& operator = (const Piece&) = delete;
	Piece& operator = (Piece&&) = delete;
	
private:
	Side m_Side{};
	sf::Sprite m_Sprite{};
};


// TODO:
// Проверить, может ли фигура так двигаться, если нет - аборт 
// bool DoesHaveMove(const Move& possilbeMove)
// {
//		for (const auto& [move, distance] : m_PossibleMoves)
//		{
//			if (possibleMove.first == possilbeMove.first && distance >= possilbeMove.distance)
//			{
//				return true;
//			}
//		}
// 
//		return false;
// }
// 
// Проверить, пустой ли путь, если нет - аборт
// 
// bool IsPathClear(const BoardCell& start, const BoardCell& end, const Direction direction)
// {
//		for (auto boardCell = startBoard; boardCell != end; boardCell = MoveNext(boardCell, direction)
//		{
//			if (!boardCell.IsFree())
//			{
//				return false;
//			}
//		}
// 
//		return true;
// }
// Проверить, кто стоит в конце, если пусто - перемещаем фигуру, если занято чужой фигурой - атакуем, если занято своей фигурой - аборт
// void MakeFinalMove(const std::shared_ptr<Piece> piece, const BoardCell& cell)
// {
//		if (boardCell.IsFree())
//		{
//			piece->Move(cell);
//		}		
//		else if (piece->GetColor() != cell.GetPiece()->GetColor)
//		{
//			piece.Attack(piece);
//		}
// 
// }
// 
// 