#pragma once 

#include <functional>

#include "Graphic/Sprite/Sprite.hpp"

class Button : public Sprite
{
public:
    using Delegate = std::function<void()>;

public:
    Button() = default;
    Button(const Button&) = default;
    Button(Button&&) = default;

    Button(const TexturePointer texture, const Position position,
        const Delegate onClickCallBack);

    virtual ~Button() = default;

    void OnInteract() noexcept(false) override;

private:
    Delegate m_CallBack;
};
