#pragma once

class MoveChecker
{
// Bad practive don't do 
class Board{};

public:
	virtual ~MoveChecker() = 0;

	virtual bool CheckPermissibility(const Board& board) const noexcept = 0;
};  