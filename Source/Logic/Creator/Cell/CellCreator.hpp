#pragma once 

#include "Graphic/TextureLoader/TextureLoader.hpp"
#include "Logic/Board/Cell/BoardCell.hpp"

class CellCreator
{
public:
    using TextureIndex = Side;
    using TextureLoader = TextureLoader<TextureIndex, std::string>;

public:
    CellCreator() = delete;
    CellCreator(const CellCreator&) = delete;
    CellCreator(CellCreator&&) = delete;

    CellCreator(const BoardCellIndex& start,
        const Side startSide,
        const BoardCellIndex& limit,
        const BoardCellIndex& step,
        TextureLoader* loader);

    ~CellCreator() = default;
    
    BoardCell CreateCell(const TextureIndex index) noexcept(false); 

    CellCreator& operator = (const CellCreator&) = delete;
    CellCreator& operator = (CellCreator&&) = delete;

private:
    void SetNextIndex() noexcept(false); 

private:
    BoardCellIndex m_NextIndex{};
    Side m_NextSide{};    

    const BoardCellIndex::File m_StartFile{};
    const BoardCellIndex m_Limit{};
    const BoardCellIndex m_Step{};

    std::unique_ptr<TextureLoader> m_TextureLoader;
};
