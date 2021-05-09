#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <sstream>

#define NUM_OF_STUDENT 4
#define NUM_OF_STUDENT_INFO 3
#define LOAD_FILE_LINES 10

#include "LinkedList.h"
#include "TileBag.h"
#include "Player.h"
#include "Tile.h"
#include "TileCodes.h"
#include "utils.h"
#include "Board.h"
#include "Hand.h"

void welcomeMessage();
void goodbyeMessage();
void mainMenu();
void setupGame(TileBag* tilebag, Player* player1, Player* player2);
void newGame(Player* player1, Player* player2);
void playTheGame(TileBag* tilebag, Board* board, Player* player1, Player* player2);
int player_turn(Board* board, TileBag* TileBag, Player* p_turn, Player* p_wait, bool* first);
bool loadupGame(TileBag* tilebag, Board* board, Player* player1, Player* player2);
void cleanupGame(TileBag* tileBag, Board* board, Player* player1, Player* player2);
void invalidInput();
void credits();
void cleanupGame();


int main(int argc, char** argv) {
    welcomeMessage();
    
    bool play = true;

    while(!std::cin.eof() && play) {
        mainMenu();

        // LinkedList* list = new LinkedList();

        std::string menu = "";
        std::cin >> menu;

        if(menu >= "1" && menu <= "4") {
            if(menu == "1") {
                // setupGame(deck, player1, player2);
                //testing tileBag implementation
                //remove later

                // Make a new TileBag
                TileBag* tileBag = new TileBag();
                tileBag->makeTiles();

                // Make a new Board    
                Board* board = new Board();

                // Create two players
                Player* player1 = new Player();
                Player* player2 = new Player();

                setupGame(tileBag, player1, player2);
                //TESTED UNTIL HERE

                playTheGame(tileBag, board, player1, player2);

                cleanupGame(tileBag, board, player1, player2);

                play = false;
            } 
            else if(menu == "2") {
                // Make a new TileBag
                TileBag* tileBag = new TileBag();

                // Make a new Board    
                Board* board = new Board();

                // Create two players
                Player* player1 = new Player();
                Player* player2 = new Player();

                if(loadupGame(tileBag, board, player1, player2)) {
                    playTheGame(tileBag, board, player1, player2);
                    play = false;
                }

                cleanupGame(tileBag, board, player1, player2);               
            } 
            else if(menu == "3") {
                credits();
            } 
            else {
                play = false;
            } 
        }
        else {
            invalidInput();
        }
    }

    goodbyeMessage();

    return EXIT_SUCCESS;
}

void goodbyeMessage() {
    std::cout << "Goodbye" << std::endl;
}

// Display welcome message
void welcomeMessage() {
    std::cout << "Welcome to Qwirkle!" << std::endl;
    std::cout << "-------------------" << std::endl;
}

// Display invalid input message
void invalidInput() {
    std::cout << "Invalid input" << std::endl;
    std::cout << std::endl;
}

// Delete all the objects
void cleanupGame(TileBag* tileBag, Board* board, Player* player1, Player* player2) {
    delete tileBag;
    tileBag = nullptr;
    delete board;
    board = nullptr;
    delete player1;
    player1 = nullptr;
    delete player2; 
    player2 = nullptr;
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

// Set up player's hand
void setupGame(TileBag* tileBag, Player* player1, Player* player2) {
    // Set players' name
    newGame(player1, player2);
    
    // Create 2 new temporary Hands
    Hand* initialHand1 = new Hand();
    Hand* initialHand2 = new Hand();

    // Set player1 hand
    int i = 0;
    while (i < MAX_HAND_SIZE) {
        initialHand1->add(tileBag->drawTile());  
        ++i;
    }
    player1->setInitialHand(initialHand1);
    delete initialHand1;

    // Set player2 hand
    i = 0;
    while (i < MAX_HAND_SIZE) {
        initialHand2->add(tileBag->drawTile());   
        ++i;
    }
    player2->setInitialHand(initialHand2);
    delete initialHand2;
}

// Set up player's info
void newGame(Player* player1, Player* player2) {
    std::cout << "Starting a New Game" << std::endl;
    std::cout << std::endl;
    
    bool AllUpper = true;
    std::string name;
    while(!std::cin.eof() && AllUpper) {
        std::cout << "Enter a name for player 1 (uppercase characters only)" << std::endl;
        std::cout << "> ";

        std::cin >> name;
        for (unsigned int i = 0; i < name.length() && AllUpper; ++i){
            if(!isupper(name[i])) {
                AllUpper = false;
                invalidInput();
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
    while(!std::cin.eof() && AllUpper) {
        std::cout << "Enter a name for player 2 (uppercase characters only)" << std::endl;
        std::cout << "> ";
        
        std::cin >> name;
        for (unsigned int i = 0; i < name.length() && AllUpper; ++i){
            if(!isupper(name[i])) {
                AllUpper = false;
                invalidInput();
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

// Player the game
void playTheGame(TileBag* tilebag, Board* board, Player* player1, Player* player2) {
    int turn = 0;
    bool value = false;
    bool* first = &value;
	while (!std::cin.eof() && tilebag->size() != 0 && player1->getHand()->size() != 0 && player2->getHand()->size() != 0) {

		board->getBoard();
		if (turn == 0) {
			turn += player_turn(board, tilebag, player1, player2, first);
		}
		else {
			turn += player_turn(board, tilebag, player2, player1, first);
		}
		turn %= 2;
	}
    std::cout << "Game over" << std::endl;
    std::cout << "Score for " << player1->getPlayerName() << ": " << player1->getPlayerScore() << std::endl;
    std::cout << "Score for " << player2->getPlayerName() << ": " << player2->getPlayerScore() << std::endl;
    if(player1->getPlayerScore() > player2->getPlayerScore()) {
        std::cout << "Player " << player1->getPlayerName() << " won!" << std::endl;
    }
    else if(player1->getPlayerScore() < player2->getPlayerScore()) {
        std::cout << "Player " << player2->getPlayerName() << " won!" << std::endl;
    }
    else {
        std::cout << "Draw!" << std::endl;
    }
}

// Player place a tile on the board or replace a tile or save this game
int player_turn(Board* board, TileBag* TileBag, Player* p_turn, Player* p_wait, bool* first) {
    int flag = 0;
    std::cout << std::endl;
	std::cout << p_turn->getPlayerName() << ", it's your turn" << std::endl;
    std::cout << "Score for " << p_turn->getPlayerName() << ": " << p_turn->getPlayerScore() << std::endl;;
	std::cout << "Score for " << p_wait->getPlayerName() << ": " << p_wait->getPlayerScore() << std::endl;;
    printHand(std::cout, p_turn->getHand());

	std::string command, tile, at, location;
    std::cout << std::endl;
	std::cout << "> ";
	std::cin >> command >> tile;
	if (command == "replace") {
        if(p_turn->getHand()->getTilebyName(tile) != nullptr) {
            Tile* t = new Tile(*p_turn->getHand()->getTilebyName(tile));
            TileBag->add(t);
            p_turn->getHand()->removeTile(tile);
            Tile* tile = TileBag->drawTile();
            if(tile != nullptr) {
                p_turn->getHand()->addTile(tile);
            }
            std::cout << std::endl;
        }
        else {
            invalidInput();
        }
	}
	else if (command == "place") {
		std::cin >> at >> location;
        if(p_turn->getHand()->getTilebyName(tile) != nullptr) {
            Tile* t = new Tile(*p_turn->getHand()->getTilebyName(tile));

            if (board->check(location, t, first)) {
                board->add(location, t);
                p_turn->getHand()->removeTile(tile);
                Tile* tile = TileBag->drawTile();
                if(tile != nullptr) {
                    p_turn->getHand()->addTile(tile);
                }
                p_turn->addScore(board->getScore(location));
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
                invalidInput();
            }
            delete t;
        }
		else {
            invalidInput();
        }
	}
	else if (command == "save") {
        //Save a game
        tile = tile + ".txt";
		std::ofstream saveFile(tile);
        saveFile << p_turn->getPlayerName() << std::endl;
        saveFile << p_turn->getPlayerScore() << std::endl;
        printHand(saveFile, p_turn->getHand());
        saveFile << std::endl;
        saveFile << p_wait->getPlayerName() << std::endl;
        saveFile << p_wait->getPlayerScore() << std::endl;
        printHand(saveFile, p_wait->getHand());
        saveFile << std::endl;
        saveFile << board->getBoardSize() << std::endl;
        board->returnAllTilesinBoard(saveFile);
        saveFile << std::endl;
        printTileBag(saveFile, TileBag);
        saveFile << std::endl;
        saveFile << p_turn->getPlayerName() << std::endl;

        saveFile.close();
        std::cout << std::endl;
        std::cout << "Game successfully saved" << std::endl;
        std::cout << std::endl;
	}
    else {
        invalidInput();
    }
	return flag;
}

// Load existent savefile
bool loadupGame(TileBag* tilebag, Board* board, Player* player1, Player* player2) {
    bool loadSuccess = false;
    std::cout << std::endl;
    std::cout << "Enter the filename from which load a game" << std::endl;
    std::cout << "> ";

    //Take the file name
    std::string filename;
    std::cin >> filename;

    std::string Filename = filename + ".txt";
    std::ifstream file(Filename);

    //Check if the file exists
    if(!file)
    {
        invalidInput();
    }
    else {
        //Read player1 name
        std::string player1name = "";
        std::getline(file, player1name);
        player1->setPlayerName(player1name);

        //Read player1 score
        std::string player1score = "";
        std::getline(file, player1score);
        player1->addScore(std::stoi(player1score));

        //Read player1 hand
        std::string player1hand = "";
        std::getline(file, player1hand);
        std::stringstream ss1(player1hand);
        Hand* initialHand1 = new Hand();
        
        while (ss1.good()) {
            std::string substr;
            getline(ss1, substr, ',');
            initialHand1->addTileByName(substr);
        }
        player1->setInitialHand(initialHand1);
        delete initialHand1;

        //Read player2 name
        std::string player2name = "";
        std::getline(file, player2name);
        player2->setPlayerName(player2name);

        //Read player2 score
        std::string player2score = "";
        std::getline(file, player2score);
        player2->addScore(std::stoi(player2score));

        //Read player2 hand
        std::string player2hand = "";
        std::getline(file, player2hand);
        std::stringstream ss2(player2hand);
        Hand* initialHand2 = new Hand();
        
        while (ss2.good()) {
            std::string substr;
            getline(ss2, substr, ',');
            initialHand2->addTileByName(substr);
        }
        player2->setInitialHand(initialHand2);
        delete initialHand2;

        //Read board size
        std::string boardsize;
        std::getline(file, boardsize);
        std::stringstream ss3(boardsize);  
        int boardRowCol[2] = {};      
        int i = 0;
        while (ss3.good()) {
            std::string substr;
            getline(ss3, substr, ',');
            boardRowCol[i] = std::stoi(substr);
            ++i;
        }

        board->reSize(boardRowCol[0], boardRowCol[1]);

        //Read tiles in board
        std::string tilesInBoard;
        std::getline(file, tilesInBoard);
        remove(tilesInBoard.begin(), tilesInBoard.end(), ' ');
        std::stringstream ss4(tilesInBoard);  
        while (ss4.good()) {
            std::string substr;
            getline(ss4, substr, ',');
            board->setTiles(substr);
        }

        //Read tileBag
        std::string tilebagString = "";
        std::getline(file, tilebagString);
        std::stringstream ss5(tilebagString);
        while (ss5.good()) {
            std::string substr;
            getline(ss5, substr, ',');
            tilebag->addTileByName(substr);
        }

        //Read player turn
        //We already know the player who saved this files is the player1 and this is player1's turn
        std::cout << std::endl;
        std::cout << "Qwirkle game successfully loaded" << std::endl;
        std::cout << std::endl;
        loadSuccess = true;
    }
    return loadSuccess;
}

// Show students credits
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