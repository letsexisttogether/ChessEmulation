#pragma once

class Match;

class GameMode
{
public:
    GameMode() = default;

    ~GameMode() = default;

    bool IsKingSave(const Match& match) const noexcept(false);
};
