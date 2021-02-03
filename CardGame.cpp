//
// Created by jihee on 1/26/2021.
//

#include "CardGame.h"

CardGame::CardGame(const std::string &name, int numberOfPlayers, int numberOfCards) : Game(name, numberOfPlayers),
                                                                                      number_of_cards(numberOfCards) {}

CardGame::~CardGame() {

}

void CardGame::print_game(std::ostream &out) const {
    out<< "Card game: ";
    Game::print_game(out);
    out << " has " << number_of_cards <<" cards.";
}
