#include "Player.hpp"
#include <cstring>

Player::Player(const char* name) {
    playerName = new char[strlen(name) + 1];
    strcpy(playerName, name);

    ships[0] = new Carrier();
    ships[1] = new Battleship();
    ships[2] = new Cruiser();
    ships[3] = new Submarine();
    ships[4] = new Destroyer();

        std::srand(std::time(nullptr));
}

Player::~Player() {
    delete[] playerName;
    for (int i = 0; i < 5; ++i) {
        delete ships[i];
    }
}

const char* Player::getPlayerName() const {
    return playerName;
}


void Player::placeAllShips() {
    for (int i = 0; i < 5; ++i) {
        Ship* ship = ships[i];
        bool placed = false;

        while (!placed) {
            int row = std::rand() % 10;
            int col = std::rand() % 10;
            bool horizontal = std::rand() % 2 == 0;

            if (grid.inBounds(row, col, ship->getSize(), horizontal) &&
                !grid.isTileOccupied(row, col)) {
                grid.placeShip(row, col, ship->getSize(), horizontal, 'S');
                placed = true;
            }
        }
    }
}

void Player::makeMove(Player* opponent) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        std::cout << playerName << ", enter attack coordinates (row and column): ";
        std::cin >> row >> col;

        if (row >= 0 && row < 10 && col >= 0 && col < 10) {
            char cell = opponent->grid.getCell(row, col);

            if (cell == '~') {
                opponent->grid.markMiss(row, col);
                std::cout << "Miss!" << std::endl;
                validMove = true;
            } else if (cell == 'S') {
                opponent->grid.markHit(row, col);
                for (int i = 0; i < 5; ++i) {
                    Ship* ship = opponent->ships[i];
                    if (ship->isSunk()) continue; 
                    ship->takeHit();
                    break;
                }
                std::cout << "Hit!" << std::endl;
                validMove = true;
            } else {
                std::cout << "Invalid move, try again." << std::endl;
            }
        } else {
            std::cout << "Coordinates out of bounds, try again." << std::endl;
        }
    }

    std::cout << "\nYour grid:\n";
    displayMyGrid();

    std::cout << "\nOpponent's grid:\n";
    displayOpponentGrid(opponent);
}

bool Player::allShipsSunk() const {
    for (int i = 0; i < 5; ++i) {
        if (!ships[i]->isSunk()) {
            return false;
        }
    }
    return true;
}

void Player::displayMyGrid() const {
    grid.printGrid();
}


void Player::displayOpponentGrid(const Player* opponent) const {
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            char cell = opponent->grid.getCell(row, col);
            if (cell == 'S') {
                std::cout << "~ "; // Hide the ships
            } else {
                std::cout << cell << " ";
            }
        }
        std::cout << std::endl;
    }
}
