//
// Created by jihee on 1/26/2021.
//

#ifndef GAMESTORE_CARDGAME_H
#define GAMESTORE_CARDGAME_H


#include "Game.h"

class CardGame : public Game{
private:
    int number_of_cards;

public:
    CardGame(const std::string &name, int numberOfPlayers, int numberOfCards);

    virtual ~CardGame();

    void print_game(std::ostream &out) const override;

};


#endif //GAMESTORE_CARDGAME_H
