//
// Created by Quinn Koike on 12/03/2017.
//

#ifndef PONTOON_MAINFUNCTIONS_H
#define PONTOON_MAINFUNCTIONS_H

#include "Log.h"

bool playerChoices(Player *p, Log *l);
void initialDeal(Player *p, Bank *b);
void bankerMoves(Player *p, Bank *b, Log *l);
bool playAgain();

#endif //PONTOON_MAINFUNCTIONS_H
