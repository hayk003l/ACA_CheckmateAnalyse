#ifndef __ROOKCLASS__
#define __ROOKCLASS__


#include "ChessPiece.hpp"


class Rook : public ChessPiece {
public:
    Rook(Color color);
    ~Rook();
    char getSymbol() override;
    Color getColor() override;
    bool isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) override;

};

#endif // __ROOKCLASS__