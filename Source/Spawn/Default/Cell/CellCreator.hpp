#pragma once 

#include <SFML/Graphics/Texture.hpp>

#include "Spawn/Associative/AssociativeSpawner.hpp"
#include "Spawn/Default/DefaultSpawner.hpp"

#include "Logic/Board/Cell/BoardCell.hpp"
#include "Logic/PieceElements/Piece/Side/SideHolder/PieceSideHolder.hpp"

class CellCreator : public DefaultSpawner<BoardCell>
{
public:
    using IndexSpawner = DefaultSpawner<BoardCellIndex>;
    using PositionCreator = DefaultSpawner<sf::Vector2f>;

    using TextureLoader = AssociativeSpawner<PieceSide, sf::Texture*>;

public:
    CellCreator() = delete;
    CellCreator(const CellCreator&) = delete;
    CellCreator(CellCreator&&) = delete;

    CellCreator(const PieceSideHolder& sideHolder,
        IndexSpawner* indexCreator, 
        PositionCreator* positionCreator,
        TextureLoader* loader);

    ~CellCreator() = default;
    
    BoardCell GetInstance() noexcept(false) override; 

    CellCreator& operator = (const CellCreator&) = delete;
    CellCreator& operator = (CellCreator&&) = delete;

private:
    PieceSideHolder m_SideHolder;
    std::unique_ptr<IndexSpawner> m_IndexCreator;
    std::unique_ptr<PositionCreator> m_PositionCreator;
    std::unique_ptr<TextureLoader> m_TextureLoader;
};
