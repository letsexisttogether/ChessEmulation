#pragma once

#include <cstdint>
#include <type_traits>

#include "../Core.hpp"

GraphicsSpaceStart

/**
* @brief Enumeration with all possible UI interaction
*
* @details It'll be changed to collection 
* of enums (enum classes) in the future
*/
enum InteractionEvent : std::uint8_t
{
    None,
    Hover,
    // TODO #3: Change to OnClick, OnRelease later 
    OnClick,
};

class Interactable
{
public:
    using IEUnderType 
        = std::underlying_type_t<InteractionEvent>;

public:
    Interactable() = default;
    Interactable(const Interactable&) = default;
    Interactable(Interactable&&) = default;

    Interactable(const InteractionEvent interactions) noexcept;
    Interactable(const IEUnderType interactions) noexcept;

    virtual ~Interactable() = default;

    virtual void Interact(const InteractionEvent interactions)
        noexcept(false);

    bool AreInteractionsSupported(const InteractionEvent interactions)
        noexcept;

    InteractionEvent GetInteractions() const noexcept;

    Interactable& operator = (const Interactable&) = default;
    Interactable& operator = (Interactable&&) = default;

protected:
    InteractionEvent m_Interactions{};
};

GraphicsSpaceEnd
