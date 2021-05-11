#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H 

#include "LinkedList.h"
#include "Hand.h"

#include <string>

#define MAX_HAND_SIZE    6

//Represents a player in qwirkle
class Player {
    public:
        Player();
        Player(Player &other);
        ~Player();
        
        //Set the initial hand for the deck using the given Hand.
        //Keep an internal copy of the given Hand.
        void setInitialHand(Hand* hand);

        //Return the player's name
        std::string getPlayerName();

        //Set the player's name
        void setPlayerName(std::string playerName);

        //Return the player's score
        int getPlayerScore();

        //Return the player's hand
        Hand* getHand();

        //Update player's score
        void addScore(int addScore);

        //Return the tile at the given index in the player's hand
        Tile* getATile(unsigned int index);

    private:
        std::string playerName;
        int score;
        Hand* hand;
};

#endif // ASSIGN2_PLAYER_H