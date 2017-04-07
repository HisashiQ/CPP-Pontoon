//
// Created by Quinn Koike on 11/03/2017.
//

#ifndef PONTOON_CARD_H
#define PONTOON_CARD_H

#include <iostream>

template<typename T>
class Card {

public:
    Card(T &face, T &suit, int value){
        std::get<0>(card) = face;
        std::get<1>(card) = suit;
        std::get<2>(card) = value;
    }

    const int getValue(){
        return std::get<2>(card);
    }

    void printCard() const {
        std::cout<< std::get<0>(card) << " of " << std::get<1>(card) << std::endl;
    }

private:
    std::tuple<T, T, int> card;
};

#endif //PONTOON_CARD_H
