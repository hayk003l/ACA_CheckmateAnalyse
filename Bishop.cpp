#include "Bishop.hpp"

Bishop::Bishop(Color color) {
    _color = color;
}

bool Bishop::isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) {
    return std::abs(endX - startX) == std::abs(endY - startY);
}

char Bishop::getSymbol() {
    return _color == White ? 'B' : 'b';
}

Color Bishop::getColor() {
    return _color;
}