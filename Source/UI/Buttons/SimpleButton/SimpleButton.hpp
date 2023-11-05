#pragma once

#include <functional>
#include <tuple>

#include "SFML/System/Vector2.hpp"
#include "UI/Buttons/Button.hpp"

template <class _Result, class... _Argc>
class SimpleButton : public Button<_Result> {
public:
    using Delegate = std::function<_Result(_Argc...)>;

public:
    SimpleButton() = delete;
    SimpleButton(const SimpleButton&) = delete;
    SimpleButton(SimpleButton&&) = delete;

    SimpleButton(const sf::Texture& texture, const sf::Vector2f& position, 
            const Delegate& delegate, _Argc... argc)
        : Button<_Result>{ texture, position }, m_Delegate{ delegate }, 
            m_Argc{ std::make_tuple(argc...) }
    {}

    ~SimpleButton() = default;

    _Result OnPress() noexcept override 
    {
        return std::apply(m_Delegate, m_Argc);
    }

    SimpleButton& operator = (const SimpleButton&) = delete;
    SimpleButton& operator = (SimpleButton&&) = delete;

private:
    Delegate m_Delegate;
    std::tuple<_Argc...> m_Argc;
};
