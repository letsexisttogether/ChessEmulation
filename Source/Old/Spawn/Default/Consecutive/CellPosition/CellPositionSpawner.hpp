#pragma once

#include <SFML/System/Vector2.hpp>

#include "Spawn/Default/Consecutive/ConsecutiveSpawner.hpp"
#include "Graphic/Drawable/Drawable.hpp"

class CellPositionSpawner : public ConsecutiveSpawner<sf::Vector2f>
{
public:
    using Position = Drawable::Position; 

    using Super = ConsecutiveSpawner<Position>;

public:
    CellPositionSpawner() = delete;
    CellPositionSpawner(const CellPositionSpawner&) = default;
    CellPositionSpawner(CellPositionSpawner&&) = default;

    CellPositionSpawner(const Position& start, const Position& step,
            const Position& lowest, const Position& highest);

    ~CellPositionSpawner() = default;

    CellPositionSpawner& operator = (const CellPositionSpawner&) = delete;
    CellPositionSpawner& operator = (CellPositionSpawner&&) = delete;

protected:
    void ChangeNextInstance() noexcept(false) override;

    bool CheckColumnBoundries() const noexcept override;
    bool CheckRowBoundries() const noexcept override;
};
