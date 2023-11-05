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

    SimpleButton(const Delegate& delegate, _Argc... argc)
        : m_Delegate{ delegate }, m_Argc{ std::make_tuple(argc...) }
    {}

    SimpleButton(const sf::Texture& texture, const Delegate& delegate, _Argc... argc)
        : Button<_Result>{ texture }, m_Delegate{ delegate }, 
            m_Argc{ std::make_tuple(argc...) }
    {}

    SimpleButton(const sf::Texture& texture, const sf::Vector2f& position, 
            const Delegate& delegate, _Argc... argc)
        : Button<_Result>{ texture, position }, m_Delegate{ delegate }, 
            m_Argc{ std::make_tuple(argc...) }
    {}

    ~SimpleButton() = default;

    _Result Press() noexcept override 
    {
        return std::apply(m_Delegate, m_Argc);
    }

    bool IsIntersected(const sf::Vector2i& mousePosition) const noexcept override
    {
        const sf::Vector2f& objPosition = getPosition();
        const sf::Vector2i objSize{ getTexture()->getSize() }; 

        const sf::Vector2i leftUpBorder
        {
            static_cast<std::int32_t>(objPosition.x),
            static_cast<std::int32_t>(objPosition.y)
        };
        const sf::Vector2i rightDownBorder
        { 
            leftUpBorder.x + objSize.x,
            leftUpBorder.y + objSize.y
        };

        return (mousePosition.x >= leftUpBorder.x 
                && mousePosition.x <= rightDownBorder.x
                && mousePosition.y >= leftUpBorder.y 
                && mousePosition.y <= rightDownBorder.y);
    }

    SimpleButton& operator=(const SimpleButton&) = delete;
    SimpleButton& operator=(SimpleButton&&) = delete;

private:
    Delegate m_Delegate;
    std::tuple<_Argc...> m_Argc;
};
