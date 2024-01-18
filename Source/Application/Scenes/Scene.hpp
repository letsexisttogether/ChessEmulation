#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <string>

#include "UI/Buttons/Button.hpp"

class Scene 
{
// public:
    // using ButtonPointer = std::unique_ptr<Button>;

public:
    Scene(const std::string& name, std::vector<Button>&& buttons);
    
    virtual ~Scene() = default;

    virtual void UpdateLogic() noexcept(false) = 0;

    virtual void UpdateGraphic() noexcept(false) = 0;

    void ActivateButton(const std::size_t buttonIndex) noexcept(false);
    
    const std::string& GetName() const noexcept;

    bool IsWorking() const noexcept;
    void SetWorking(const bool isWorking) noexcept;

// Change some of the fields to private
protected:
    const std::string m_Name;

    bool m_IsWorking{ true };
    std::vector<Button> m_Buttons;
};
