#pragma once

#include <functional>

#include "SFML/System/Vector2.hpp"
#include "UI/Buttons/Button.hpp"

template<class _Result, class ... _Argc>
class SimpleButton : public Button
{
public: 
    using Delegate = std::function<_Result(_Argc...)>;

public:
    SimpleButton() = delete;
    SimpleButton(const SimpleButton&) = delete;
    SimpleButton(SimpleButton&&) = delete;

    SimpleButton(const sf::Texture& texture, const Delegate& delegate)
        : Button{ texture }, m_Delegate{ delegate }
    {}
    SimpleButton(const sf::Texture& texture, Delegate&& delegate)
        : Button{ texture }, m_Delegate{ std::move(delegate) }
    {}

    ~SimpleButton() = default;

    void Press() noexcept override
    {
        m_Delegate();
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
    
    SimpleButton& operator = (const SimpleButton&) = delete;
    SimpleButton& operator = (SimpleButton&&) = delete;

private:
    Delegate m_Delegate;
};
