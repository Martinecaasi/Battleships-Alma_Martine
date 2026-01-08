#include "HumanPlayer.hpp"
#include "AiPlayer.hpp"
#include "Game.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr)); 

    HumanPlayer player1("Human Player");
    AiPlayer player2("AI Player");

    Game game(&player1, &player2);

    game.setup();

    game.start();

    return 0;
}
