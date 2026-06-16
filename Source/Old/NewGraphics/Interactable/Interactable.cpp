#include "Interactable.hpp"

GraphicsSpaceStart

Interactable::Interactable(const InteractionEvent interactions) noexcept
    : m_Interactions{ interactions }
{}

Interactable::Interactable(const IEUnderType interactions) noexcept
    : m_Interactions{ static_cast<InteractionEvent>(interactions) }
{}

void Interactable::Interact(const InteractionEvent interactions)
    noexcept(false)
{
}

bool Interactable::AreInteractionsSupported
    (const InteractionEvent interactions) noexcept
{
    return m_Interactions & interactions;
}

InteractionEvent Interactable::GetInteractions() const noexcept
{
    return m_Interactions;
}

GraphicsSpaceEnd
