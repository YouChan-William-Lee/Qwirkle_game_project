#ifndef ASSIGN2_UTILS_H
#define ASSIGN2_UTILS_H

#include "Tile.h"
#include "Board.h"
#include "TileBag.h"
#include "TileCodes.h"

void printHand(std::ostream& file, TileBag* tileBag);
void printTile(std::ostream& output,Tile* tile);
void printColourAsString(std::ostream& output,Colour colour);
void printShapeAsString(std::ostream& output,Shape shape);
void printTileBag(std::ostream& file, TileBag* tileBag);

#endif // ASSIGN2_UTILS_H