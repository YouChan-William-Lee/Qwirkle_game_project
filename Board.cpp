#include <string>
#include <iostream>
#include <string>

#include "Board.h"
#include "utils.h"
#include "TileCodes.h"

#define INITIAL_BOARD_ROW_SIZE 6
#define INITIAL_BOARD_COL_SIZE 6
#define INITIAL_BOARD_ROW_ENG 'A'
#define INT_A 65
#define MAXIMUM_VECTOR_SIZE 26
#define ALL_CONDITONS 4
#define NEIGHBOURS 4
#define MYSELF 1

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
            if(board[i][j]->getColour() != EMPTY_TILE) {
                if(first) {
                    printTile(file, board[i][j]);
                    file << "@";  
                    file << char(i+INT_A);
                    file << std::to_string(j);
                    first = false;
                }
                else {
                    file << ", ";
                    printTile(file, board[i][j]);
                    file << "@";  
                    file << char(i+INT_A);
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
                if(k < 10) {
                    std::cout << " " << k << " ";
                }
                else {
                    std::cout << " " << k;
                }
                
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
            if(board[i][j]->getColour() == EMPTY_TILE) {
                std::cout << "  ";
            }
            else {
                printTile(std::cout, board[i][j]);
            }
            if(j == board[i].size() - 1) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
}

void Board::add(std::string x, Tile* tile) {
    //Change alphabet to int
    unsigned int row = int(x[0]) - INT_A;
    //Change string to int
    unsigned int col = 0;
    for (unsigned int i = 1; i < x.length(); i++) {
		col = col * TENS_PLACE + (x[i] - CHAR_0);
	}

    board[row][col]->setColour(tile->getColour());
    board[row][col]->setShape(tile->getShape());
}

void Board::setTiles(std::string tile) {
    //For example) the formation of tile is P5@D2
    //P would be colour of tile, 5 would be shape of tile
    //D would be row of the board, 2 would be col of the board
    std::string str1(1, tile[0]);
    Colour colour = changeStringToColour(str1);
    std::string str2(1, tile[1]);
    Shape shape = changeStringToShape(str2);
    //Change alphabet to int
    unsigned int row = int(tile[3]) - INT_A;
    //Change string to int
    unsigned int col = 0;
    for (unsigned int i = 4; i < tile.length(); i++) {
		col = col * TENS_PLACE + (tile[i] - CHAR_0);
	}
    board[row][col]->setColour(colour);
    board[row][col]->setShape(shape);
}

bool Board::check(std::string x, Tile* tile, bool* first) {
    //Neighbours location (DOWN, UP, LEFT, RIGHT)
    int nx[NEIGHBOURS] = { 0,0,-1,1 };
	int ny[NEIGHBOURS] = { -1,1,0,0 };

	//Change alphabet to int
    unsigned int row = int(x[0]) - INT_A;
    //Change string to int
    unsigned int col = 0;
    for (unsigned int i = 1; i < x.length(); i++) {
		col = col * TENS_PLACE + (x[i] - CHAR_0);
	}

    int four_conditions = 0;

    //Check if the location is valid
    if(row >= 0 && row < board.size() && col >=0 && col < board[0].size()) {
        int neighbour = 0;
        //Check if empty tile
        if (board[row][col]->getColour() == EMPTY_TILE) {
            for (int i = 0; i < NEIGHBOURS; i++) {
                unsigned int neighbour_x = nx[i] + row;
                unsigned int neighbour_y = ny[i] + col;
                //Check if this neighbour is edge
                if (neighbour_x < 0 || neighbour_x >= board.size() || neighbour_y < 0 || neighbour_y >= board[0].size()) {
                    four_conditions += 1;
                    neighbour += 1;
                }
                else {
                    Tile* t = board[neighbour_x][neighbour_y];
                    //Check if this tile is the first tile in the board
                    if(!(*first)) {
                        if (t->getColour() == EMPTY_TILE) {
                        four_conditions += 1;
                        }
                    }
                    else {
                        //Check 3 other neighbours are either empty tile or edge
                        if(neighbour < 3 && t->getColour() == EMPTY_TILE) {
                            four_conditions += 1;
                            neighbour += 1;
                        }
                        else if ((t->getShape() == tile->getShape() || t->getColour() == tile->getColour()) 
                                    && !(t->getShape() == tile->getShape() && t->getColour() == tile->getColour())) {
                            
                            bool duplication = false;
                            bool stop = false;
                            //Check neighbour's neighbour if they are same as this tile
                            while(neighbour_x > 0 && neighbour_y > 0 && neighbour_x < board.size() 
                                                                     && neighbour_y < board[0].size() 
                                                                     && !duplication
                                                                     && !stop) {
                                neighbour_x = nx[i] + neighbour_x;
                                neighbour_y = ny[i] + neighbour_y;
                                Tile* t = board[neighbour_x][neighbour_y];
                                
                                //If this neighbour is same as this tile, it means there is duplication
                                if(t->getShape() == tile->getShape() && t->getColour() == tile->getColour()){
                                    duplication = true;
                                }      

                                //If this neighbour is empty tile or none of shape and colour is differnt with this tile, stop searching
                                if(t->getColour() == EMPTY_TILE || (t->getShape() != tile->getShape() && t->getColour() != tile->getColour())) {
                                    stop = true;
                                }                               
                            }

                            //If there is no duplication, it satisfies the condition
                            if(!duplication) {
                                four_conditions += 1;
                            }
                        }                    
                    }
                }
            }
        }

        //If this tile satisfies all four condtions
        if (four_conditions == ALL_CONDITONS) {
            unsigned int resizedRow = 0;
            unsigned int resizedCol = 0;
            //If this tile is on the corner
            if (row == board.size() - 1 && col == board[0].size() - 1) {
                if(!(board.size() == MAXIMUM_VECTOR_SIZE && board[0].size() == MAXIMUM_VECTOR_SIZE)) {
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
            }
            //If this tile is on the edge of row
            else if(row == board.size() - 1) {
                if(!(board.size() == MAXIMUM_VECTOR_SIZE)) {
                    resizedRow = board.size() + INITIAL_BOARD_ROW_SIZE;
                    resizedCol = board[0].size();
                    if(resizedRow > MAXIMUM_VECTOR_SIZE) {
                        resizedRow = MAXIMUM_VECTOR_SIZE;
                    }
                    reSize(resizedRow, resizedCol);
                }
            }
            //If this tile is on the edge of col
            else if(col == board[0].size() - 1) {
                if(!(board[0].size() == MAXIMUM_VECTOR_SIZE)) {
                    resizedRow = board.size();
                    resizedCol = board[0].size() + INITIAL_BOARD_COL_SIZE;
                    if(resizedCol > MAXIMUM_VECTOR_SIZE) {
                        resizedCol = MAXIMUM_VECTOR_SIZE;
                    }
                    reSize(resizedRow, resizedCol);
                }
            }
        }
    }
	
	return (four_conditions == ALL_CONDITONS ? true : false);
}

unsigned int Board::getBoardRow() {
    return board.size();
}

unsigned int Board::getBoardCol() {
    return board[0].size();
}

void Board::reSize(unsigned int row, unsigned int col) {
    //Resie row first
    board.resize(row);

    //Resize col next
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
    //Change alphabet to int
    int row = int(tile[0]) - INT_A;
    //Change string to int
    unsigned int col = 0;
    for (unsigned int i = 1; i < tile.length(); i++) {
		col = col * TENS_PLACE + (tile[i] - CHAR_0);
	}

	int my_score = 0;

    //Check all tiles there are near by me
	int num_of_top = 0;
    //Check UP
	for (int i = row - 1; i > -1; --i) {
		Tile* t = board[i][col];
		if (t->getColour() == EMPTY_TILE) {
			i = -1; //Stop
		}
		else {
			num_of_top += 1;
		}
	}

	int num_of_bot = 0;
    //Check BOTTOM
	for (unsigned int i = row + 1; i < board.size(); ++i) {
		Tile* t = board[i][col];
		if (t->getColour() == EMPTY_TILE) {
			i = board.size(); //Stop
		}
		else {
			num_of_bot += 1;
		}
	}

	int num_of_left = 0;
    //Check LEFT
	for (int i = col -1 ; i > -1; --i) {
		Tile* t = board[row][i];
		if (t->getColour() == EMPTY_TILE) {
			i = -1; //Stop
		}
		else {
			num_of_left += 1;
		}
	}

	int num_of_right = 0;
    //Check RIGHT
	for (unsigned int i = col + 1; i < board[0].size(); ++i) {
		Tile* t = board[row][i];
		if (t->getColour() == EMPTY_TILE) {
			i = board[0].size();
		}
		else {
			num_of_right += 1;
		}
	}

    bool qwirkle = false;
    //If there are total 6 tiles including myself in a column
    if(num_of_top + num_of_bot == QWIRKLE_NUMBER_WITHOUT_MYSELF) {
        my_score += QWIRKLE_POINTS;
        qwirkle = true;
    }
    else if(num_of_top != 0 || num_of_bot != 0) {
        my_score += num_of_top + num_of_bot + MYSELF;
    }

    //If there are total 6 tiles including myself in a row
    if(num_of_left + num_of_right == QWIRKLE_NUMBER_WITHOUT_MYSELF) {
        my_score += QWIRKLE_POINTS;
        qwirkle = true;
    }
    else if(num_of_left != 0 || num_of_right != 0) {
        my_score += num_of_left + num_of_right + MYSELF;
    }

    if(qwirkle) {
        std::cout << std::endl;
        std::cout << "QWIRKLE!!!" << std::endl;
    }

	return my_score;
}

bool Board::tileOnTheBoard() {
    bool retVal = false;
    for(unsigned int i = 0; i != board.size() && !retVal; ++i) {
        for (unsigned int j = 0; j != board[i].size() && !retVal; ++j) {
            if(board[i][j]->getColour() != EMPTY_TILE) {
                retVal = true;
            }
        }
    }
    return retVal;
}

void Board::clear() {
    for(unsigned int i = 0; i != board.size() ; ++i) {
        for (unsigned int j = 0; j != board[i].size(); ++j) {
            delete board[i][j];
            board[i][j] = nullptr;
        }
    }
}