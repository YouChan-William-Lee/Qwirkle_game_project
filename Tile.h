#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

#include "TileCodes.h"

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {

   public:
      Colour colour;
      Shape shape;
      
      Tile();
      Tile(Colour, Shape);
      Tile(Tile& other);
      ~Tile();

      //Get colour
      Colour getColour();

      //Get shape
      Shape getShape();

      //Set colour
      void setColour(Colour colour);

      //Set shape
      void setShape(Shape shape);
};



#endif // ASSIGN2_TILE_H