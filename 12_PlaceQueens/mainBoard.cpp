#include "Board.hpp"


int main(void) {
    Board chess;
    chess.printBoard();
    chess.placeQueens();
    chess.printBoard();


    return 0;
}