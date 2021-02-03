//
// Created by jihee on 1/26/2021.
//

#ifndef GAMESTORE_BOARDGAMEEXPANSION_H
#define GAMESTORE_BOARDGAMEEXPANSION_H
#include <iostream>

class BoardGameExpansion {
private:
    std::string name;
    bool playable_alone;

public:
    BoardGameExpansion(const std::string &name, bool playableAlone);

    virtual ~BoardGameExpansion();

    const std::string &get_name() const;

    void print_expansion(std::ostream & out,const std::string &indentation ="") const;
};


#endif //GAMESTORE_BOARDGAMEEXPANSION_H
