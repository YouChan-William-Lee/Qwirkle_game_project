#include "Hand.h"

Hand::Hand() {
    hand = new LinkedList();
}

Hand::Hand(Hand& other) {
    hand = new LinkedList(*other.hand);
}

Hand::~Hand() {
    clear();
    delete hand;
    hand = nullptr;
}

unsigned int Hand::size() {
    return hand->size();
}

void Hand::addTile(Tile* tile) {
    hand->add_back(tile);
}

void Hand::addTileByName(std::string tile) {
    std::string str1(1, tile[0]);
    Colour colour = changeStringToColour(str1);
    std::string str2(1, tile[1]);
    Shape shape = changeStringToShape(str2);
    Tile* newtile = new Tile(colour, shape);
    hand->add_back(new Tile(*newtile));
    delete newtile;
}

Tile* Hand::getByIndex(int index) {
    return hand->getByIndex(index);
}

Tile* Hand::getTilebyName(std::string tilename) {
    return hand->find_tile(tilename);
}

void Hand::removeTile(std::string tilename) {
    hand->remove_tile(tilename);
}

void Hand::clear() {
    hand->clear();
}