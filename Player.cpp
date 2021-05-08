#include "Player.h"
#include "Tile.h"
#include "utils.h"


Player::Player() {
    this->playerName = "Jake";
    this->score = 0;
    hand = new TileBag();
}
Player::Player(Player &other) {
    this->playerName = other.playerName;
    this->score = other.score;
    delete hand;
    hand = new TileBag(*other.hand);
}
Player::~Player() {
    hand->clear();
    delete hand;
}
    
void Player::setInitialHand(TileBag* tileBag) {
    delete hand;
    hand = new TileBag(*tileBag);
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

TileBag* Player::getHand() {
    return hand;
}

void Player::addScore(int addScore) {
    this->score = this->score + addScore;
}

Tile* Player::getATile(unsigned int index) {
    Tile* tile = nullptr;
    if(index <= hand->size()) {
        tile = new Tile(*hand->get(index));
    }
    
    return tile;
}