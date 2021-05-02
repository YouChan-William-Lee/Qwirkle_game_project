#include <fstream>
#include <iostream>
#include <string>

#define NUM_OF_STUDENT 4
#define NUM_OF_STUDENT_INFO 3
#define NUM_OF_COLOURS 6
#define NUM_OF_SHAPE 6
#define MAX_SIZE_TILE NUM_OF_COLOURS * NUM_OF_SHAPE

#include "LinkedList.h"

void welcomeMessage();
void mainMenu();
void setupGame();
void loadupGame();
void credits();
void cleanupGame();


int main(int argc, char** argv) {
    welcomeMessage();
    
    bool play = true;

    while(play) {
        mainMenu();

        // LinkedList* list = new LinkedList();

        std::string menu = "";
        std::cin >> menu;

        if(menu >= "1" && menu <= "4") {
            if(menu == "1") {
            // setupGame(deck, player1, player2);
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

void setupGame() {

}

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