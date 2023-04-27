#pragma once

#include "../DefaultMove.hpp"

class Castling : public DefaultMove
{
public:
    Castling() = delete;
    Castling(const Castling&) = delete;
    Castling(Castling&&) = default; 
    
    Castling(const MoveSpecs specs);

    virtual ~Castling() override = default;

    bool CheckRequirements(const Board& board, 
		const BoardCell& initial, const BoardCell& final) const noexcept(false) override;

    void HandleMove(Board& board, BoardCell& initial, BoardCell& final /* DeadBoard& deadBoard*/) 
        const noexcept override; 

    Castling& operator = (const Castling&) = delete;
	Castling& operator = (Castling&&) = delete;
};