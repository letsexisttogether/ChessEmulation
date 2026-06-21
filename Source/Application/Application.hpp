#pragma once

#include <cstdint>

// Manages the scenes SetUp(), CleanUp() and Switch()
// I lied
// Who cares
// I'm the only dev of it
// I'm getting out of my mind
// I'm aaaaaaaa
// Cool
// What if anyone sees this beauty?
// Who cares?
// I don't
// Me neither
class Application final
{
public:
    static auto GetInstance() noexcept -> Application&;

    auto CarryTheBoatsAndTheLogs() noexcept -> std::int32_t;

private:
    Application() = default;
    Application(const Application&) = delete;

    ~Application() = default; 

    auto operator = (const Application&) = delete;
};
