#include "AI.hpp"

#include "Logic/Match/Match.hpp"
#include "AI.hpp"

#include <iostream>

AI::AI(Match& match, const PieceSide side, ValueMap&& map)
    : Player{ match, side }, m_ValueMap{ std::move(map) }
{}

BasicMove* AI::GetMove() noexcept(false)
{
    MiniMaxData decidedData = Maxi({}, 3);

    std::cout << "We got to return";

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

    std::cout << "I EVALUATE\n";

    for (const auto& [type, index]: 
        observer.GetIndices(side))
    {
        value += m_ValueMap[type];
    }

    std::cout << "I STOP EVALUATE";

    return value;
}

AI::MiniMaxData AI::Maxi(MiniMaxData data, Depth depth) 
    noexcept(false) 
{
    std::cout << "\n\nMAXI ENTERED\n\n" << std::endl;
    if (!depth)
    {
        data.Value = Evaluate(m_Side.GetSide()); 

        std::cout << "MAXI return\n";

        return data;
    }

    data.Value = -10000;
    MiniMaxData max = data;
    
    Board& board = m_Match.GetBoard();
    BoardObserver& observer = board.GetObserver();

    for (auto& [type, initialIndex]: observer
            .GetIndices(m_Side.GetSide()))
    {
        std::cout << "I TRY TO GET THE INDEX";

        BoardCell& initial = board[initialIndex];

        std::cout << "I TRY GOT THE INDEX";

        auto moves = initial.GetLegalMoves(board);

        for (auto& [move, finalIndex]: moves)
        {
            std::cout << "We entered moves check\n";

            BoardCell& final = board[finalIndex];

            std::cout << "MAXI: GOT FINAL INDEX\n";

            move->DoMove(board, initial, final);

            std::cout << "MAXI: MADE A MOVE\n";

            MiniMaxData miniData
            {
                move, 0, &initial, &final
            };

            MiniMaxData minReturn = Mini(miniData, depth - 1);

            std::cout << "MAXI: TRY TO UNDO THE MOVE\n";

            if (max.Value < minReturn.Value)
            {
                max = miniData;
                max.Value = minReturn.Value;
            }

            move->UndoMove(board, initial, final);
            
            std::cout << "MAXI TYPE IS "
                << static_cast<std::int32_t>(initial.GetPiece().GetType()) << '\n';

            std::cout << "MAXI: WE UNDO THE MOVE\n";
        }
    }

    std::cout << "MAXI: return\n";

    return max;
}

AI::MiniMaxData AI::Mini(MiniMaxData data, Depth depth) 
    noexcept(false)
{
    std::cout << "\n\nMINI ENTERED\n\n" << std::endl;
    if (!depth)
    {
        data.Value = -Evaluate(m_Side.GetOppositeSide()); 

        std::cout << "MINI: return\n";

        return data;
    }

    MiniMaxData min = data;
    min.Value = 10000;
    
    Board& board = m_Match.GetBoard();
    BoardObserver& observer = board.GetObserver();

    auto& indices = observer.GetIndices(m_Side.GetOppositeSide());

    for (auto& [type, initialIndex]: indices)
    {
        std::cout << "I TRY TO GET THE INDEX";

        BoardCell& initial = board[initialIndex];

        std::cout << "I TRY GOT THE INDEX";

        for (auto& [move, finalIndex]: initial.GetLegalMoves(board))
        {
            BoardCell& final = board[finalIndex];

            std::cout << "MINI: TRY TO MAKE A MOVE \n";

            move->DoMove(board, initial, final);

            std::cout << "MINI: MADE A MOVE\n";

            MiniMaxData maxiData
            {
                move, 0, &initial, &final
            };

            std::cout << "We called maxi\n";
            MiniMaxData maxReturn = Maxi(maxiData, depth - 1);

            if (min.Value > maxReturn.Value)
            {
                min = maxiData;
                min.Value = maxReturn.Value;
            }

            std::cout << "MINI: TRY TO UNDO THE MOVE\n";
            move->UndoMove(board, initial, final);

            std::cout << "MAXI TYPE IS "
                << static_cast<std::int32_t>(initial.GetPiece().GetType()) << '\n';

            std::cout << "MINI: UNDO THE MOVE\n";
        }
    }

    std::cout << "MINI: return\n";

    return min;
}
