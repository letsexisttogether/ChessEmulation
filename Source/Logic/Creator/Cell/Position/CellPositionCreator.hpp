#pragma once

#include <SFML/System/Vector2.hpp>

#include "Spawn/Default/Consecutive/ConsecutiveCreator.hpp"

class CellPositionCreator : public ConsecutiveSpawner<sf::Vector2f>
{
public:
    using Position = sf::Vector2f;

public:
    CellPositionCreator() = delete;
    CellPositionCreator(const CellPositionCreator&) = default;
    CellPositionCreator(CellPositionCreator&&) = default;

    CellPositionCreator(const Position& start, const Position& step,
            const Position& lowest, const Position& highest);

    ~CellPositionCreator() = default;

    CellPositionCreator& operator = (const CellPositionCreator&) = delete;
    CellPositionCreator& operator = (CellPositionCreator&&) = delete;

protected:
    void ChangeNextInstance() noexcept(false) override;

    bool CheckColumnBoundries() const noexcept override;
    bool CheckRowBoundries() const noexcept override;
};
