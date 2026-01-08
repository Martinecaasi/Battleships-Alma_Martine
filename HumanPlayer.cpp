#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer(const char* name) : Player(name) {}

void HumanPlayer::placeAllShips() {
    std::cout << playerName << ", place your ships on the grid.\n";

//This code iterates through a list of ships, prompting the user to place each one on a grid. 
//For each ship, the user is asked to input the starting row, column, and orientation, and the code checks if the placement is valid 
//(within bounds and unoccupied); if valid, the ship is placed on the grid and displayed; otherwise, the user is asked to try again.
    for (int i = 0; i < 5; ++i) {
        Ship* ship = ships[i];
        bool placed = false;

        while (!placed) {
            int row, col;
            char orientation;

            std::cout << "Placing " << ship->getName() << " (size: " << ship->getSize() << ")\n";
            std::cout << "Enter starting row and column (0-9): ";
            std::cin >> row >> col;
            std::cout << "Enter orientation (H for horizontal, V for vertical): ";
            std::cin >> orientation;

            bool horizontal = (orientation == 'H' || orientation == 'h');

            if (grid.inBounds(row, col, ship->getSize(), horizontal) &&
                !grid.isTileOccupied(row, col)) {
                grid.placeShip(row, col, ship->getSize(), horizontal, 'S');
                placed = true;
                grid.printGrid();
            } else {
                std::cout << "Invalid placement. Try again.\n";
            }
        }
    }
}

//This code defines the makeMove function for a HumanPlayer, allowing the player to attack the opponent's grid. 
//The player inputs attack coordinates, and the function validates if they are within bounds and not previously targeted; 
//if valid, the cell is marked as a "miss" or "hit" depending on its content, and the grid updates are displayed. 
//If a ship is hit, it checks the status of the opponent's ships to apply damage, prompting the user to retry in case of invalid input or repeated targeting of a cell.
void HumanPlayer::makeMove(Player* opponent) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        std::cout << playerName << ", enter attack coordinates (row and column): ";
        std::cin >> row >> col;

        if (row >= 0 && row < 10 && col >= 0 && col < 10) {
            char cell = opponent->getGrid().getCell(row, col);

            if (cell == '~') {
                opponent->getGrid().markMiss(row, col);
                std::cout << "Miss!\n";
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
                std::cout << "Hit!\n";
                validMove = true;
            } else {
                std::cout << "Invalid move. Cell already targeted. Try again.\n";
            }
        } else {
            std::cout << "Coordinates out of bounds. Try again.\n";
        }
    }

    std::cout << "\nYour grid:\n";
    grid.printGrid();

    std::cout << "\nOpponent's grid:\n";
    opponent->getGrid().printGrid();
}
