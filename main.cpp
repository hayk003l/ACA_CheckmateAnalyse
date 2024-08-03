#include <iostream>
#include <vector>
#include <cmath>
// #include "AllIncludes.hpp"
#include "ChessBoard.hpp"



int main() {
    
    ChessBoard chessBoard;
    
    // Add some pieces to the board
    chessBoard.addPiece(0, 4, 'K', Black);
    chessBoard.addPiece(7, 4, 'K', White);
    chessBoard.addPiece(1, 0, 'R', White);
    chessBoard.addPiece(1, 7, 'R', White);

    // Print the board
    chessBoard.printBoard();

    // Check for checkmate situation
    if (chessBoard.checkmateInOneMove(Black)) {
        std::cout << "Checkmate Position." << std::endl;
    } else {
        std::cout << "No Checkmate." << std::endl;
    }

    return 0;
}
