#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include <string>
#include "Tile.h"

class Board {
    public:
    
        Board();
        Board(Board& other);
        ~Board();

        //Print current board
        void getBoard();

        //Add a tile to the bag
        void add(std::string x, Tile* tile);

        bool check(std::string x, Tile* tile, bool* first);

        void reSize(unsigned int row, unsigned int col);

        std::string getBoardSize();

        int getScore(std::string tile);

        std::string returnAllTilesinBoard(std::ostream& file);

        void setTiles(std::string tiles);

        unsigned int getBoardRow();

        unsigned int getBoardCol();

        //Removes all tiles from the bag
        //Deletes the bag
        void clear();

    private:
        std::vector< std::vector<Tile*> > board;

};
#endif // ASSIGN2_BOARD_H