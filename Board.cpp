#include <string>
#include <iostream>
#include <string>

#include "Board.h"
#include "utils.h"
#include "TileCodes.h"

#define INITIAL_BOARD_ROW_SIZE 6
#define INITIAL_BOARD_COL_SIZE 6
#define INITIAL_BOARD_ROW_ENG 'A'
#define INITIAL_BOARD_COL_NUM 1
#define ALPHABET_A 65
#define CHAR_TO_INT 48
#define MAXIMUM_VECTOR_SIZE 26
#define ALL_CONDITONS 4
#define NEIGHBOURS 4

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

std::string Board::getBoardSize() {
    return std::to_string(board.size()) + "," + std::to_string(board[0].size());
}

std::string Board::returnAllTilesinBoard(std::ostream& file) {
    std::string retValue = "";
    bool first = true;
    for(unsigned int i = 0; i != board.size(); ++i) {
        for(unsigned int j = 0; j != board[0].size(); ++j) {
            if(board[i][j]->getShape() != EMPTY_TILE) {
                if(first) {
                    printTile(file, board[i][j]);
                    file << "@";  
                    file << char(i+int('A'));
                    file << std::to_string(j);
                    first = false;
                }
                else {
                    file << ", ";
                    printTile(file, board[i][j]);
                    file << "@";  
                    file << char(i+int('A'));
                    file << std::to_string(j);
                }
                
            }
        }
    }
    return retValue;
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
            printTile(std::cout, board[i][j]);
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
		col = col * TENS_PLACE + (int)(x[i] - '0');
	}

    board[row][col]->setColour(tile->getColour());
    board[row][col]->setShape(tile->getShape());
}

void Board::setTiles(std::string tiles) {
    std::string str1(1, tiles[0]);
    Colour colour = changeStringToColour(str1);
    std::string str2(1, tiles[1]);
    Shape shape = changeStringToShape(str2);
    int row = int(tiles[3]) - ALPHABET_A;
    int col = int(tiles[4]) - CHAR_TO_INT;
    board[row][col]->setColour(colour);
    board[row][col]->setShape(shape);
}

bool Board::check(std::string x, Tile* tile, bool* first) {
    int nx[NEIGHBOURS] = { 0,0,-1,1 };
	int ny[NEIGHBOURS] = { -1,1,0,0 };

	unsigned int row = (int)(x[0] - 'A');
	unsigned int col = 0;
	for (unsigned int i = 1; i < x.length(); i++) {
		col = col * TENS_PLACE + (int)(x[i] - '0');
	}

    int deck_count = 0;

    //Check location validation
    if(row >= 0 && row < board.size() && col >=0 && col < board[0].size()) {
        int neighbour = 0;
        //Check empty tile
        if (board[row][col]->getColour() == EMPTY_TILE) {
            for (int i = 0; i < NEIGHBOURS; i++) {
                unsigned int neighbour_x = nx[i] + row;
                unsigned int neighbour_y = ny[i] + col;
                if (neighbour_x < 0 || neighbour_x >= board.size() || neighbour_y < 0 || neighbour_y >= board[0].size()) {
                    deck_count += 1;
                    neighbour += 1;
                }
                else {
                    Tile* t = board[neighbour_x][neighbour_y];
                    if(!(*first)) {
                        if (t->getColour() == EMPTY_TILE || t->getShape() == tile->getShape() || t->getColour() == tile->getColour()) {
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

        if (deck_count == ALL_CONDITONS) {
            unsigned int resizedRow = 0;
            unsigned int resizedCol = 0;
            if (row == board.size() - 1 && col == board[0].size() - 1) {
                resizedRow = board.size() + INITIAL_BOARD_ROW_SIZE;
                resizedCol = board[0].size() + INITIAL_BOARD_COL_SIZE;
                if(resizedRow > MAXIMUM_VECTOR_SIZE) {
                    resizedRow = MAXIMUM_VECTOR_SIZE;
                }
                if(resizedCol > MAXIMUM_VECTOR_SIZE) {
                    resizedCol = MAXIMUM_VECTOR_SIZE;
                }
                reSize(resizedRow, resizedCol);
            }
            else if(row == board.size() - 1) {
                resizedRow = board.size() + INITIAL_BOARD_ROW_SIZE;
                resizedCol = board[0].size();
                if(resizedRow > MAXIMUM_VECTOR_SIZE) {
                    resizedRow = MAXIMUM_VECTOR_SIZE;
                }
                reSize(resizedRow, resizedCol);
            }
            else if(col == board[0].size() - 1) {
                resizedRow = board.size();
                resizedCol = board[0].size() + INITIAL_BOARD_COL_SIZE;
                if(resizedCol > MAXIMUM_VECTOR_SIZE) {
                    resizedCol = MAXIMUM_VECTOR_SIZE;
                }
                reSize(resizedRow, resizedCol);
            }
        }
    }
	
	return (deck_count == ALL_CONDITONS ? true : false);
}

unsigned int Board::getBoardRow() {
    return board.size();
}

unsigned int Board::getBoardCol() {
    return board[0].size();
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

int Board::getScore(std::string tile) {
    int row = (int)(tile[0] - 'A');
	int col = 0;
	for (unsigned int i = 1; i < tile.length(); ++i) {
		col = col * TENS_PLACE + (int)(tile[i] - '0');
	}
	int my_score = 0;

    //Check all tiles there are near by me
	int num_of_top = 0;
	for (int i = row - 1; i > -1; --i) { //Check up
		Tile* t = board[i][col];
		if (t->getShape() == EMPTY_TILE) {
			i = -1; //Stop
		}
		else {
			num_of_top += 1;
		}
	}

	int num_of_bot = 0;
	for (unsigned int i = row + 1; i < board.size(); ++i) { //Check bot
		Tile* t = board[i][col];
		if (t->getShape() == EMPTY_TILE) {
			i = board.size(); //Stop
		}
		else {
			num_of_bot += 1;
		}
	}

	int num_of_left = 0;
	for (int i = col -1 ; i > -1; --i) { //Check left
		Tile* t = board[row][i];
		if (t->getShape() == EMPTY_TILE) {
			i = -1; //Stop
		}
		else {
			num_of_left += 1;
		}
	}

	int num_of_right = 0;
	for (unsigned int i = col + 1; i < board[0].size(); ++i) { //Check right
		Tile* t = board[row][i];
		if (t->getShape() == EMPTY_TILE) {
			i = board[0].size(); //Stop
		}
		else {
			num_of_right += 1;
		}
	}

    bool qwirkle = false;
    if(num_of_top + num_of_bot == QWIRKLE_NUMBER_WITHOUT_MYSELF) {
        my_score += QWIRKLE_POINTS;
        qwirkle = true;
    }
    else if(num_of_top != 0 || num_of_bot != 0) {
        my_score += num_of_top + num_of_bot + 1;
    }

    if(num_of_left + num_of_right == QWIRKLE_NUMBER_WITHOUT_MYSELF) {
        my_score += QWIRKLE_POINTS;
        qwirkle = true;
    }
    else if(num_of_left != 0 || num_of_right != 0) {
        my_score += num_of_left + num_of_right + 1;
    }

    if(qwirkle) {
        std::cout << std::endl;
        std::cout << "QWIRKLE!!!" << std::endl;
        std::cout << std::endl;
    }

	return my_score;
}

void Board::clear() {
    for(unsigned int i = 0; i != board.size() ; ++i) {
        for (unsigned int j = 0; j != board[i].size(); ++j) {
            delete board[i][j];
            board[i][j] = nullptr;
        }
    }
}