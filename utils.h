#ifndef ASSIGN2_UTILS_H
#define ASSIGN2_UTILS_H

#include "Tile.h"
#include "Board.h"
#include "TileCodes.h"

class TileBag;
class Hand;

//Print all tiles in player's hand
void printHand(std::ostream& file, Hand* hand);

//Print all tiles in TileBag
void printTileBag(std::ostream& file, TileBag* tileBag);

//Print a tile
void printTile(std::ostream& output,Tile* tile);

//Change colour to string and print it
void printColourAsString(std::ostream& output,Colour colour);

//Change shape to string and print it
void printShapeAsString(std::ostream& output,Shape shape);

//Change c(string) to colour(Colour)
Colour changeStringToColour(std::string c);

//Change s(string) to shape(Shape)
Shape changeStringToShape(std::string s);

#endif // ASSIGN2_UTILS_H