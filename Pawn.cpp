#include "Pawn.hpp"

Pawn::Pawn(Color color) {
    _color = color;
};


bool Pawn::isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) {
    return (endX == startX - 1 && (endY == startY - 1 || endY == startY + 1));
}

char Pawn::getSymbol() {
    return _color == White ? 'P' : 'p';
}

Color Pawn::getColor() {
    return _color;
}