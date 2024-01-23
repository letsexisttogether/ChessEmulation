#include "BoardObserver.hpp"

#include <stdexcept>

void BoardObserver::AddPiece(const PieceSide side, const PieceType type, 
        const BoardCell* cell) noexcept
{
    PieceKey key{ side, type };

    auto& map = GetPiecesMap(side);
    map.emplace(key, cell);
}

const BoardCell& BoardObserver::GetPiece(const PieceSide side, 
    const PieceType type) const noexcept(false)
{
    PieceKey key{ side, type };
    const auto& map = GetPiecesMap(side); 

    auto range = map.equal_range(key);
    if (range.first == range.second)
    {
        throw std::runtime_error{ "Piece not found" };
    }

    // Assuming you want to return the first piece found
    return *range.first->second;
}

BoardObserver::CellsOutContainer 
    BoardObserver::GetAlivePieces(const PieceSide side) 
    const noexcept
{
    CellsOutContainer result{};
    
    const auto& map = GetPiecesMap(side);

    for (const auto& [pieceKey, boardCell] : map)
    {
        result.push_back(boardCell);
    }

    return result;
}
