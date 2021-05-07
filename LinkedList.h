#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include "Tile.h"
#include "utils.h"

#include <stdexcept>
#include <iostream>

class LinkedList {
    public:

        LinkedList();
        ~LinkedList();
        LinkedList(LinkedList& other);

        // Get a size of LinkedList
        int getsize();

        // Get a specified tile
        Tile* getByTile(Tile* tile);

        //Get a tile at a specified index
        Tile* getByIndex(int index);
        Tile* getfront();

        //Find a tile by string tile name
        Tile* find_tile(std::string tile);

        // Add a Tile at the front
        void add_front(Tile* tile);

        // Add a Tile at the back
        void add_back(Tile* tile);

        // Remove a Tile at the front
        void remove_front();

        // Remove a Tile at the back
        void remove_back();

        void remove(int index);

        void remove_tile(std::string x);
        
        // Remove a specified tile
        bool remove(Tile* tile);

        // Clear LinkedList
        void clear();

        //Print all the elements in the linkedlist
        void print();

    private:
        Node* head;
        int size;
};

#endif // ASSIGN2_LINKEDLIST_H