//
// Created by Quinn Koike on 11/03/2017.
//

#include "Bank.h"

Bank::Bank(Deck *deck){
    this->deck = deck;
    totalCards = 0;
}

void Bank::deal() {
    hand.push_back(deck -> deal());
    addCardCount();
}

void Bank::printHand(std::string entity) {
    std::cout<< entity <<" hand: " << std::endl;
    for (int i = 0; i < hand.size(); i++){
        std::cout << "    | " << std::flush;
        hand[i].printCard();
    }
    std::cout<< "Current value of hand: " << getHandValue() << "\n" << std::endl;
}

const int Bank::getHandValue() {
    int totalValue = 0;
    for (int i = 0; i < hand.size(); i++){
        totalValue += hand[i].getValue();
    }
    return totalValue;
}

const int Bank::getTotalNumCards() {
    return totalCards;
}

void Bank::addCardCount() {
    totalCards += 1;
}

const bool Bank::isBust() {
    return getHandValue() > 21;
}

void Bank::reset() {
    hand.erase(hand.begin(), hand.end());
    totalCards = 0;
}


