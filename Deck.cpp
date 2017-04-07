//
// Created by Quinn Koike on 11/03/2017.
//

#include <random>
#include "Deck.h"

Deck::Deck() {
    std::string faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack",
                           "Queen", "King"};
    std::string suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};
    for (int i = 0; i < 13; i++) {
        value[i] = faces[i];
    }
    for (int i = 0; i < 4; i++) {
        pic[i] = suits[i];
    }
    createStackDeck();
}

void Deck::generateVectorDeck() {
    for (int i = 0; i < 13; i++) {
        std::string face = value[i];

        for (int k = 0; k < 4; ++k) {
            std::string suit = pic[k];
            Card<std::string> c(face, suit, getValue(face));
            vectorDeck.push_back(c);
        }
    }
}

int Deck::getValue(std::string &face) const {
    if (face == "Ace"){
        return 1;
    } else if(face == "Two"){
        return 2;
    }else if(face == "Three"){
        return 3;
    }else if(face == "Four"){
        return 4;
    }else if(face == "Five"){
        return 5;
    }else if(face == "Six"){
        return 6;
    }else if(face == "Seven"){
        return 7;
    }else if(face == "Eight"){
        return 8;
    }else if(face == "Nine"){
        return 9;
    }else if(face == "Ten"){
        return 10;
    }else if(face == "Jack"){
        return 10;
    }else if(face == "Queen"){
        return 10;
    }else if(face == "King"){
        return 10;
    } else {
        throw "Error: Not a card.";
    }
}

void Deck::shuffleDeck() {
    shuffle(&vectorDeck[0], &vectorDeck[52], std::default_random_engine(std::random_device()()));
}

const Card<std::string> Deck::deal() {
    Card<std::string> topOfDeck = stackDeck.top();
    stackDeck.pop();

    // Check if the deck is empty - If it is, a new deck is generated and shuffled using createStackDeck()
    if (isEmpty()){
        std::cout << "\n\n\n\n This deck is now empty. Bringing in a new deck.\n\n\n\n" << std::endl;
        createStackDeck();
    }
    return topOfDeck;
}

const bool Deck::isEmpty(){
    return stackDeck.size() == 0;
}

void Deck::createStackDeck() {
    generateVectorDeck();
    shuffleDeck();

    for (int i = 0; i < 52; i++){
        stackDeck.push(vectorDeck[i]);
    }
    vectorDeck.erase(vectorDeck.begin(), vectorDeck.end());
}
