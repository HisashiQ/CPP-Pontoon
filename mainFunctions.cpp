//
// Created by Quinn Koike on 12/03/2017.
//

#include <iostream>
#include "Player.h"

#include "mainFunctions.h"

// Function to get user choice

bool playerChoices(Player *p, Log *l){
    char choice;
    std::string input = "";
    bool playerPlaying = true;
    bool cont = true;
    while (cont) {
        if (p->isBust()) {
            std::cout << "Player is bust, Bank wins" << std::endl;
            cont = false;
            playerPlaying = false;
            l -> endRound(2);
        } else if (p -> getTotalNumCards() == 5) {
            cont = false;
            playerPlaying = true;
        } else if (p -> getHandValue() == 21){
            cont = false;
            playerPlaying = true;
        } else {
            while (true) {
                std::cout << "Please enter 't' to twist or 's' to stick" << std::endl;
                std::cout << ">> " << std::flush;
                getline(std::cin, input);

                if (input.length() == 1 && (input == "t" || input == "s")) {
                    choice = input[0];
                    break;
                }

                std::cout << "Invalid character, please try again" << std::endl;
            }
            if(choice == 't'){
                p -> deal();
                p -> printHand();
            } else {
                p -> stick();
                cont = false;
            }
        }
    }
    return playerPlaying;
}

// Function to deal cards to bank and player
void initialDeal(Player *p, Bank *b) {
    b -> deal();
    b -> deal();
    p -> deal();
    p -> deal();
    p -> printHand();
}

// Function to decided on bankers move and log the outcome of the game to file.

void bankerMoves(Player *p, Bank *b, Log *l) {
    bool bankCont = true;
    while (bankCont) {
        if (b -> isBust()) {
            bankCont = false;
            std::cout << "Bank is bust, Player wins" << std::endl;
            l -> endRound(1);
        } else if (b -> getTotalNumCards() == 5 && p -> getTotalNumCards() < 5) {
            std::cout << "Bank wins with 5 cards" << std::endl;
            bankCont = false;
            l -> endRound(2);
        } else if (b -> getHandValue() > p -> getHandValue()) {
            std::cout << "Bank wins with a hand value of " << b -> getHandValue() << ". Players hand value: "
                      << p -> getHandValue() << std::endl;
            bankCont = false;
            l -> endRound(2);
        } else if (p -> getHandValue() == 21 && b -> getHandValue() == 21){
            if (p -> getTotalNumCards() > b -> getTotalNumCards()){
                std::cout << "Player wins with more cards than the Bank" << std::endl;
                bankCont = false;
                l -> endRound(1);
            } else if (p -> getTotalNumCards() == b -> getTotalNumCards()){
                std::cout << "Draw" << std::endl;
                bankCont = false;
                l -> endRound(3);
            } else {
                std::cout << "Bank wins with more cards" << std::endl;
                bankCont = false;
                l -> endRound(2);
            }
        } else {
            b -> deal();
            std::cout << "\n\nThe bank draws a card...\n\n" << std::endl;
            b -> printHand();
        }
    }
}

// Function to check if the player would like to play again

bool playAgain() {
    std::string input = "";
    char choice;
    while (true) {
        std::cout << "\nWould you like to play again? (y/n)" << std::endl;
        std::cout << ">> " << std::flush;
        getline(std::cin, input);
        if (input.length() == 1 && (input == "y" || input == "n")) {
            choice = input[0];
            break;
        }
        std::cout << "Invalid character, please try again" << std::endl;
    }
    return choice == 'y';
}
