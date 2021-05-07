#ifndef ASSIGN2_HAND_H
#define ASSIGN2_HAND_H
#include "LinkedList.h"

class Hand {
    public:
        Hand();
        Hand(Hand& other);
        ~Hand();


        //Get a tile from the hand
        Tile* getTile(Tile* tile);

        //Add a tile to the hand
        void addTile(Tile* tile);

        //Remove tile from hand
        bool removeTile(Tile* tile);

        //Return a tile if exists
        Tile* getTilebyName(std::string tilename);

        void removeTile(std::string tilename);

        //Show all tiles in hand
        void displayTiles();

        //Return hand size
        int getSize();

    private:
        LinkedList* hand;    
};

#endif // ASSIGN2_HAND_H
