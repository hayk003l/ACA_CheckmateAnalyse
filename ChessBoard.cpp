#include "ChessBoard.hpp"

#include <iostream>
#include <exception>

ChessBoard::ChessBoard() : board(8, std::vector<ChessPiece*>(8, nullptr)) {}

ChessBoard::~ChessBoard() {
    for (int i = 0; i < 8; ++i) {
       for (int j = 0; j < 8; ++j) {
        delete board[i][j];
       }
    }
}


std::pair<int, int> ChessBoard::findKing(Color kingColor) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] && board[i][j]->_color == kingColor && dynamic_cast<King*>(board[i][j])) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

bool ChessBoard::isCheck(Color kingColor) {
    std::pair<int, int> kingPosition = findKing(kingColor);

    if (kingPosition.first == -1) {
        std::cout << "There is no King on board" << std::endl;
        return false;
    }
    
    int kingX = kingPosition.first;
    int kingY = kingPosition.second;

    // Analyse attacks
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] && board[i][j]->_color != kingColor && board[i][j] -> isValidMove(i, j, kingX, kingY, board)) {
                return true;
            }
        }
    }
    return false;
}


bool ChessBoard::canMoveToAvoidCheck(Color kingColor) {
    std::pair<int, int> kingPosition = findKing(kingColor);
    if (kingPosition.first == -1) {
        std::cout << "King not found on board!" << std::endl;
        return false;
    }

    int kingX = kingPosition.first;
    int kingY = kingPosition.second;

    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (x == kingX && y == kingY) continue;
            
            if (board[x][y] && board[x][y]->_color == kingColor) continue;
            
            if (board[kingX][kingY]->isValidMove(kingX, kingY, x, y, board)) {
                
                // Move the king to the new position
                ChessPiece* temp = board[x][y];
                board[x][y] = board[kingX][kingY];
                board[kingX][kingY] = nullptr;

                bool avoidsCheck = !isCheck(kingColor);

                // Restore the board state
                board[kingX][kingY] = board[x][y];
                board[x][y] = temp;

                if (avoidsCheck) return true;
            }   
        }
    }
    return false;
}

bool ChessBoard::checkKingPosition(const int& x, const int& y) {
    // Handle King piece right placement
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (x + i < 0 || x + i >= 8 || y + j < 0 || y + j >= 8) {
                continue;
            }
            else if (board[x + i][y + j] && dynamic_cast<King*>(board[x + i][y + j])) {
                return false;
            }
        }
    }
    return true;
}

void ChessBoard::placePiece(const int& x, const int& y, ChessPiece* piece) {
    board[x][y] = piece;
};


bool ChessBoard::addPiece(const int& x, const int& y, char pieceType, Color color) {
    
    // Check position cordinates
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        throw std::out_of_range("Position is out of board!.");
        return false;
    }

    ChessPiece* piece = nullptr;

    // Determine piece type
    switch (pieceType)  {
    case 'K': 
        if (checkKingPosition(x, y)) {
            piece = new King(color);
        }
        else {
            throw std::out_of_range("Invalid position");
            return false;
        }
        break;
    case 'Q' : piece = new Queen(color); break;
    case 'P' : piece = new Pawn(color); break;
    case 'N' : piece = new Knight(color); break;
    case 'B' : piece = new Bishop(color); break;
    case 'R' : piece = new Rook(color); break;
    default:
        throw std::out_of_range("Invalid name of piece!");
        return false;
    }
    

    placePiece(x, y, piece);
    return true;
}


bool ChessBoard::isCheckMate(Color kingColor) {
        if (!isCheck(kingColor)) {
            return false;
        } 
        return !canMoveToAvoidCheck(kingColor);
}

bool ChessBoard::movePiece(int startX, int startY, int endX, int endY) {
    // Checking cordinates
    if (startX < 0 || startX >= 8 ||
        startY < 0 || startY >= 8 || 
        endX < 0 || endX >= 8 ||
        endY < 0 || endX >= 8) {
            throw std::out_of_range("Invalid position.");
        }
    // Move piece
    if (board[startX][startY] && 
        board[startX][startY] -> isValidMove(startX, startY, endX, endY, board) &&
        (!board[endX][endY] || board[startX][startY]->_color != board[endX][endY]->_color)){

            // Handle King piece right placement
            if (dynamic_cast<King*>(board[startX][startY]) && !checkKingPosition(endX, endY)) {
                return false;
            }
            
            board[endX][endY] = board[startX][startY];
            board[startX][startY] = nullptr;
            // std::cout << "flag" << std::endl;
            return true;
        }
    return false;
}

void ChessBoard::printBoard() {
    std::cout << "   A B C D E F G H" << std::endl;
    std::cout << " +-----------------+" << std::endl;

    for (int i = 0; i < 8; ++i) {
        std::cout << (8 - i) << "|"; // Row number
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == nullptr) {
                std::cout << " .";
            } else {
                std::cout << ' ' << board[i][j]->getSymbol();
            }
        }
        std::cout << " |" << (8 - i) << std::endl;
    }

    std::cout << " +-----------------+" << std::endl;
    std::cout << "   A B C D E F G H" << std::endl;
}

bool ChessBoard::checkmateInOneMove(Color color) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            
            if (board[i][j] && board[i][j] -> _color != color) {

                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        ChessPiece* tempOne = board[i][j];
                        ChessPiece* tempTwo = board[x][y];
                        if (movePiece(i, j, x, y) && isCheckMate(color)) {
                            // std::cout << "flag1" << std::endl;
                            printBoard();
                            return true;
                        }
                        else {
                            board[i][j] = tempOne;
                            board[x][y] = tempTwo;
                        }
                    }
                }
            }
        }
    }
    return false;
}
