#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H

#include "LinkedList.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

class TileBag {
    public:
    
        TileBag();
        ~TileBag();

        //Returns the current size of the bag
        unsigned int size();

        //Get tile from the bag
        Tile* drawCard();

        //Add a tile to the bag
        void add(Tile* tile);

        //Remove a tile from the bag
        void remove();

        //Removes all tiles from the bag
        //Deletes the bag
        void clear();

    private:
        LinkedList* tileBag;


};
#endif // ASSIGN2_TILEBAG_H