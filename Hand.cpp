#include "Hand.h"
#include "utils.h"

Hand::Hand() {
    hand = new LinkedList();
}

Hand::Hand(Hand& other) {
    hand = new LinkedList(*other.hand);
}

Hand::~Hand() {
    hand->clear();
    delete hand;
}

Tile* Hand::getTile(Tile* tile) {
    return hand->getByTile(tile);
}

void Hand::addTile(Tile* tile) {
    hand->add_back(tile);
}

bool Hand::removeTile(Tile* tile) {
    bool success = hand->remove(tile);
    if (success == false) {
        std::cout << "Tile not in hand" << std::endl;
    }
    return success;
}

void Hand::displayTiles() {
    hand->print();
}