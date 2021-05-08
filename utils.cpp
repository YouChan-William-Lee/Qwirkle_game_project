#include "utils.h"
#include <iostream>

void printHand(std::ostream& file, TileBag* tileBag) {
    if(tileBag->size() != 0) {
        for (unsigned int i = 0; i < tileBag->size(); ++i) {
            if (tileBag->get(i) != nullptr) {
                printTile(file, tileBag->get(i));
            }
            if (i != tileBag->size() - 1) {
                file << ",";
            }
        }
    } 
}

void printTileBag(std::ostream& file, TileBag* tileBag) {
    if(tileBag->size() != 0) {
        for (unsigned int i = 0; i < tileBag->size(); ++i) {
            if (tileBag->get(i) != nullptr) {
                printTile(file, tileBag->get(i));
            }
            if (i != tileBag->size() - 1) {
                file << ",";
            }
        }
    } 
}

void printBoardState(std::ostream& file, Board* board, unsigned int boardRow, unsigned int boardCol) {
    // for(unsigned int i = 0; i != boardRow; ++i) {
    //     for(unsigned int j = 0; j != boardCol; ++j) {
    //         if(board[i][j]->getShape() != EMPTY_TILE) {
    //             file << board[i][j]->getColour() << board[i][j]->getShape() << "@" << char(i+int('A')) << j;
    //         }
    //     }
    // }
}

void printTile(std::ostream& output, Tile* tile) {
    printColourAsString(output, tile->getColour());
    printShapeAsString(output, tile->getShape());
}

void printColourAsString(std::ostream& output, Colour colour) {
    char red[] = "R";
    char orange[] = "O";
    char yellow[] = "Y";
    char green[] = "G";
    char blue[] = "B";
    char purple[] = "P";
    char unknown[] = " ";

    if (colour == RED) {
        output << red;
    } else if (colour == ORANGE) {
        output << orange;
    } else if (colour == YELLOW) {
        output << yellow;
    } else if (colour == GREEN) {
        output << green;
    } else if (colour == BLUE) {
        output << blue;
    } else if (colour == PURPLE) {
        output << purple;
    } else {
        output << unknown;
    }
}

void printShapeAsString(std::ostream& output, Shape shape) {
    char circle[] = "1";
    char star_4[] = "2";
    char diamond[] = "3";
    char square[] = "4";
    char star_6[] = "5";
    char clover[] = "6";
    char unknown[] = " ";

    if (shape == CIRCLE) {
        output << circle;
    } else if (shape == STAR_4) {
        output << star_4;
    } else if (shape == DIAMOND) {
        output << diamond;
    } else if (shape == SQUARE) {
        output << square;
    } else if (shape == STAR_6) {
        output << star_6;
    } else if (shape == CLOVER) {
        output << clover;
    } else {
        output << unknown;
    }
}