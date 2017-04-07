//
// Created by Quinn Koike on 11/03/2017.
//

#ifndef PONTOON_DECK_H
#define PONTOON_DECK_H

#include <vector>
#include <stack>
#include "Card.h"


class Deck {
public:
    Deck();
    const Card<std::string> deal();
    const bool isEmpty();

private:

    std::vector<Card<std::string>> vectorDeck;

    // Vector (vectorDeck is used to create the deck. It is then copied onto stack to give pop and push functionality
    // like a real deck of cards.
    std::stack<Card<std::string>> stackDeck;

    // Private helper methods : Used in constructor

    std::string value[13];
    std::string pic[4];
    int getValue(std::string&) const;
    void shuffleDeck();
    void generateVectorDeck();
    void createStackDeck();
};


#endif //PONTOON_DECK_H
