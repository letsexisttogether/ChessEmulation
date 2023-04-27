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

CellIndex CellIndex::operator + (const MoveSpecs& move) const noexcept(false)
{
    const auto& distance = move.GetDistance(); 

    if (m_Value.first < distance.first || m_Value.second < distance.second)
    {
        throw std::invalid_argument{ "The MoveDirection was calculated incorrectly" };
    }

    switch (move.GetMoveDirection())
    {
    case MoveDirection::NONE:
        return (*this);

    case MoveDirection::UP:
        return { static_cast<ColumnType>(m_Value.first + distance.first), m_Value.second };
    case MoveDirection::DOWN:
        return { static_cast<ColumnType>(m_Value.first - distance.first),m_Value.second };
    case MoveDirection::RIGHT:
        return { m_Value.first, static_cast<RowType>(m_Value.second + distance.second) };
    case MoveDirection::LEFT:
        return { m_Value.first, static_cast<RowType>(m_Value.second - distance.second) };
    
    // Add the other move types when CellIndex is inserted to every place it should be at
    case MoveDirection::UP_RIGHT:
        return { static_cast<ColumnType>(m_Value.first + distance.first), 
            static_cast<RowType>(m_Value.second + distance.second ) };
    case MoveDirection::UP_LEFT:
        return { static_cast<ColumnType>(m_Value.first + distance.first), 
                static_cast<RowType>(m_Value.second - distance.second ) };
    case MoveDirection::DOWN_RIGHT:
        return { static_cast<ColumnType>(m_Value.first - distance.first),
            static_cast<RowType>(m_Value.second + distance.second) };
    case MoveDirection::DOWN_LEFT: 
        return { static_cast<ColumnType>(m_Value.first - distance.first),
            static_cast<RowType>(m_Value.second - distance.second ) };

    default:
        throw std::invalid_argument{ "Unknown MoveDirection found" };
    }
    
    return {};
}

CellIndex& CellIndex::operator += (const MoveSpecs &move) noexcept(false)
{
    return (*this = *this + move);
}
