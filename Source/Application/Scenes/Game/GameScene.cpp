#include "GameScene.hpp"
#include "Logic/Move/Moves/MoveEffect/MoveEffect.hpp"
#include "Application/Application.hpp"

#include <utility>

GameScene::GameScene(Controller* controller, Match&& match,
        ButtonsContainer&& buttons)
    : Scene{ controller }, m_Match{ std::move(match) },
    m_Buttons{ std::move(buttons) }
{}

void GameScene::UpdateLogic() noexcept(false)
{
    m_Controller->Control();

    GameObserver& gameObsever = m_Match.GetGameObserver();

    if (!gameObsever.IsMoveBeingMade())
    {
        return;
    }

    GameObserver& constGameObserver = m_Match.GetGameObserver();

    Board& board = m_Match.GetBoard();
    BoardCell& initial = *constGameObserver.GetInitial();
    BoardCell& final = *constGameObserver.GetFinal();
    
    BasicMove* move = initial.TryMove(board, final);

    if (move)
    {
        move->CompleteMove(m_Match);
    }

    gameObsever.ClearCells();

    // CheckGameState(); 
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

