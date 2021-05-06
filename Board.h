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

        //Add a tile to the bag
        void add(Tile* tile, std::string row, int col);

        //Removes all tiles from the bag
        //Deletes the bag
        void clear();

    private:
        std::vector< std::vector<Tile*> > board;

};
#endif // ASSIGN2_BOARD_H