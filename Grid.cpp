#include "Grid.hpp"
#include <iostream>
#include <iomanip>

Grid::Grid() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cells[i][j] = '~';
        }
    }
}

bool Grid::isTileOccupied(int row, int col) const {
    return cells[row][col] == 'S' || cells[row][col] == 'X';
}

bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const {
    if (horizontal) {
        return col + shipSize <= 10;
    } else {
        return row + shipSize <= 10;
    }
}

//This function places a ship on the grid by marking its tiles with the provided symbol, either horizontally or vertically, 
//starting from the specified row and col. Before placement, it checks if the ship fits within the grid's bounds and ensures 
//that none of the target tiles are already occupied; if either condition fails, it outputs an error and exits without placing the ship.
void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol) {
    if (!inBounds(row, col, shipSize, horizontal)) {
        std::cerr << "Error: Ship placement out of bounds!" << std::endl;
        return;
    }
    for (int i = 0; i < shipSize; ++i) {
        if (horizontal) {
            if (isTileOccupied(row, col + i)) {
                std::cerr << "Error: Tile already occupied!" << std::endl;
                return;
            }
            cells[row][col + i] = symbol;
        } else {
            if (isTileOccupied(row + i, col)) {
                std::cerr << "Error: Tile already occupied!" << std::endl;
                return;
            }
            cells[row + i][col] = symbol;
        }
    }
}

void Grid::markHit(int row, int col) {
    if (cells[row][col] == 'S') {
        cells[row][col] = 'X';
    } else {
        std::cerr << "Error: No ship at this location!" << std::endl;
    }
}

void Grid::markMiss(int row, int col) {
    if (cells[row][col] == '~') {
        cells[row][col] = 'M';
    } else {
        std::cerr << "Error: Cannot mark miss here!" << std::endl;
    }
}

char Grid::getCell(int row, int col) const {
    return cells[row][col];
}

void Grid::printGrid() const {
    std::cout << "  ";
    for (int col = 0; col < 10; ++col) {
        std::cout << std::setw(2) << col;
    }
    std::cout << std::endl;

    for (int row = 0; row < 10; ++row) {
        std::cout << std::setw(2) << row << " ";
        for (int col = 0; col < 10; ++col) {
            std::cout << std::setw(2) << cells[row][col];
        }
        std::cout << std::endl;
    }
}