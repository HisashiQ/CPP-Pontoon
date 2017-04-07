//
// Created by Quinn Koike on 12/03/2017.
//

#ifndef PONTOON_PLAYER_H
#define PONTOON_PLAYER_H


#include "Bank.h"

class Player : public Bank {
public:
    Player(Deck *deck);
    void stick();
    const bool isStuck();
    void printHand(std::string entity="Players") override;
private:
    bool sticking;
};


#endif //PONTOON_PLAYER_H
