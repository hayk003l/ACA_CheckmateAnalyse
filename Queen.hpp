#ifndef __QUEENCLASS__
#define __QUEENCLASS__


#include "ChessPiece.hpp"


class Queen : public ChessPiece {
    public:
    Queen(Color color);
    char getSymbol() override;
    Color getColor() override;
    bool isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) override;

};

#endif // __QUEENCLASS__