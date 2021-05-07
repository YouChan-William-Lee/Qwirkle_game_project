#ifndef ASSIGN2_UTILS_H
#define ASSIGN2_UTILS_H

#include "Tile.h"
#include <string>

class LinkedList;

void printTile(Tile* tile);
void printColourAsString(Colour colour);
void printShapeAsString(Shape shape);

Tile* getTileFromString(std::string string);

char getRowFromString(std::string string);
long unsigned int getColFromString(std::string string);

#endif // ASSIGN2_UTILS_H