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
	DefaultMove() = delete;
	DefaultMove(const DefaultMove&) = default;
	DefaultMove(DefaultMove&&) = default;

	DefaultMove(const Rank rank, const File file);

	Distance GetDistance() const noexcept;
	
    Rank GetRank() const noexcept;
    File GetFile() const noexcept;

	~DefaultMove() = default;

	DefaultMove& operator = (const DefaultMove&) = default;
	DefaultMove& operator = (DefaultMove&&) = default;

    bool operator == (const DefaultMove& move) const noexcept;

    bool operator >= (const DefaultMove& move) const noexcept;
    bool operator <= (const DefaultMove& move) const noexcept;

private:
    const Rank m_Rank;
    const File m_File;
};