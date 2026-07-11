#pragma once

#include <type_traits>
#include <cstdint>

#include "Board.hpp"

enum class MoveType : std::uint8_t
{
    None,
    Side,
    Diagonal,
    Wierd
};

class Move final
{
public:
    using Rank = std::make_signed_t<CNST::Rank>;
    using File = std::make_signed_t<CNST::File>;

public:
    Move(const Move&) = delete;

    Move(const Rank rank, const File file) noexcept;

    Move(const BoardCell& fromCell, const BoardCell& toCell)
        noexcept;

    auto GetRank() const noexcept -> Rank;
    auto GetFile() const noexcept -> File;
    auto GetType() const noexcept -> MoveType;

    auto operator = (const Move&) -> Move& = delete;

private:
    auto DetermineType() const noexcept -> MoveType;

private:
    Rank m_Rank{};
    File m_File{};
    MoveType m_Type{};
};
