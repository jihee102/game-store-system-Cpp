//
// Created by jihee on 1/26/2021.
//

#include "BoardGameExpansion.h"

BoardGameExpansion::BoardGameExpansion(const std::string &name, bool playableAlone) : name(name),
                                                                                      playable_alone(playableAlone) {}

BoardGameExpansion::~BoardGameExpansion() {

}

void BoardGameExpansion::print_expansion(std::ostream &out ,const std::string &indentation) const {
    out << indentation <<name << (playable_alone ? "(Can be played standalone)" : "");
}

const std::string &BoardGameExpansion::get_name() const {
    return name;
}

