#include <string>
#include <iostream>

#include "Board.h"
#include "utils.h"

#define INITIAL_BOARD_ROW_SIZE 6
#define INITIAL_BOARD_COL_SIZE 6
#define INITIAL_BOARD_ROW_ENG 'A'
#define INITIAL_BOARD_COL_NUM 1

Board::Board() {
    board.resize(INITIAL_BOARD_ROW_SIZE, std::vector<Tile*>(INITIAL_BOARD_COL_SIZE));

    for(int i = 0; i != INITIAL_BOARD_ROW_SIZE ; ++i) {
        for (int j = 0; j != INITIAL_BOARD_COL_SIZE; ++j) {
            board[i][j] = new Tile();
        }
    }
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

void Board::add(std::string x, Tile* tile) {
    unsigned int row = (int)(x[0] - 'A');
	unsigned int col = 0;
	for (unsigned int i = 1; i < x.length(); i++) {
		col = col * 10 + (int)(x[i] - '0');
	}

    board[row][col]->setColour(tile->getColour());
    board[row][col]->setShape(tile->getShape());
}

bool Board::check(std::string x, Tile* tile, bool* first) {
    int nx[4] = { 0,0,-1,1 };
	int ny[4] = { -1,1,0,0 };

	unsigned int row = (int)(x[0] - 'A');
	unsigned int col = 0;
	for (unsigned int i = 1; i < x.length(); i++) {
		col = col * 10 + (int)(x[i] - '0');
	}
	int deck_count = 0;
    int neighbour = 0;
    //Check empty tile
	if (board[row][col]->getColour() == ' ') {
		for (int i = 0; i < 4; i++) {
			unsigned int neighbour_x = nx[i] + row;
			unsigned int neighbour_y = ny[i] + col;
			if (neighbour_x < 0 || neighbour_x >= board.size() || neighbour_y < 0 || neighbour_y >= board[0].size()) {
				deck_count += 1;
                neighbour += 1;
			}
			else {
                Tile* t = board[neighbour_x][neighbour_y];
                if(!(*first)) {
                    if (t->getColour() == ' ' || t->getShape() == tile->getShape() || t->getColour() == tile->getColour()) {
					deck_count += 1;
				    }
                }
                else {
                    if(neighbour < 3 && t->getColour() == ' ') {
                        deck_count += 1;
                        neighbour += 1;
                    }
                    else if (t->getShape() == tile->getShape() || t->getColour() == tile->getColour()) {
                        deck_count += 1;
                    }                    
                }
			}
		}
	}

    if (deck_count == 4) {
        unsigned int resizedRow = 0;
        unsigned int resizedCol = 0;
        if (row == board.size() - 1 && col == board[0].size() - 1) {
            resizedRow = board.size() + INITIAL_BOARD_ROW_SIZE;
            resizedCol = board[0].size() + INITIAL_BOARD_COL_SIZE;
            if(resizedRow > 26) {
                resizedRow = 26;
            }
            if(resizedCol > 26) {
                resizedCol = 26;
            }
            reSize(resizedRow, resizedCol);
        }
        else if(row == board.size() - 1) {
            resizedRow = board.size() + INITIAL_BOARD_ROW_SIZE;
            resizedCol = board[0].size();
            if(resizedRow > 26) {
                resizedRow = 26;
            }
            reSize(resizedRow, resizedCol);
        }
        else if(col == board[0].size() - 1) {
            resizedRow = board.size();
            resizedCol = board[0].size() + INITIAL_BOARD_COL_SIZE;
            if(resizedCol > 26) {
                resizedCol = 26;
            }
            reSize(resizedRow, resizedCol);
        }
    }
	return (deck_count == 4 ? true : false);
}

void Board::reSize(unsigned int row, unsigned int col) {
    board.resize(row);

    for(unsigned int i = 0; i != board.size(); ++i) {
        board[i].resize(col);
    }

    for(unsigned int i = 0; i != board.size(); ++i) {
        for(unsigned int j = 0; j != board[0].size(); ++j) {
            if(board[i][j] == nullptr) {
                board[i][j] = new Tile();
            }
        }
    }
}

void Board::clear() {
    for(unsigned int i = 0; i != board.size() ; ++i) {
        for (unsigned int j = 0; j != board[i].size(); ++j) {
            delete board[i][j];
            board[i][j] = nullptr;
        }
    }
}