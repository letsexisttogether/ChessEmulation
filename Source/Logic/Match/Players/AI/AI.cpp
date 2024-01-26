#include "AI.hpp"

#include <stdexcept>

#include "Logic/Match/Match.hpp"
#include "AI.hpp"

AI::AI(Match& match, const PieceSide side, ValueMap&& map)
    : Player{ match, side }, m_ValueMap{ std::move(map) }
{}

BasicMove* AI::GetMove() noexcept(false)
{
    MiniMaxData decidedData{};

    PieceValue value = Maxi(decidedData, 1);

    if (!decidedData.Move
        || !decidedData.Initial 
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
    }

    return value;
}

AI::PieceValue AI::Maxi(MiniMaxData& data, Depth depth) 
    noexcept(false) 
{
    if (!depth)
    {
        return Evaluate(m_Side.GetSide());
    }

    PieceValue max = -10000;
    
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

            PieceValue minReturn = Mini(data, depth - 1);

            if (max < minReturn)
            {
                max = minReturn;

                data.Move = move;
                data.Initial = &initial;
                data.Final = &final;
            }

            move->UndoMove(board, initial, final);
        }
    }

    return max;
}

AI::PieceValue AI::Mini(MiniMaxData& data, const Depth depth) 
    noexcept(false)
{
    if (!depth)
    {
        return -Evaluate(m_Side.GetOppositeSide());;
    }

    PieceValue min = 10000;
    
    Board& board = m_Match.GetBoard();
    BoardObserver& observer = board.GetObserver();

    for (auto& [type, initialIndex]: 
        observer.GetIndices(m_Side.GetOppositeSide()))
    {
        BoardCell& initial = board[initialIndex];

        for (auto& [move, finalIndex]: initial.GetLegalMoves(board))
        {
            BoardCell& final = board[finalIndex];

            move->DoMove(board, initial, final);

            PieceValue maxReturn = Maxi(data, depth - 1);

            min = std::min(min, maxReturn);

            move->UndoMove(board, initial, final);
        }
    }

    return min;
}
