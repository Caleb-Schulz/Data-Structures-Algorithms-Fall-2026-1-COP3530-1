#include "Board.hpp"

#include <string>
#include <iostream>

Board::Board(int size) : board_size(size) {
    std::string row(board_size, '.');
    for(int i = 0; i < board_size; i++) {
        board.push_back(row);
    }
}

void Board::printRow(int row) const {
    for (int col = 0; col < board[row].size(); col++) {
        std::cout << board[row][col];
        if (col < board[row].size() - 1) {
            std::cout << " ";
        }
    }
}
void Board::printBoard() const {
    int i = 0;
    int j = board_size;
    std::cout << "  ________________\n";
    while (i < board_size) {
        std::cout << j << '|';
        printRow(i);
        std::cout << '|' << std::endl;
        i++;
        j--;
    }
    std::cout << "  ----------------\n";
    std::cout << "  a b c d e f g h\n";
}



void Board::placeQueens() {
    
}


bool Board::checkPlace(const int row, const int col) const {
    //NS
    int i = 0;
    int j = col;
    while (i < board_size) {
        if (board[i][j] == 'Q' && (i != row || j != col)) {
            return false;
        }
        i++;
    }

    i = row;
    j = col;

    
    //NE
    while (i >= 0 && j < board_size) {
        if (board[i][j] == 'Q' && (i != row || j != col)) {
            return false;
        }
        i--;
        j++;
    }

    i = row;
    j = 0;

    //WE
    while (j < board_size) {
        if (board[i][j] == 'Q' && (i != row || j != col)) {
            return false;
        }
        j++;
    }

    
    //SE
    i = row;
    j = col;

    while (i < board_size && j < board_size) {
        if (board[i][j] == 'Q' && (i != row || j != col)) {
            return false;
        }
        j++;
        i++;
    }

    i = row;
    j = col;

    //SW
    while (i < board_size && j >= 0) {
        if (board[i][j] == 'Q' && (i != row || j != col)) {
            return false;
        }
        j--;
        i++;
    }
    
    //NW
    i = row;
    j = col;

    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q' && (i != row || j != col)) {
            return false;
        }
        j--;
        i--;
    }
    
    return true;
}