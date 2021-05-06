#include "TileBag.h"
#include "utils.h"

TileBag::TileBag() {
    tileBag = new LinkedList();
}

TileBag::TileBag(TileBag& other) {
    tileBag = new LinkedList(*other.tileBag);
}

TileBag::~TileBag() {
    clear();
    delete tileBag;
    tileBag = nullptr;
}

void TileBag::makeTiles() {
    char colours[NUM_OF_COLOURS] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    char shapes[NUM_OF_SHAPES] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};

    std::vector<Tile*> allTiles;

    for (int i = 0; i < NUM_OF_COLOURS; ++i){
        for (int j = 0; j < NUM_OF_SHAPES; ++j){
            Tile* tile1 = new Tile(colours[j], shapes[i]);
            Tile* tile2 = new Tile(colours[j], shapes[i]);
            allTiles.push_back(new Tile(*tile1));
            allTiles.push_back(new Tile(*tile2));
            delete tile1;
            delete tile2;
        }
    }
    unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
    std::shuffle(std::begin(allTiles), std::end(allTiles), std::default_random_engine(seed));
    for (unsigned int i = 0; i < allTiles.size(); i++){
        tileBag->add_back(new Tile(*allTiles[i]));
    }

    for (int i = 0; i < MAX_SIZE_TILE; ++i){
        delete allTiles[i];
        allTiles[i] = nullptr;
    }
    allTiles.clear();
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

void TileBag::clear() {
    tileBag->clear();
}
