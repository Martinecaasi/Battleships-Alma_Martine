#include "AiPlayer.hpp"
#include <iostream>

AiPlayer::AiPlayer(const char* name) : Player(name) {}

int AiPlayer::getRandomCoordinate() {
    return std::rand() % 10; 
}

void AiPlayer::placeAllShips() {
    std::cout << playerName << " is placing ships...\n";

    for (int i = 0; i < 5; ++i) {
        Ship* ship = ships[i];
        bool placed = false;

        while (!placed) {
            int row = getRandomCoordinate();
            int col = getRandomCoordinate();
            bool horizontal = (std::rand() % 2 == 0); // Randomly choose orientation

            // Check if the placement is valid
            if (grid.inBounds(row, col, ship->getSize(), horizontal) &&
                !grid.isTileOccupied(row, col)) {
                grid.placeShip(row, col, ship->getSize(), horizontal, 'S');
                placed = true;
            }
        }
    }

    std::cout << playerName << "'s ships have been placed.\n";
}


//This function implements the AI player's move in the game. 
//It randomly generates coordinates until a valid move is found. 
//If the selected cell is water (~), it marks it as a miss; 
//if it contains a ship (S), it marks it as a hit and applies damage to the corresponding ship. 
//After the move, the AI updates and displays its own grid and the opponent's grid.
void AiPlayer::makeMove(Player* opponent) {
    bool validMove = false;
    int row, col;

    while (!validMove) {
        row = getRandomCoordinate();
        col = getRandomCoordinate();

        char cell = opponent->getGrid().getCell(row, col);

        if (cell == '~') {
            opponent->getGrid().markMiss(row, col);
            std::cout << playerName << " attacked (" << row << ", " << col << "): Miss!\n";
            validMove = true;
        } else if (cell == 'S') {
            opponent->getGrid().markHit(row, col);
            for (int i = 0; i < 5; ++i) {
                Ship* ship = opponent->getShip(i);
                if (!ship->isSunk()) {
                    ship->takeHit();
                    break;
                }
            }
            std::cout << playerName << " attacked (" << row << ", " << col << "): Hit!\n";
            validMove = true;
        }
    }

    std::cout << "\n" << playerName << "'s grid:\n";
    grid.printGrid();

    std::cout << "\nOpponent's grid:\n";
    opponent->getGrid().printGrid();
}
