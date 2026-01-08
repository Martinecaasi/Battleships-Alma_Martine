#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>

class Ship {
protected:
          char* name;
          int size;
          int hitsTaken;

public:
          Ship(const char* shipName, int shipSize);

          virtual ~Ship();
          virtual void takeHit();

          bool isSunk() const;

          const char* getName() const;

          int getSize() const;

          int getHitsTaken() const;

};


class Carrier : public Ship {
public:
    Carrier();
};

class Battleship : public Ship {
public:
    Battleship();
};

class Cruiser : public Ship {
public:
    Cruiser();
};

class Submarine : public Ship {
public:
    Submarine();
};

class Destroyer : public Ship {
public:
    Destroyer();
};


#endif


