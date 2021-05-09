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

        //Returns the current size of the bag
        unsigned int size();

        //Get tile from the bag
        Tile* drawTile();

        //Add a tile to the bag
        void add(Tile* tile);

        void addTileByName(std::string tile);

        //Remove a tile from the bag
        void remove();

        //Get a tile at the given index from the bag
        Tile* get(int index);
        
        Tile* getTilebyName(std::string tilename);

        bool removeTile(Tile* tile);

        void removeTile(std::string tilename);

        void addTile(Tile* tile);

        //Removes all tiles from the bag
        //Deletes the bag
        void clear();

    private:
        LinkedList* hand;


};
#endif // ASSIGN2_HAND_H