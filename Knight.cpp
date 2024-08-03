#include "Knight.hpp"

Knight::Knight(Color color) {
    _color = color;
}

bool Knight::isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) {
    return (std::abs(endX - startX) == 2 && std::abs(endY - startY) == 1) || (std::abs(endX - startX) == 1 && std::abs(endY - startY) == 2);
}

char Knight::getSymbol() {
    return _color == White ? 'N' : 'n';
}

Color Knight::getColor() {
    return _color;
}