#include "AI.hpp"

#include "Logic/Match/Match.hpp"
#include "AI.hpp"

#include <iostream>

AI::AI(Match& match, const PieceSide side, ValueMap&& map)
    : Player{ match, side }, m_ValueMap{ std::move(map) }
{}

BasicMove* AI::GetMove() noexcept(false)
{
    MiniMaxData decidedData{};

    PieceValue value = Maxi(decidedData, 1);

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

AI::PieceValue AI::Maxi(MiniMaxData& data, Depth depth) 
    noexcept(false) 
{
    std::cout << "\n\nMAXI ENTERED\n\n" << std::endl;
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

            PieceValue minReturn = Mini(data, depth - 1);

            std::cout << "MAXI: TRY TO UNDO THE MOVE\n";

            if (max < minReturn)
            {
                max = minReturn;

                data.Move = move;
                data.Initial = &initial;
                data.Final = &final;
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

AI::PieceValue AI::Mini(MiniMaxData& data, const Depth depth) 
    noexcept(false)
{
    std::cout << "\n\nMINI ENTERED\n\n" << std::endl;
    if (!depth)
    {
        std::cout << "MINI: return\n";

        return -Evaluate(m_Side.GetOppositeSide());;
    }

    PieceValue min = 10000;
    
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

            std::cout << "We called maxi\n";
            PieceValue maxReturn = Maxi(data, depth - 1);

            min = std::min(min, maxReturn);

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
