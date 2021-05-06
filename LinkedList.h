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

        // Get a size of LinkedList
        unsigned int size();

        // Get a Tile at given index
        Tile* get(unsigned index);
        Tile* getfront();

        // Add a Tile at the front
        void add_front(Tile* tile);

        // Add a Tile at the back
        void add_back(Tile* tile);

        // Remove a Tile at the front
        void remove_front();

        // Remove a Tile at the back
        void remove_back();
        
        // Remove A tile at given index
        void remove(int index);

        // Clear LinkedList
        void clear();

    private:
        Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H