#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H 

#include "TileBag.h"
#include "LinkedList.h"

#include <string>

#define MAX_HAND_SIZE    6

/**
 * Represents a player in qwirkle.
 */
class Player {
    public:
        Player();
        Player(Player &other);
        ~Player();
        
        /**
         * Sets the initial hand for the deck using the given TileBag.
         * Keeps an internal copy of the given TileBag.
         */
        void setInitialHand(TileBag* tilebag);

        /**
         * Return the player number
         */
        std::string getPlayerName();

        /**
         * Set the player name
         */
        void setPlayerName(std::string playerName);

        /**
         * Return the player score
         */
        int getPlayerScore();

        /**
         * Returns the players hand
         */
        TileBag* getHand();

        /**
         * Returns the tile at the given index in the players hand
         */
        Tile* getATile(unsigned int index);

    private:
        std::string playerName;
        int score;

        TileBag* hand;
};

#endif // ASSIGN2_PLAYER_H