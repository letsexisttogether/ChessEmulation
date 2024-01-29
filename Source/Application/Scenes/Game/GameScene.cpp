#include "GameScene.hpp"

#include <iostream>
#include <utility>

#include "Application/Application.hpp"

GameScene::GameScene(Controller* controller, Match&& match,
        ButtonsContainer&& buttons)
    : Scene{ controller }, m_Match{ std::move(match) },
    m_Buttons{ std::move(buttons) }
{}

void GameScene::UpdateLogic() noexcept(false)
{
    m_Controller->Control();

    BasicMove* move = m_Match.GetCurrentPlayer().GetMove();

    if (move)
    {
        std::cout << "I decide to move\n";

        move->CompleteMove(m_Match);

        std::cout << "We moved successfuly";        

        CheckGameState(); 
    }
}

Scene::IntersectablesContainer GameScene::GetIntersectables() 
    const noexcept 
{
    IntersectablesContainer intersectables{};

    for (const BoardCell& cell : m_Match.GetBoard().GetCells())
    { 
        BoardCell& cellRef = const_cast<BoardCell&>(cell);
        intersectables.push_back(&cellRef);
    }

    for (const Button& button : m_Buttons)
    {
        Button& buttonRef = const_cast<Button&>(button);
        intersectables.push_back(&buttonRef); 
    }

    return intersectables;
}

Scene::DrawablesContainer GameScene::GetDrawables() 
    const noexcept
{
    DrawablesContainer drawables{};

    const Board& board = m_Match.GetBoard();

    drawables.push_back(&board);

    for (const BoardCell& cell : board.GetCells())
    { 
        if (!cell.IsFree())
        {
            const Piece& piece = cell.GetPiece();

            drawables.push_back(&piece);
        }
    }

    for (const Button& button : m_Buttons)
    {
        drawables.push_back(&button);
    }

    drawables.push_back(m_Controller.get());

    return drawables;
}

Match& GameScene::GetMatch() noexcept
{
    return m_Match;
}

const Match& GameScene::GetMatch() const noexcept
{
    return m_Match;
}

void GameScene::CheckGameState() noexcept(false)
{
    const PieceSide& side = m_Match.GetTurnSide().GetSide();

    Board& board = m_Match.GetBoard();

    const bool isKingSave = board.IsKingSafe(side);

    if (!isKingSave)
    {
        if (true)
        {
            std::cout << "The game is over\n"
                << "THE " << ((side == PieceSide::WHITE) ?
                ("BLACK") : ("WHITE")) << " WINS" << std::endl;

            SetWorking(false);
        }
    }
}
