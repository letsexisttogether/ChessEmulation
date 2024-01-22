#include "GameScene.hpp"
#include "Logic/Move/Moves/MoveEffect/MoveEffect.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>

GameScene::GameScene(Controller* controller, Match&& match,
        MoveHandlers&& handlers,
        ButtonsContainer&& buttons)
    : Scene{ controller }, m_Match{ std::move(match) },
    m_Handlers{ std::move(handlers) }, m_Buttons{ std::move(buttons) }
{
    Board& board = m_Match.GetBoard();

    AddDrawable(&board);

    for (const BoardCell& cell : board.GetCells())
    {        
        BoardCell& cellRef = const_cast<BoardCell&>(cell);
        AddIntersectable(&cellRef);

        std::cout << cellRef.GetOrigin().x << ' ' << cellRef.GetOrigin().y << '\n';

        if (!cell.IsFree())
        {
            std::cout << "Found a piece" << '\n';
            Piece& piece = cellRef.GetPiece();
    
            AddDrawable(&piece);
        }
    }

    for (Button& button : m_Buttons)
    {
        AddIntersectable(&button);
        AddDrawable(&button);
    }

    // This should go the last
    AddDrawable(controller);
}

Match& GameScene::GetMatch() noexcept
{
    return m_Match;
}

const Match& GameScene::GetMatch() const noexcept
{
    return m_Match;
}

void GameScene::UpdateLogic() noexcept(false)
{
    m_Controller->Control();

    GameObserver& gameObsever = m_Match.GetGameObserver();

    if (!gameObsever.IsMoveBeingMade())
    {
        return;
    }

   const MoveEffect moveEffect =
        gameObsever.GetCellPair().first->GetPiece().TryMove(m_Match);

    if (moveEffect == MoveEffect::NONE)
    {
        gameObsever.ClearCells();
        return;
    }

    const MoveHandler& handler = GetHandler(moveEffect);
    handler.Handle(m_Match.GetBoard(), m_Match.GetGameObserver());
    
    gameObsever.ClearCells();

    // CheckGameState(); 
}


const MoveHandler& GameScene::GetHandler(const MoveEffect effect) 
    const noexcept(false)
{
    const auto& iter = m_Handlers.find(effect);

    if (iter == m_Handlers.end())
    {
        throw std::runtime_error{ "There's no such a handler for this move" };
    }

    return *iter->second;
}
