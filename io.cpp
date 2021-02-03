//
// Created by jihee on 1/26/2021.
//

#include <fstream>
#include "io.h"

void read_expansions(GameAdmin gameAdmin, const std::string &game, const std::string &filename) {
    std::ifstream input{filename};

    if(!input.is_open()){
        throw std::runtime_error("Fail to open the file "+filename);
    }

    for(;;){
        std::string name;
        input >> name;

        // if the end-of-file has been reached, we're done
        if(name.empty() || input.eof()){
            return;
        }

        gameAdmin.add_expansion_in_game(game, name, true);

    }

}
