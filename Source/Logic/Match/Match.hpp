#pragma once 

#include <memory>

#include "Control/Controller.hpp"
#include "Logic/Board/Board.hpp"

class Match
{
public:
    using ControllerPointer = std::shared_ptr<Controller>;

public:
    Match() = delete;
    Match(const Match&) = delete;
    Match(Match&&) = delete;

    // C_tor();

    ~Match() = default;

private:
    Board m_Board{};  
    ControllerPointer m_Controller{};    
    Side m_CurrentSide{};

    // const Timer m_Timer;
};
