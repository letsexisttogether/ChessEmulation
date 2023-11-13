#pragma once 

#include "Graphic/TextureLoader/TextureLoader.hpp"
#include "Logic/Board/Cell/BoardCell.hpp"
#include "Logic/Creator/Consecutive/ConsecutiveCreator.hpp"
#include "Logic/PieceElements/Piece/Side/SideHolder/PieceSideHolder.hpp"

class CellCreator
{
public:
    using TextureIndex = PieceSide;
    using TextureLoader = TextureLoader<TextureIndex, std::string>;

    using IndexCreator = ConsecutiveCreator<BoardCellIndex>;
    using PositionCreator = ConsecutiveCreator<sf::Vector2f>;

public:
    CellCreator() = delete;
    CellCreator(const CellCreator&) = delete;
    CellCreator(CellCreator&&) = delete;

    CellCreator(const PieceSideHolder& sideHolder,
        IndexCreator* indexCreator, 
        PositionCreator* positionCreator,
        TextureLoader* loader);

    ~CellCreator() = default;
    
    BoardCell CreateCell(const TextureIndex index) noexcept(false); 

    CellCreator& operator = (const CellCreator&) = delete;
    CellCreator& operator = (CellCreator&&) = delete;

private:
    PieceSideHolder m_SideHolder;
    std::unique_ptr<IndexCreator> m_IndexCreator;
    std::unique_ptr<PositionCreator> m_PositionCreator;
    std::unique_ptr<TextureLoader> m_TextureLoader;
};
