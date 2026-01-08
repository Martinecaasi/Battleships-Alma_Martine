#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP

#include "Player.hpp"
#include <iostream>

class HumanPlayer : public Player {
public:
    HumanPlayer(const char* name);

    void placeAllShips() override;
    void makeMove(Player* opponent) override;
};

#endif