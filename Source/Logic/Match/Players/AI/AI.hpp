#pragma once

#include "Logic/Match/Players/Player.hpp"
#include "Logic/Piece/Type/PieceType.hpp"

#include <cstdint>
#include <unordered_map>
#include <utility>

class BoardCell;
class BoardCellIndex;

class AI: public Player
{
public:
    using PieceValue = std::int32_t;
    using ValueMap = std::unordered_map<PieceType, PieceValue>;
    using PositionValueMap = std::unordered_multimap<PieceType, 
        std::pair<BoardCellIndex, PieceValue>>;

private:
    using Depth = std::int32_t;
    using MoveTuple = std::tuple<BasicMove*, PieceValue, 
        BoardCellIndex, BoardCellIndex>;

public:
    AI() = delete;
    AI(const AI&) = default;
    AI(AI&&) = default;
    
    AI(Match& match, const PieceSide side, ValueMap&& map);

    ~AI() = default;

    BasicMove* GetMove() noexcept(false);

private:
    struct MiniMaxData
    {
        BasicMove* Move;
        BoardCell* Initial;
        BoardCell* Final;
    };

private:
    AI::PieceValue Evaluate(const PieceSide side) noexcept(false);

    PieceValue Maxi(MiniMaxData& data, const Depth depth, 
        PieceValue alpha, PieceValue beta)  noexcept(false);
    PieceValue Mini(MiniMaxData& data, const Depth depth, 
        PieceValue alpha, PieceValue beta)noexcept(false);

private:
    ValueMap m_ValueMap;
    PositionValueMap m_PositionValueMap;
};
