#ifndef __PAWNCLASS__
#define __PAWNCLASS__

#include "ChessPiece.hpp"


class Pawn : public ChessPiece {
    public:
    Pawn(Color color);
    char getSymbol() override;
    Color getColor() override;
    bool isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) override;
};

#endif // __PAWNCLASS__