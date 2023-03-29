#include "BoardCell.hpp"

BoardCell::BoardCell(const std::pair<uint8_t, char> index, std::shared_ptr<sf::Texture> texture, const std::shared_ptr<Piece> piece)
	: m_Index{ index }, m_Texture{ texture }, m_Piece{ piece }
{}
