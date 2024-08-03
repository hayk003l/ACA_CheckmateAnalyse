#ifndef __BISHOPCLASS__
#define __BISHOPCLASS__
 


#include "ChessPiece.hpp"


class Bishop : public ChessPiece {
public:
    Bishop(Color color);
    char getSymbol() override;
    Color getColor() override;
    bool isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) override;
};

#endif // __BISHOPCLASS__