//
// Created by Quinn Koike on 12/03/2017.
//

#include "Player.h"

void Player::stick() {
    sticking = true;
}

Player::Player(Deck *deck) : Bank(deck) {
    sticking = false;
}

const bool Player::isStuck() {
    return sticking;
}

void Player::printHand(std::string entity) {
    Bank::printHand(entity);
}