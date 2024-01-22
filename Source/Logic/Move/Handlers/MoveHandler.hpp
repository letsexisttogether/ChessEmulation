#pragma once 

class Board;
class GameObserver;

class MoveHandler
{
public:
    MoveHandler() = default;

    virtual ~MoveHandler() = default;

    virtual void Handle(Board& board, GameObserver& gameObsever)
        const noexcept(false) = 0;
};
