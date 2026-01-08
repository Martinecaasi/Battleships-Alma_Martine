#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Grid.hpp"
#include "Ship.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Player
{
protected:
    char* playerName;   
    Ship* ships[5];     
    Grid grid; 

public:

Player(const char* name);

virtual~ Player();

const char* getPlayerName() const;

virtual void placeAllShips();

virtual void makeMove(Player* opponent);

bool allShipsSunk() const;

void displayMyGrid() const;

void displayOpponentGrid(const Player* opponent) const;

    Grid& getGrid() { return grid; }
    Ship* getShip(int index) { return ships[index]; }

};

#endif
