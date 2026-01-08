#ifndef GRID_HPP
#define GRID_HPP

class Grid
{
private:
          char cells[10][10];
public:
 Grid();

 bool isTileOccupied( int row, int col) const;

bool inBounds(int row, int col, int shipSize, bool horizontal) const;

    void placeShip(int row, int col, int shipSize, bool horizontal, char symbol);

    void markHit(int row, int col);

    void markMiss(int row, int col);

    char getCell(int row, int col) const;

    void printGrid() const;
};

#endif


