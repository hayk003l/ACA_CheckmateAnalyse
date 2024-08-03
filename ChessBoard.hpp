#ifndef __CHESSBOARD__
#define __CHESSBOARD__
#include "AllIncludes.hpp"


class ChessBoard {
private:
    std::vector<std::vector<ChessPiece*>> board;

    std::pair<int, int> findKing(Color kingColor);
    bool isCheck(Color kingColor);
    bool canMoveToAvoidCheck(Color kingColor);
    void placePiece(const int& x, const int& y, ChessPiece* piece);
    bool checkKingPosition(const int& x, const int& y);
public :
    ChessBoard();
    ~ChessBoard();  
    
    bool addPiece(const int& x, const int& y, char pieceType, Color color);
    bool isCheckMate(Color kingColor);
    bool movePiece(int startX, int startY, int endX, int endY);
    void printBoard();
    bool checkmateInOneMove(Color color);
    void possibleMoves(Color color);
};

#endif // __CHESSBOARD__