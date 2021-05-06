#include <string>
#include <iostream>

#include "Board.h"
#include "utils.h"

#define INITIAL_BOARD_ROW_SIZE 6
#define INITIAL_BOARD_COL_SIZE 6
#define INITIAL_BOARD_ROW_ENG 'A'
#define INITIAL_BOARD_COL_NUM 1

Board::Board() {
    board.resize(INITIAL_BOARD_ROW_SIZE, std::vector<Tile*>(INITIAL_BOARD_COL_SIZE, new Tile()));
}
Board::Board(Board& other) {
    clear();
    for(unsigned int i = 0; i != other.board.size() ; ++i) {
        for (unsigned int j = 0; j != other.board[i].size(); ++j) {
            board[i][j] = new Tile(*other.board[i][j]);
        }
    }
}
Board::~Board() {
    clear();
}

void Board::getBoard() {
    for(unsigned int i = 0; i != board.size() ; ++i) {
        if(i == 0) {
            std::cout << "  ";
            for(unsigned int k = 0; k != board[i].size(); ++k) {
                std::cout << " " << k << " ";
            }
            std::cout << std::endl;
            std::cout << "  ";
            for(unsigned int k = 0; k != board[i].size(); ++k) {
                std::cout << "---";
            }
            std::cout << "-";
            std::cout << std::endl;
        }
        for (unsigned int j = 0; j != board[i].size(); ++j) {
            if(j == 0) {
                std::cout << char(INITIAL_BOARD_ROW_ENG + i) << " ";
            }
            if(j != board[i].size()) {
                std::cout << "|";
            }
            printTile(board[i][j]);
            if(j == board[i].size() - 1) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
}

void Board::add(Tile* tile, char row, unsigned int col) {
    if(row >= INITIAL_BOARD_ROW_ENG && row < char(INITIAL_BOARD_ROW_ENG + board.size())
                                    && col >= INITIAL_BOARD_COL_NUM
                                    && col < (INITIAL_BOARD_COL_NUM + board[0].size())) {
        board[row][col] = new Tile(*tile);
    }
}

void Board::clear() {
    // for(unsigned int i = 0; i != board.size() ; ++i) {
    //     for (unsigned int j = 0; j != board[i].size(); ++j) {
    //         delete[] board[i][j];
    //         board[i][j] = nullptr;
    //     }
    // }
    // board.clear();
}