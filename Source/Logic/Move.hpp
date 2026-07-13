#pragma once

#include <tuple>
#include <type_traits>
#include <cstdint>

#include "Board.hpp"

/**
* @details For now MoveType and AttackType is packed into one thing 
*/
enum class MoveType : std::uint8_t
{
    None        = 0x0,
    Side        = 0x1,
    Diagonal    = 0x2,
    Wierd       = 0x4,
};

class Move final
{
public:
    using Rank = std::make_signed_t<CNST::Rank>;
    using File = std::make_signed_t<CNST::File>;

public:
    Move(const Move&) = default;

    Move(const Board& board, const BoardCell& fromCell,
        const BoardCell& toCell) noexcept;

    auto GetRank() const noexcept -> Rank;
    auto GetFile() const noexcept -> File;

    auto GetType() const noexcept -> MoveType;
    auto IsAttacking() const noexcept -> bool;

    auto AsPack() const noexcept -> std::tuple<Rank, File, MoveType, bool>;

    auto operator = (const Move&) -> Move& = default;

    explicit operator bool () const noexcept;

private:
    Rank m_Rank{};
    File m_File{};
    MoveType m_Type{};
    bool m_IsAttacking{};
};
