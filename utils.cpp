#include "utils.h"
#include "TileBag.h"
#include "Hand.h"

#include <iostream>

void printHand(std::ostream& file, Hand* hand) {
    if(hand->size() != 0) {
        for (unsigned int i = 0; i < hand->size(); ++i) {
            if (hand->getByIndex(i) != nullptr) {
                printTile(file, hand->getByIndex(i));
            }
            if (i != hand->size() - 1) {
                file << ",";
            }
        }
    } 
}

void printTileBag(std::ostream& file, TileBag* tileBag) {
    if(tileBag->size() != 0) {
        for (unsigned int i = 0; i < tileBag->size(); ++i) {
            if (tileBag->getByIndex(i) != nullptr) {
                printTile(file, tileBag->getByIndex(i));
            }
            if (i != tileBag->size() - 1) {
                file << ",";
            }
        }
    } 
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

Colour changeStringToColour(std::string c) {
    char red[] = "R";
    char orange[] = "O";
    char yellow[] = "Y";
    char green[] = "G";
    char blue[] = "B";
    char purple[] = "P";

    Colour colour = ' ';

    if (c == red) {
        colour = RED;
    } else if (c == orange) {
        colour = ORANGE;
    } else if (c == yellow) {
        colour = YELLOW;
    } else if (c == green) {
        colour = GREEN;
    } else if (c == blue) {
        colour = BLUE;
    } else if (c == purple) {
        colour = PURPLE;
    }

    return colour;
}

Shape changeStringToShape(std::string s) {
    char circle[] = "1";
    char star_4[] = "2";
    char diamond[] = "3";
    char square[] = "4";
    char star_6[] = "5";
    char clover[] = "6";

    Shape shape = ' ';

    if (s == circle) {
        shape = CIRCLE;
    } else if (s == star_4) {
        shape = STAR_4;
    } else if (s == diamond) {
        shape = DIAMOND;
    } else if (s == square) {
        shape = SQUARE;
    } else if (s == star_6) {
        shape = STAR_6;
    } else if (s == clover) {
        shape = CLOVER;
    }

    return shape;
}