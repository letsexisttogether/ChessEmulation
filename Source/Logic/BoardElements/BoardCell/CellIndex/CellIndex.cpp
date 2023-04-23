#include "CellIndex.hpp"

#include <stdexcept>

CellIndex::CellIndex(const ValueType& value)
    : m_Value{ value }
{}

CellIndex::CellIndex(const ColumnType& first, const RowType& second)
    : m_Value{ first, second }
{}


bool CellIndex::operator == (const CellIndex &index) const noexcept
{
    return m_Value == m_Value;
}

bool CellIndex::operator != (const CellIndex &index) const noexcept
{
    return !(*this == index);
}

CellIndex CellIndex::operator + (const DefaultMove& move) const noexcept(false)
{
    switch (const auto& distance = move.GetDistance(); move.GetMoveDirection())
    {
    case MoveDirection::UP:
        return { static_cast<ColumnType>(m_Value.first + distance.first), m_Value.second };
    case MoveDirection::DOWN:
        return { static_cast<ColumnType>(m_Value.first - distance.first),m_Value.second };
    case MoveDirection::RIGHT:
        return { m_Value.first, static_cast<RowType>(m_Value.second + distance.second) };
    case MoveDirection::LEFT:
        return { m_Value.first, static_cast<RowType>(m_Value.second - distance.second) };
    
    // Add the other move types when CellIndex is inserted to every place it should be at

    default:
        throw std::runtime_error{ "Unknown move type passed" };
    }
    
    return {};
}
