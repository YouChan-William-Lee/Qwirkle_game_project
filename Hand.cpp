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

void Hand::removeTile(Tile* tile) {
    hand->remove(tile);
}

void Hand::displayTiles() {
    hand->print();
}