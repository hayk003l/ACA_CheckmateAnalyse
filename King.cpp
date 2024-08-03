#include "King.hpp"

King::King(Color color) {
    _color = color;
}

bool King::isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) {
    return std::abs(endX - startX) <= 1 && std::abs(endY - startY) <= 1;
}

char King::getSymbol() {
    return _color == White ? 'K' : 'k';
}

Color King::getColor() {
    return _color;
}