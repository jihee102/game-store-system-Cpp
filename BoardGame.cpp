//
// Created by jihee on 1/26/2021.
//

#include "BoardGame.h"

BoardGame::BoardGame(const std::string &name, int numberOfPlayers, const std::string &publisher) : Game(name,
                                                                                                        numberOfPlayers),
                                                                                                   publisher(
                                                                                                           publisher) {}

BoardGame::~BoardGame() {

}

std::shared_ptr<BoardGameExpansion> BoardGame::find_expansion(const std::string &name) {
    for(auto expansion: expansion_list){
        if(expansion->get_name() == name){
            return expansion;
        }
    }

    return nullptr;
}


void BoardGame::add_expansion(const std::string &name, bool playableAlone) {
    if(name.empty()){
        throw std::runtime_error("The expansion name cannot be empty!");
    }

    auto expansion = find_expansion(name);

    if(expansion){
        throw std::runtime_error("The expansion already exist!");
    }

    auto new_expansion = std::make_shared<BoardGameExpansion>(name, playableAlone);

    expansion_list.push_back(new_expansion);
}

void BoardGame::print_game(std::ostream &out) const {
    out << "Board game: ";
    Game::print_game(out);
    out << ", published by "<< publisher;
    out << std::endl;
    if(expansion_list.size()> 0){
        out << "\t" << "Expansions:" << std::endl;
        for(auto game: expansion_list){
            game->print_expansion(out, "\t");
            out << std::endl;
        }
    }
}

