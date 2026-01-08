#include "Ship.hpp"
#include <cstring>

Ship::Ship(const char* shipName,int shipSize) 
: size(shipSize),hitsTaken(0){
          name= new char[strlen(shipName)+1];
          strcpy(name,shipName);

}


Ship::~Ship(){
          delete[] name;
}


void Ship::takeHit() {
    hitsTaken++;
    std::cout << name << " got hit!" << std::endl;
    if (isSunk()) {
        std::cout << name << " is sunk!" << std::endl;
    }
}

bool Ship::isSunk() const{
          return hitsTaken>=size;
}

const char* Ship::getName() const{
          return name;
}

int Ship::getHitsTaken() const {
    return hitsTaken;
}

int Ship::getSize() const {
    return size;
}

Carrier::Carrier() : Ship("Carrier ", 5) {}

Battleship::Battleship() : Ship("Battleship ", 4) {}

Cruiser::Cruiser() : Ship("Cruiser ", 3) {}

Submarine::Submarine() : Ship("Submarine ", 3) {}

Destroyer::Destroyer() : Ship("Destroyer ", 2) {}