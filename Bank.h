//
// Created by Quinn Koike on 11/03/2017.
//

#ifndef PONTOON_BANK_H
#define PONTOON_BANK_H


#include "Deck.h"

class Bank {
public:
    Bank(Deck *deck);
    void deal();

//  Function is virtual to make it polymorphic. Each class using the function is given different defaults to print
    virtual void printHand(std::string entity="Banks");

    const int getHandValue();
    const int getTotalNumCards();
    const bool isBust();

//  Resets total cards and hand attributes
    void reset();

private:
    Deck *deck;
    std::vector<Card<std::string>> hand;
    int totalCards;

//  Helper Method used in deal() to add to totalCards
    void addCardCount();
};


#endif //PONTOON_BANK_H
