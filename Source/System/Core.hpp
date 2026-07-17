#pragma once

#include <concepts>

namespace ASYS
{
    namespace 
    {
        template <class _Type>
        concept HasLessEqualAndGreaterEqualOperator =
        requires(_Type a, _Type b)
        {
            { a <= b } -> std::convertible_to<bool>;
            { a >= b } -> std::convertible_to<bool>;
        };

        template <class _Type>
        concept HasEqualsToOperator =
        requires(_Type a, _Type b)
        {
            { a == b } -> std::convertible_to<bool>;
        };
    };

    template <HasLessEqualAndGreaterEqualOperator _Type>
    auto IsInBounds(const _Type& value, const _Type& min,
        const _Type& max) -> bool
    {
        return min <= value && value <= max;
    }

    template <HasEqualsToOperator _Type, HasEqualsToOperator ... _Args>
    requires (_Args >= 1)
    auto AreValuedEqualTo(const _Type& value, _Args&& ... args)
    {
        return _Type 
    }
};
