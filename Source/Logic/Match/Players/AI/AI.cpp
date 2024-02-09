#include "AI.hpp"

#include <iostream>
#include <stdexcept>

#include "Logic/Match/Match.hpp"
#include "AI.hpp"

AI::AI(Match& match, const PieceSide side, ValueMap&& map)
    : Player{ match, side }, m_ValueMap{ std::move(map) }
{
    m_PositionValueMap.emplace(PieceType::PAWN, 
            std::make_pair(BoardCellIndex{ 1, 5 }, 4));
    m_PositionValueMap.emplace(PieceType::PAWN, 
            std::make_pair(BoardCellIndex{ 8, 5 }, 4));
    m_PositionValueMap.emplace(PieceType::PAWN, 
            std::make_pair(BoardCellIndex{ 5, 2 }, 10));
    m_PositionValueMap.emplace(PieceType::PAWN, 
            std::make_pair(BoardCellIndex{ 4, 5 }, 10));
    m_PositionValueMap.emplace(PieceType::PAWN, 
            std::make_pair(BoardCellIndex{ 3, 3 }, 5));
    m_PositionValueMap.emplace(PieceType::PAWN, 
            std::make_pair(BoardCellIndex{ 6, 3 }, 5));

    m_PositionValueMap.emplace(PieceType::ROOK, 
            std::make_pair(BoardCellIndex{ 0, 4 }, 5));
    m_PositionValueMap.emplace(PieceType::ROOK, 
            std::make_pair(BoardCellIndex{ 8, 4 }, 5));
    m_PositionValueMap.emplace(PieceType::ROOK, 
            std::make_pair(BoardCellIndex{ 4, 4 }, 4));

    m_PositionValueMap.emplace(PieceType::ROOK, 
            std::make_pair(BoardCellIndex{ 3, 4 }, 7));
    m_PositionValueMap.emplace(PieceType::ROOK, 
            std::make_pair(BoardCellIndex{ 3, 3 }, 7));
    m_PositionValueMap.emplace(PieceType::ROOK, 
            std::make_pair(BoardCellIndex{ 5, 2 }, 7));

    m_PositionValueMap.emplace(PieceType::BISHOP, 
            std::make_pair(BoardCellIndex{ 8, 4 }, 10));
    m_PositionValueMap.emplace(PieceType::BISHOP, 
            std::make_pair(BoardCellIndex{ 7, 3 }, 10));
    m_PositionValueMap.emplace(PieceType::BISHOP, 
            std::make_pair(BoardCellIndex{ 1, 5 }, 10));
    m_PositionValueMap.emplace(PieceType::BISHOP, 
            std::make_pair(BoardCellIndex{ 8, 6 }, 10));

    m_PositionValueMap.emplace(PieceType::QUEEN, 
            std::make_pair(BoardCellIndex{ 2, 4 }, 8));
    m_PositionValueMap.emplace(PieceType::BISHOP, 
            std::make_pair(BoardCellIndex{ 4, 4 }, 8));
    m_PositionValueMap.emplace(PieceType::BISHOP, 
            std::make_pair(BoardCellIndex{ 6, 5 }, 8));
    m_PositionValueMap.emplace(PieceType::BISHOP, 
            std::make_pair(BoardCellIndex{ 8, 6 }, 8));
}

BasicMove* AI::GetMove() noexcept(false)
{
    MiniMaxData decidedData{};

    PieceValue value = Maxi(decidedData, 3, -100000, 100000);

    if (!decidedData.Move || !decidedData.Initial 
        || !decidedData.Final)
    {
        throw std::runtime_error{ "AI: Cannot find a move" };
    }

    GameObserver& observer = m_Match.GetGameObserver();
    observer.SetCell(decidedData.Initial);
    observer.SetCell(decidedData.Final); 

    return decidedData.Move;
}

AI::PieceValue AI::Evaluate(const PieceSide side) noexcept(false)
{
    PieceValue value = 0;

    Board& board = m_Match.GetBoard();
    BoardObserver& observer = board.GetObserver();

    for (auto& [type, index]: observer.GetIndices(side))
    {
        value += m_ValueMap[type];

        for (auto& [mapType, positionValue] : m_PositionValueMap)
        {
            if (type == mapType && index == positionValue.first)
            {
                value += positionValue.second;
            }
        }
    }

    return value;
}

AI::PieceValue AI::Maxi(MiniMaxData& data, const Depth depth, 
    PieceValue alpha, PieceValue beta) noexcept(false) 
{
    if (!depth)
    {
        return Evaluate(m_Side.GetSide());
    }

    PieceValue max = -100000;
    
    Board& board = m_Match.GetBoard();
    BoardObserver& observer = board.GetObserver();

    for (auto& [type, initialIndex]: observer
        .GetIndices(m_Side.GetSide()))
    {
        BoardCell& initial = board[initialIndex];

        for (auto& [move, finalIndex]: initial.GetLegalMoves(board))
        {
            BoardCell& final = board[finalIndex];

            move->DoMove(board, initial, final);

            PieceValue minReturn = Mini(data, depth - 1, alpha, beta);

            if (max < minReturn)
            {
                max = minReturn;

                data.Move = move;
                data.Initial = &initial;
                data.Final = &final;
            }

            move->UndoMove(board, initial, final);

            alpha = std::max(alpha, max);

            if (alpha >= beta)
            {
                break; 
            }
        }
    }

    return max;
}

AI::PieceValue AI::Mini(MiniMaxData& data, const Depth depth, 
    PieceValue alpha, PieceValue beta) noexcept(false)
{
    if (!depth)
    {
        return -Evaluate(m_Side.GetOppositeSide());
    }

    PieceValue min = 100000;
    
    Board& board = m_Match.GetBoard();
    BoardObserver& observer = board.GetObserver();

    for (auto& [type, initialIndex]: observer
        .GetIndices(m_Side.GetOppositeSide()))
    {
        BoardCell& initial = board[initialIndex];

        for (auto& [move, finalIndex]: initial.GetLegalMoves(board))
        {
            BoardCell& final = board[finalIndex];

            move->DoMove(board, initial, final);

            PieceValue maxReturn = Maxi(data, depth - 1, alpha, beta);

            min = std::min(min, maxReturn);

            move->UndoMove(board, initial, final);

            beta = std::min(beta, min);

            if (beta <= alpha)
            {
                break; 
            }
        }
    }

    return min;
}
