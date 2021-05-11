#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H

#include "LinkedList.h"
#include "TileCodes.h"
#include "utils.h"

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <string>

class TileBag {
    public:
        TileBag();
        TileBag(TileBag& other);
        ~TileBag();

        //Shuffle 72 tiles
        void makeTiles();

        //Return the current size of the bag
        unsigned int size();
        
        //Add this tile which has tile(string) to the bag
        void addTileByName(std::string tile);

        //Get tile from the bag
        Tile* drawTile();

        //Get a tile at the given index from the bag
        Tile* getByIndex(int index);

        //Get a tile which has tilename(string)
        Tile* getTilebyName(std::string tilename);

        //Remove a tile which has tilename(string)
        void removeTile(std::string tilename);

        //Add this tile to the bag
        void addTile(Tile* tile);

        //Removes all tiles from the bag
        //Deletes the bag
        void clear();

    private:
        LinkedList* tileBag;


};
#endif // ASSIGN2_TILEBAG_H