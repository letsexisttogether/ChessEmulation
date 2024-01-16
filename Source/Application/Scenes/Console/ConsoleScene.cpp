#include "ConsoleScene.hpp"

#include <utility>

ConsoleScene::ConsoleScene(const std::string& name, 
    std::vector<Button>&& buttons)
    : Scene{ name, std::move(buttons) }
{} 

void ConsoleScene::UpdateLogic() noexcept(false)
{

} 

void ConsoleScene::UpdateGraphic() noexcept(false)
{
}
