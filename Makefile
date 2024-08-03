
CC = g++

main: main.o ChessPiece.o King.o Queen.o Bishop.o Pawn.o Knight.o Rook.o AllIncludes.o
	$(CC) -o main main.o ChessPiece.o King.o Queen.o Bishop.o Pawn.o Knight.o Rook.o AllIncludes.o

main.o: main.cpp AllIncludes.hpp 
	$(CC) -c main.cpp

allIncludes.o :	AllIncludes.hpp
	$(CC) -c AllIncludes.cpp	

ChessPiece.o: ChessPiece.cpp ChessPiece.hpp
	$(CC) -c ChessPiece.cpp

King.o: King.cpp King.hpp ChessPiece.hpp
	$(CC) -c King.cpp

Queen.o: Queen.cpp Queen.hpp ChessPiece.hpp
	$(CC) -c Queen.cpp

Pawn.o: Pawn.cpp Pawn.hpp ChessPiece.hpp
	$(CC) -c Pawn.cpp

Rook.o: Rook.cpp Rook.hpp ChessPiece.hpp
	$(CC) -c Rook.cpp

Bishop.o: Bishop.cpp Bishop.hpp ChessPiece.hpp
	$(CC) -c Bishop.cpp

Knight.o: Knight.cpp Knight.hpp ChessPiece.hpp
	$(CC) -c Knight.cpp

clean:
	rm -f main main.o ChessPiece.o King.o Queen.o Bishop.o Pawn.o Knight.o Rook.o AllIncludes.o *d.
