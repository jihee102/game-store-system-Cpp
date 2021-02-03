//
// Created by jihee on 1/26/2021.
//

#include "GameAdmin.h"
#include "CardGame.h"
#include "BoardGame.h"

GameAdmin::GameAdmin() {}

GameAdmin::~GameAdmin() {

}

std::shared_ptr<Game> GameAdmin::find_game(const std::string &name) const {
    auto iterator = game_list.find(name);

    return iterator == game_list.cend()? nullptr: iterator->second;
}

void GameAdmin::add_card_game(const std::string &name, int numberOfPlayers, int numberOfCards) {
    if(name.empty() || numberOfPlayers ==0 || numberOfCards ==0){
        throw std::runtime_error("Game name / number of players / number of cards cannot be empty or 0");
    }

    auto game = find_game(name);
    if(game){
        throw std::runtime_error("The game with the given nae already exist!");
    }

    auto card_game = std::make_shared<CardGame>(name, numberOfPlayers, numberOfCards);

    game_list[name] = card_game;
}

void GameAdmin::add_board_game(const std::string &name, int numberOfPlayers, const std::string &publisher) {
    if(name.empty() || numberOfPlayers ==0 || publisher.empty()){
        throw std::runtime_error("Game name / number of players / publisher cannot be empty or 0");
    }

    auto game = find_game(name);
    if(game){
        throw std::runtime_error("The game with the given name already exist!");
    }

    auto board_game = std::make_shared<BoardGame>(name, numberOfPlayers, publisher);

    game_list[name] = board_game;
}

void GameAdmin::add_expansion_in_game(const std::string &game_name, const std::string &name, bool playableAlone) {
    auto game = find_game(game_name);

    // check if a game with the given name exist.
    if(!game){
        throw std::runtime_error("The game with the given name doesn't exist!");
    }

    // check if the game is a board game.
    auto board_game = std::dynamic_pointer_cast<BoardGame>(game);
    if(!board_game){
        throw std::runtime_error("The game is not a board game!");
    }

    // Add expansion of the game (expansion name will be check if it's already exist.)
    board_game->add_expansion(name, playableAlone);

}

void GameAdmin::print_all_games(std::ostream &out) const {
    for(auto iterator: game_list){
        iterator.second->print_game(out);
        out << std::endl;
    }
}
