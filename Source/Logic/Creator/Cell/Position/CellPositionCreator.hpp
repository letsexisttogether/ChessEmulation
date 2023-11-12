#pragma once

#include <SFML/System/Vector2.hpp>

#include "Logic/Creator/Consecutive/ConsecutiveCreator.hpp"

class CellPositionCreator : public ConsecutiveCreator<sf::Vector2f>
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

    CellPositionCreator& operator = (const CellPositionCreator&) = default;
    CellPositionCreator& operator = (CellPositionCreator&&) = default;

protected:
    void ChangeNextInstance() noexcept(false) override;

    bool CheckColumnBoundries() const noexcept override;
    bool CheckRowBoundries() const noexcept override;
};
