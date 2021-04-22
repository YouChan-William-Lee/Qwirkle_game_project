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

    unsigned int size();

    Tile* get(unsigned index);

    void add_front(Tile* tile);
    void add_back(Tile* tile);

    void remove_front();
    void remove_back();
    
    void remove(int index);
    void clear();

private:
    Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H