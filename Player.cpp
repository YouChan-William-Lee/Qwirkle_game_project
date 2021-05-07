#include "Player.h"


Player::Player() {
    this->score = 0;
    hand = new Hand();
}

Player::Player(Player &other) {
    this->playerName = other.playerName;
    this->score = other.score;
    delete hand;
    hand = new Hand(*other.hand);
}
Player::~Player() {
    delete hand;
}
    
void Player::setInitialHand(TileBag* tileBag) {
    Tile* drawnTile;
    for (int i = 0; i < MAX_HAND_SIZE; i++) {
        drawnTile = tileBag->drawTile();
        hand->addTile(drawnTile);
    }
}

std::string Player::getPlayerName() {
    return playerName;
}

void Player::setPlayerName(std::string playerName) {
    this->playerName = playerName;
}

int Player::getPlayerScore() {
    return score;
}

Hand* Player::getHand() {
    return hand;
}