#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H

#include "LinkedList.h"
#include "TileCodes.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

class TileBag {
    public:
    
        TileBag();
        TileBag(TileBag& other);
        ~TileBag();

        //Shuffle 72 tiles
        void makeTiles();

        //Returns the current size of the bag
        int size();

        //Get tile from the bag
        Tile* drawTile();

        //Add a tile to the bag
        void add(Tile* tile);

        //Remove a tile from the bag
        void remove();

    private:
        LinkedList* tileBag;


};
#endif // ASSIGN2_TILEBAG_H