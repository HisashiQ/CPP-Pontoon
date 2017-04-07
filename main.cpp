#include <iostream>
#include "Bank.h"
#include "Player.h"
#include "mainFunctions.h"

int main() {
    //Seed sudo-random number generator
    std::srand(unsigned(std::time(0)));

    Log log;
    bool stillPlaying = true;
    bool bankCont = true;
    Deck *deck = new Deck;
    Bank bank(deck);
    Player player(deck);

    while (stillPlaying) {
        initialDeal(&player, &bank);
        if (playerChoices(&player, &log)) {
            bankerMoves(&player, &bank, &log);
        }
        bank.reset();
        player.reset();
        if (!playAgain()){
            std::cout << "\nGood game, see you next time!" << std::endl;
            stillPlaying = false;
        }
    }
    delete(deck);
    log.ioOut();
}