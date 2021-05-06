#include "Tile.h"

Tile::Tile() {
    this->colour = ' ';
    this->shape = ' ';
}

Tile::Tile(Colour colour, Shape shape) {
    this->colour = colour;
    this->shape = shape;
}

Tile::Tile(Tile& other) {
    this->colour = other.colour;
    this->shape = other.shape;
}

Tile::~Tile() {
}