#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include "Tile.h"

#include <stdexcept>

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(LinkedList& other);

        //Get a size of LinkedList
        unsigned int size();

        //Get a tile at the front
        Tile* getfront();

        //Add a Tile at the front
        void add_front(Tile* tile);

        //Add a Tile at the back
        void add_back(Tile* tile);

        //Remove a Tile at the front
        void remove_front();

        //Remove a Tile at the back
        void remove_back();

        //Get a tile which has tile(string)
        Tile* find_tile(std::string tile);

        //Get atile at given index
        Tile* getByIndex(unsigned int index);
        
        //Remove A tile at given index
        void remove(int index);

        //Remove a tile which has tile(string)
        void remove_tile(std::string tile);

        // Clear LinkedList
        void clear();

    private:
        Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H