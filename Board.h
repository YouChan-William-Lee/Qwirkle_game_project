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

        //Check if tile can be put on the location(x)
        bool check(std::string x, Tile* tile, bool* first);

        //Resize the board size
        void reSize(unsigned int row, unsigned int col);

        //Return the board size (row,col)
        std::string getBoardSize();

        //Retrun the score of the tile which player just put
        int getScore(std::string tile);

        //Return all tiles in the board
        std::string returnAllTilesinBoard(std::ostream& file);

        //Set tile's colour and shape with tile(string)
        void setTiles(std::string tile);

        //Return row size of the board
        unsigned int getBoardRow();

        //Return col size of the board
        unsigned int getBoardCol();

        //Check if there is any tile on the board
        bool tileOnTheBoard();

        //Removes all tiles from the bag
        //Deletes the bag
        void clear();

    private:
        std::vector< std::vector<Tile*> > board;

};
#endif // ASSIGN2_BOARD_H