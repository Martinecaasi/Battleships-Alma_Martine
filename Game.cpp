#include "Game.hpp"


Game::Game(Player* p1, Player* p2) : player1(p1), player2(p2) {}

void Game::setup() {
    std::cout << player1->getPlayerName() << ", place your ships:\n";
    player1->placeAllShips();

    std::cout << "\n" << player2->getPlayerName() << ", place your ships:\n";
    player2->placeAllShips();
}


//This function manages the main game loop, alternating turns between two players until one of them wins. 
//It announces the start of the battle, lets each player make a move, and checks after every turn if all of the opponent's ships are sunk. 
//If a player sinks all of their opponent's ships, the game announces the winner and ends.
void Game::start() {
    std::cout << "\nThe battle begins!\n";

    while (!isGameOver()) {
        std::cout << "\n" << player1->getPlayerName() << "'s turn:\n";
        player1->makeMove(player2);

        if (player2->allShipsSunk()) {
            std::cout << player1->getPlayerName() << " wins!\n";
            break;
        }

        std::cout << "\n" << player2->getPlayerName() << "'s turn:\n";
        player2->makeMove(player1);

        if (player1->allShipsSunk()) {
            std::cout << player2->getPlayerName() << " wins!\n";
            break;
        }
    }
}

bool Game::isGameOver() const {
    return player1->allShipsSunk() || player2->allShipsSunk();
}
