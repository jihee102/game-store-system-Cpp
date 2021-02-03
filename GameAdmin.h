//
// Created by jihee on 1/26/2021.
//

#ifndef GAMESTORE_GAMEADMIN_H
#define GAMESTORE_GAMEADMIN_H

#include <memory>
#include <map>
#include "Game.h"

class GameAdmin {
private:
    std::map<std::string, std::shared_ptr<Game>> game_list;

public:
    GameAdmin();

    virtual ~GameAdmin();

    std::shared_ptr<Game> find_game(const std::string &name) const;

    void add_card_game(const std::string &name, int numberOfPlayers, int numberOfCards);

    void add_board_game(const std::string &name, int numberOfPlayers,  const std::string &publisher);

    void add_expansion_in_game(const std::string &game_name, const std::string &name, bool playableAlone);

    void print_all_games(std::ostream & out) const;

};


#endif //GAMESTORE_GAMEADMIN_H
