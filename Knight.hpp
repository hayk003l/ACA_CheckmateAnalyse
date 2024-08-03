#ifndef __KNIGHTCLASS__
#define __KNIGHTCLASS__
#include "ChessPiece.hpp"


class Knight : public ChessPiece {
    public:
    Knight(Color color);
    char getSymbol() override;
    Color getColor() override;
    bool isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) override;
};

#endif // __KNIGHTCLASS__