#include "Tile.h"

Tile::Tile() {
}

Tile::Tile(Tile& other) {
    this->colour = other.colour;
    this->shape = other.shape;
}

Tile::~Tile() {
}

Colour Tile::getTile() {
    return colour;
}

Shape Tile::getShape() {
    return shape;
}