#pragma once

#include "../DefaultMove.hpp"

class EnPassant : public DefaultMove
{
public:
    EnPassant() = delete;
    EnPassant(const EnPassant&) = delete;
    EnPassant(EnPassant&&) = default; 
    
    EnPassant(const MoveSpecs specs);

    virtual ~EnPassant() override = default;

    bool CheckRequirements(const Board& board, 
		const BoardCell& initial, const BoardCell& final) const noexcept(false) override;

    void HandleMove(Board& board, BoardCell& initial, BoardCell& final /* DeadBoard& deadBoard*/) 
        const noexcept override; 

    EnPassant& operator = (const EnPassant&) = delete;
	EnPassant& operator = (EnPassant&&) = delete;
};