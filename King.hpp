#ifndef __KINGCLASS__
#define __KINGCLASS__
 
#include "ChessPiece.hpp"


class King : public ChessPiece {
    public:
    King(Color color);
    char getSymbol() override;
    Color getColor() override;
    bool isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) override;
};

#endif // __KINGCLASS__