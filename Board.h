#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include "Tile.h"

class Board {
    public:
    
        Board();
        Board(Board& other);
        ~Board();

        //Print current board
        void getBoard();

        bool check(std::string x, Tile* tile, bool* first);

        //Add a tile to the bag
        void add(std::string x, Tile* tile);

        //Removes all tiles from the bag
        //Deletes the bag
        void clear();

    private:
        std::vector< std::vector<Tile*> > board;

};
#endif // ASSIGN2_BOARD_H