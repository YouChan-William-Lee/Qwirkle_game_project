#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

#define NUM_OF_STUDENT 4
#define NUM_OF_STUDENT_INFO 3

#include "LinkedList.h"
#include "TileBag.h"
#include "Player.h"
#include "Tile.h"
#include "TileCodes.h"
#include "utils.h"
#include "Board.h"

void welcomeMessage();
void mainMenu();
void setupGame(TileBag* tilebag, Player* player1, Player* player2);
void newGame(Player* player1, Player* player2);
void playTheGame(TileBag* tilebag, Board* board, Player* player1, Player* player2, int currentPlayer);
int player_turn(Board* board, TileBag* TileBag, Player* p_turn, Player* p_wait, bool* first);
void loadupGame();
void credits();
void cleanupGame();


int main(int argc, char** argv) {
    welcomeMessage();
    
    bool play = true;

    while(play) {
        mainMenu();
        std::string menu = "";
        std::cin >> menu;

        if(menu >= "1" && menu <= "4") {
            if(menu == "1") {

            // Make a new TileBag
            TileBag* tileBag = new TileBag();
            tileBag->makeTiles();

            // Make a new Board    
            Board* board = new Board();

            // Create two players
            Player* player1 = new Player();
            Player* player2 = new Player();

            setupGame(tileBag, player1, player2);


            playTheGame(tileBag, board, player1, player2, 1);

            delete tileBag;
            delete board;
            delete player1;
            delete player2;

            play = false;

            //end of test
            } 
            else if(menu == "2") {
                // loadupGame(deckFilename, deck, player1);
            } 
            else if(menu == "3") {
                credits();
            } 
            else {
                play = false;
                std::cout << std::endl;
                std::cout << "Goodbye" << std::endl;
            } 
        }
        else {
            std::cout << "Invalid input" << std::endl;
        }
    }

    // Cleanup - delete all the objects
    // cleanupGame(deck, player1);

    return EXIT_SUCCESS;
}

// Display welcome message
void welcomeMessage() {
    std::cout << "Welcome to Qwirkle!" << std::endl;
    std::cout << "-------------------" << std::endl;
}

// Display main menu
void mainMenu() {
    std::cout << std::endl;
    std::cout << "Menu" << std::endl;
    std::cout << "----" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Credits (Show student information)" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "> ";
}

void setupGame(TileBag* tileBag, Player* player1, Player* player2) {
    // Set players' name
    newGame(player1, player2);

    // Set player1 hand
    player1->setInitialHand(tileBag);

    //Set player2 hand
    player2->setInitialHand(tileBag);
}

void newGame(Player* player1, Player* player2) {
    std::cout << "Starting a New Game" << std::endl;
    std::cout << std::endl;
    
    bool AllUpper = true;
    std::string name;
    while(!std::cin.eof() && AllUpper) {
        std::cout << "Enter a name for player 1 (uppercase characters only)" << std::endl;
        std::cout << "> ";

        std::cin >> name;
        for (long unsigned int i = 0; i < name.length() && AllUpper; ++i){
            if(!isupper(name[i])) {
                AllUpper = false;
                std::cout << "Invalid input" << std::endl;
                std::cout << std::endl;
            }
        }
        if(AllUpper) {
            player1->setPlayerName(name);
            AllUpper = false;
        }
        else {
            AllUpper = true;
        }
    }

    std::cout << std::endl;

    AllUpper = true;
    while(AllUpper) {
        std::cout << "Enter a name for player 2 (uppercase characters only)" << std::endl;
        std::cout << "> ";
        
        std::cin >> name;
        for (long unsigned int i = 0; i < name.length() && AllUpper; ++i){
            if(!isupper(name[i])) {
                AllUpper = false;
                std::cout << "Invalid input" << std::endl;
                std::cout << std::endl;
            }
        }
        if(AllUpper) {
            player2->setPlayerName(name);
            AllUpper = false;
        }
        else {
            AllUpper = true;
        }
    }
    
    std::cout << std::endl;
    std::cout << "Let's Play!" << std::endl;
    std::cout << std::endl;
}

void playTheGame(TileBag* tilebag, Board* board, Player* player1, Player* player2, int currentPlayer) {

    //variable to keep the loop running
    //current loop will run for 2 turns
    //remove when u implement win game

    // bool looptest = true;
    // while (looptest) {
    //     if (currentPlayer == 1) {
    //         bool actionSuccess = false;
    //         std::string userAction;
    //         std::string userTile;
    //         std::string userLocation;
    //         std::string userCoordinate;
    //         std::cout << player1->getPlayerName() << ", it's your turn" << std::endl;
    //         std::cout << "Score for " << player1->getPlayerName() << ": " << player1->getPlayerScore() << std::endl;
    //         std::cout << "Score for " << player2->getPlayerName() << ": " << player2->getPlayerScore() << std::endl;

    //         // PRINT BOARD
    //         std::cout << std::endl;
    //         board->getBoard();

    //         std::cout << std::endl;
    //         std::cout << "Your hand is" << std::endl;
    //         player1->getHand()->displayTiles();

    //         while (!actionSuccess) {
    //             std::cout << std::endl;
    //             std::cout << "> ";
    //             std::cin >> userAction;
    //             std::cin >> userTile;
    //             std::cin >> userLocation;
    //             std::cin >> userCoordinate;
    //             if (userAction.compare("place") == 0) {
    //                 Tile* tileToPlace = getTileFromString(userTile);
    //                 bool success = player1->getHand()->removeTile(tileToPlace);
    //                 if (success && userLocation.compare("at") == 0) {
    //                     actionSuccess = true;
    //                     std::cout << "entered" << std::endl;
    //                     // board->add(tileToPlace, getRowFromString(userCoordinate), 
    //                     //             getColFromString(userCoordinate));
    //                 } else {
    //                     actionSuccess = false;
    //                 }
    //             }
    //             if (!actionSuccess) {
    //                 std::cout << "Invalid command. Please re-enter" << std::endl;
    //             }

    //         }
    //         currentPlayer = 2;
    //     }
    //     if (currentPlayer == 2) {
    //         bool actionSuccess = false;
    //         std::string userAction;
    //         std::string userTile;
    //         std::string userLocation;
    //         std::string userCoordinate;
    //         std::cout << player2->getPlayerName() << ", it's your turn" << std::endl;
    //         std::cout << "Score for " << player1->getPlayerName() << ": " << player1->getPlayerScore() << std::endl;
    //         std::cout << "Score for " << player2->getPlayerName() << ": " << player2->getPlayerScore() << std::endl;

    //         // PRINT BOARD HERE
    //         std::cout << std::endl;
    //         board->getBoard();

    //         std::cout << std::endl;
    //         std::cout << "Your hand is" << std::endl;
    //         player2->getHand()->displayTiles();

    //         while (!actionSuccess) {
    //             std::cout << std::endl;
    //             std::cout << ">";
    //             std::cin >> userAction;
    //             std::cin >> userTile;
    //             std::cin >> userLocation;
    //             std::cin >> userCoordinate;
    //             if (userAction.compare("place") == 0) {
    //                 Tile* tileToPlace = getTileFromString(userTile);
    //                 bool success = player2->getHand()->removeTile(tileToPlace);
    //                 if (success && userLocation.compare("at") == 0) {
    //                     actionSuccess = true;
    //                     std::cout << "entered" << std::endl;
    //                     // board->add(tileToPlace, getRowFromString(userCoordinate), 
    //                     //             getColFromString(userCoordinate));
    //                 } else {
    //                     actionSuccess = false;
    //                 }
    //             }
    //             if (!actionSuccess) {
    //                 std::cout << "Invalid command. Please re-enter" << std::endl;
    //             }

    //         }
    //         currentPlayer = 2;
    //         looptest = false;
    //     }
    // }

	int turn = 0;
    bool value = false;
    bool* first = &value;
	while (!std::cin.eof() && tilebag->size() != 0 && player1->getHand()->getSize() != 0 && player2->getHand()->getSize() != 0) {

		board->getBoard();
		if (turn == 0) {
			turn += player_turn(board, tilebag, player1, player2, first);
		}
		else {
			turn += player_turn(board, tilebag, player2, player1, first);
		}
		turn %= 2;
	}
}

int player_turn(Board* board, TileBag* TileBag, Player* p_turn, Player* p_wait, bool* first) {
    int flag = 0;
    std::cout << std::endl;
	std::cout << p_turn->getPlayerName() << ", it's your turn" << std::endl;
    std::cout << "Score for " << p_turn->getPlayerName() << ": " << p_turn->getPlayerScore() << std::endl;;
	std::cout << "Score for " << p_wait->getPlayerName() << ": " << p_wait->getPlayerScore() << std::endl;;
    p_turn->getHand()->displayTiles();

	std::string command, tile, at, location;
    std::cout << std::endl;
	std::cout << "> ";
	std::cin >> command >> tile;
	if (command == "replace") {
		Tile* t = new Tile(*p_turn->getHand()->getTilebyName(tile));
        if (t != nullptr) {
            TileBag->add(t);
            p_turn->getHand()->removeTile(t);
            p_turn->getHand()->addTile(TileBag->drawTile());
            std::cout << std::endl;
        }
        else {
            std::cout << "Ivalid input" << std::endl;
        }
	}
	else if (command == "place") {
		std::cin >> at >> location;
		Tile* t = new Tile(*p_turn->getHand()->getTilebyName(tile));
		if (t != nullptr) {
			if (board->check(location, t, first)) {
				board->add(location, t);
				p_turn->getHand()->removeTile(tile);
                p_turn->getHand()->addTile(TileBag->drawTile());
                std::cout << std::endl;
                // check if first tile exists on the board
                if (*first == false) {
                    *first = true;
                }
                // Couldn't implement score yet
				//score += board->getScore(loc);
				flag = 1;
			}
			else {
				std::cout << "Cannot put the tile at " << location << std::endl;
                std::cout << std::endl;
			}
		}
		else {
			std::cout << "Please enter correct Tile" << std::endl;
            std::cout << std::endl;
		}
	}
	else {
		std::cout << "Please enter a correct command " << std::endl;
        std::cout << std::endl;
	}
	return flag;
}

//HAVEN"T IMPLEMENTED
void loadupGame() {

}

void credits() {
    std::string students[NUM_OF_STUDENT][NUM_OF_STUDENT_INFO] = {
        {"Dunith Nadvi Karawita", "s3823697", "s3823697@student.rmit.edu.au"},
        {"Matthew Radin","s3334605","s3334605@student.rmit.edu.au"},
        {"Trang Nguyen","s3828554","s3828554@student.rmit.edu.au"},
        {"You Chan Lee","s3850825","s3850825@student.rmit.edu.au"}
        };
    
    std::cout << std::endl;
    std::cout << "-----------------------------------" << std::endl; 
    for(int i = 0; i < NUM_OF_STUDENT; ++i) {
        for(int j = 0; j < NUM_OF_STUDENT_INFO; ++j) {
            if(j == 0) {
                std::cout << "Name: ";
            }
            else if(j == 1) {
                std::cout << "Student ID: ";
            }
            else {
                std::cout << "Email: ";
            }
            std::cout << students[i][j] << std::endl;
        }
        if(i != NUM_OF_STUDENT - 1) {
            std::cout << std::endl;
        }
    }
    std::cout << "-----------------------------------" << std::endl; 
}