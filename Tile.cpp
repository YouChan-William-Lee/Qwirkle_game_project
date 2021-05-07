#include "Tile.h"

Tile::Tile() {
    this->colour = ' ';
    this->shape = 0;
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

void Tile::setColour(Colour colour) {
    this->colour = colour;
}

void Tile::setShape(Shape shape) {
    this->shape = shape;
}