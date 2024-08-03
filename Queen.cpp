#include "Queen.hpp"

Queen::Queen(Color color) {
    _color = color;
}

bool Queen::isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) {
    return (endX == startX || endY == startY || std::abs(endX - startX) == std::abs(endY - startY));
}

char Queen::getSymbol() {
    return _color == White ? 'Q' : 'q';
}

Color Queen::getColor() {
    return _color;
}