#include "utils.h"
#include "TileBag.h"
#include <iostream>


void printTile(Tile* tile) {
    printColourAsString(tile->colour);
    printShapeAsString(tile->shape);
}

void printColourAsString(Colour colour) {
    char red[] = "R";
    char orange[] = "O";
    char yellow[] = "Y";
    char green[] = "G";
    char blue[] = "B";
    char purple[] = "P";
    char unknown[] = " ";

    if (colour == RED) {
        std::cout << red;
    } else if (colour == ORANGE) {
        std::cout << orange;
    } else if (colour == YELLOW) {
        std::cout << yellow;
    } else if (colour == GREEN) {
        std::cout << green;
    } else if (colour == BLUE) {
        std::cout << blue;
    } else if (colour == PURPLE) {
        std::cout << purple;
    } else {
        std::cout << unknown;
    }
}

void printShapeAsString(Shape shape) {
    char circle[] = "1";
    char star_4[] = "2";
    char diamond[] = "3";
    char square[] = "4";
    char star_6[] = "5";
    char clover[] = "6";
    char unknown[] = " ";

    if (shape == CIRCLE) {
        std::cout << circle;
    } else if (shape == STAR_4) {
        std::cout << star_4;
    } else if (shape == DIAMOND) {
        std::cout << diamond;
    } else if (shape == SQUARE) {
        std::cout << square;
    } else if (shape == STAR_6) {
        std::cout << star_6;
    } else if (shape == CLOVER) {
        std::cout << clover;
    } else {
        std::cout << unknown;
    }
}