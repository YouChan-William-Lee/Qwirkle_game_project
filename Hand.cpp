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

Tile* Hand::getTilebyName(std::string tilename) {
    return hand->find_tile(tilename);
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

void Hand::removeTile(std::string tilename) {
    hand->remove_tile(tilename);
}

int Hand::getSize() {
    return hand->getsize();
}

void Hand::displayTiles() {
    hand->print();
}