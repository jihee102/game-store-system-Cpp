//
// Created by jihee on 1/26/2021.
//

#include "Game.h"
int Game::increment  = 1;

Game::Game(const std::string &name, int numberOfPlayers) : name(name), number_of_players(numberOfPlayers), id(increment++) {}

Game::~Game() {

}

void Game::print_game(std::ostream &out) const {
    out << id <<". "<< name << " (" << number_of_players << " players)";
}
