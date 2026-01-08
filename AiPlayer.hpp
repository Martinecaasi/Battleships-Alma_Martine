#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP

#include "Player.hpp"
#include <cstdlib>
#include <ctime>

class AiPlayer : public Player {
public:
    AiPlayer(const char* name);

    void placeAllShips() override;
    void makeMove(Player* opponent) override;

private:
    int getRandomCoordinate();
};

#endif 
