#pragma once

#include <utility>

#include "MoveDirection.hpp"

class DefaultMove
{
public:
    using File = std::int8_t;
    using Rank = std::int8_t;

    using Distance = std::pair<Rank, File>;

public:
	DefaultMove(const DefaultMove&);
	DefaultMove(DefaultMove&&) = default;

	DefaultMove(const Rank rank, const File file);

    bool IsUnderDistance(const DefaultMove& move) const noexcept;

	Distance GetDistance() const noexcept;
	
    Rank GetRank() const noexcept;
    File GetFile() const noexcept;

	~DefaultMove() = default;

	DefaultMove& operator = (const DefaultMove&) = default;
	DefaultMove& operator = (DefaultMove&&) = default;

    bool operator == (const DefaultMove& move) const noexcept;

private:
    DefaultMove() = default;

private:
    const Rank m_Rank{};
    const File m_File{};
};