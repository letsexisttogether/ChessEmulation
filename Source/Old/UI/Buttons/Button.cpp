#include "Button.hpp"

Button::Button(const TexturePointer texture, const Position position,
    const Delegate onClickCallBack)
    : Sprite{ texture, position }, m_CallBack{ onClickCallBack }
{}

void Button::OnInteract() noexcept(false)
{
    m_CallBack();
}

