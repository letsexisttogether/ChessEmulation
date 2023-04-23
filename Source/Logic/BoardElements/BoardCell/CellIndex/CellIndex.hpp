#pragma once

#include <utility>

#include "Logic/PieceElements/Move/DefaultMove/DefaultMove.hpp"

class CellIndex
{
public:
    using ColumnType = std::uint8_t;
    using RowType = char;
    using ValueType = std::pair<ColumnType, RowType>;
    
public:
    CellIndex() = default;
    CellIndex(const CellIndex&) = default;
    
    CellIndex(const ValueType& value);
    CellIndex(const ColumnType& first, const RowType& second);

    ~CellIndex() = default;

    inline const RowType GetHorizontal() const noexcept { return m_Value.first; }

    inline const ColumnType GetVertical() const noexcept { return m_Value.second; }

    CellIndex& operator = (const CellIndex&) = default;
    CellIndex& operator = (CellIndex&&) = default;

    bool operator == (const CellIndex& index) const noexcept;
    bool operator != (const CellIndex& index) const noexcept;

    // Exceptions allowed for tests
    CellIndex operator + (const DefaultMove& move) const noexcept(false);
    
private: 
    ValueType m_Value{};
};
