#include "Rook.hpp"

Rook::Rook(Color color) {
    _color = color;
};
Rook::~Rook() {};

bool Rook::isValidMove(const int& startX, const int& startY, const int& endX, const int& endY, const std::vector<std::vector<ChessPiece*>>& board) {
    return (startX == endX || startY == endY);
};

char Rook::getSymbol() {
    return _color == White ? 'R' : 'r';
}

Color Rook::getColor() {
    return _color;
}