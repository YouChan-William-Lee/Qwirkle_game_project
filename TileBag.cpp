#include "TileBag.h"
#include "utils.h"

TileBag::TileBag() {
    tileBag = new LinkedList();
}

TileBag::TileBag(TileBag& other) {
    tileBag = new LinkedList(*other.tileBag);
}

TileBag::~TileBag() {
    delete tileBag;
}

void TileBag::makeTiles() {
    char colours[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    std::vector<Tile*> allTiles;
    for (int i = 1; i < 7; i++){
        for (int k = 0; k < 6; k++){
            Tile* tile = new Tile(colours[k], i);
            allTiles.push_back(tile);
            allTiles.push_back(tile);
            tile->~Tile();
        }
    }
    unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
    std::shuffle(std::begin(allTiles), std::end(allTiles), std::default_random_engine(seed));
    for (unsigned int i = 0; i < allTiles.size(); i++){
        tileBag->add_back(allTiles[i]);
    }
}

unsigned int TileBag::size() {
    return tileBag->size();
}


void TileBag::add(Tile* tile) {
    tileBag->add_back(tile);
}

Tile* TileBag::drawCard() {
    Tile* returnTile = new Tile(*tileBag->getfront());
    tileBag->remove_front();
    return returnTile;
}

Tile* TileBag::get(int index) {
    return tileBag->get(index);
}
