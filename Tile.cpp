#include "Tile.h"

Tile::Tile() {
    this->colour = EMPTY_TILE;
    this->shape = EMPTY_TILE;
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

Colour Tile::getColour() {
    return colour;
}

Shape Tile::getShape() {
    return shape;
}

void Tile::setColour(Colour colour) {
    this->colour = colour;
}

void Tile::setShape(Shape shape) {
    this->shape = shape;
}