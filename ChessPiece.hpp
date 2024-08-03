
#ifndef __CHESSPIECE__
#define __CHESSPIECE__
 
#include <vector>
#include <iostream>
#include <windows.h>

class ChessBoard;

enum Color {
    White,
    Black,
    None
};

class ChessPiece {
public:
    Color _color;
    virtual bool isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) = 0;
    virtual ~ChessPiece() = default;
    virtual char getSymbol() = 0;
    virtual Color getColor() = 0;
};  

#endif // __CHESSPIECE__