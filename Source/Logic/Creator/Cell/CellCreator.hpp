#pragma once 

#include "Logic/Board/Cell/BoardCell.hpp"

class CellCreator
{
public:
    using TextureIndex = Side;

public:
    CellCreator() = delete;
    CellCreator(const CellCreator&) = delete;
    CellCreator(CellCreator&&) = delete;

    CellCreator(const BoardCellIndex& start, 
            const BoardCellIndex::Rank limitRank, 
            const BoardCellIndex::File limitFile,
            const BoardCellIndex::File fileStep,
            const BoardCellIndex::Rank rankStep);

    ~CellCreator() = default;
    
    BoardCell CreateCell(const TextureIndex index) noexcept(false); 

    CellCreator& operator = (const CellCreator&) = delete;
    CellCreator& operator = (CellCreator&&) = delete;

private:
    void SetNextIndex() noexcept(false); 

private:
    BoardCellIndex m_NextIndex{};
    const BoardCellIndex::File m_StartFile{};
    const BoardCellIndex::Rank m_LimitRank{};
    const BoardCellIndex::File m_LimitFile{};

    const BoardCellIndex::File m_FileStep{};
    const BoardCellIndex::Rank m_RankStep{};

    // std::unique_ptr<TexureLoader<TextureIndex>> m_TextureLoader;
};
