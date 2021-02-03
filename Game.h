//
// Created by jihee on 1/26/2021.
//

#ifndef GAMESTORE_GAME_H
#define GAMESTORE_GAME_H
#include <iostream>

class Game {
private:
    static int increment;
    int id;
    std::string name;
    int number_of_players;

public:
    Game(const std::string &name, int numberOfPlayers);

    virtual ~Game();

    virtual void print_game(std::ostream & out) const;


};


#endif //GAMESTORE_GAME_H
