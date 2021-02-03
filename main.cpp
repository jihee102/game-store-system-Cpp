#include <iostream>
#include "GameAdmin.h"
#include "io.h"

int main() {
    GameAdmin game_admin;

    try{
        game_admin.add_board_game("Flash Point",6,"999Games");
        game_admin.add_expansion_in_game("Flash Point","Dangerous Water",false);

        game_admin.add_board_game("Ticket to Ride",5,"Days of Wonder");
        read_expansions(game_admin, "Ticket to Ride", "expansions.txt");

        game_admin.add_card_game("Poker",4,52);
        game_admin.add_card_game("Codenames",8,200);

        game_admin.print_all_games(std::cout);

    } catch (std::exception &exception) {
        std::cerr << exception.what() << std::endl;
    }

    return 0;
}
