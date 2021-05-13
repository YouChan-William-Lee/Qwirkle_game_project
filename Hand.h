#ifndef ASSIGN2_HAND_H
#define ASSIGN2_HAND_H

#include "LinkedList.h"
#include "TileCodes.h"
#include "utils.h"
#include "Tile.h"

#include <iostream>
#include <string>

class Hand {
    public:
        Hand();
        Hand(Hand& other);
        ~Hand();

        //Return the current size of the bag
        unsigned int size();

        //Add this tile to hand
        void addTile(Tile* tile);

        //Add this tile which has tile(string) to hand
        void addTileByName(std::string tile);

        //Get a tile at the given index from the bag
        Tile* getByIndex(int index);
        
        //Return a tile which has tilename(string)
        Tile* getTilebyName(std::string tilename);

        //Remove a tile which has tilename(string)
        void removeTile(std::string tilename);

        //Removes all tiles from the bag
        //Deletes the bag
        void clear();

    private:
        LinkedList* hand;


};
#endif // ASSIGN2_HAND_H