//
// Created by jihee on 1/26/2021.
//

#ifndef GAMESTORE_BOARDGAME_H
#define GAMESTORE_BOARDGAME_H


#include <vector>
#include <memory>
#include "Game.h"
#include "BoardGameExpansion.h"

class BoardGame : public Game{
private:
    std::string publisher;
    std::vector<std::shared_ptr<BoardGameExpansion>> expansion_list;

public:
    BoardGame(const std::string &name, int numberOfPlayers, const std::string &publisher);

    virtual ~BoardGame();

    std::shared_ptr<BoardGameExpansion> find_expansion(const std::string &name);

    void add_expansion(const std::string &name, bool playableAlone);

    void print_game(std::ostream &out) const override;
};


#endif //GAMESTORE_BOARDGAME_H
