/*********************************************************************
** File name:    Doodlebug.cpp
** Author:       Group 3
** Date:         02/14/19
** Description:  Definitions for Doodlebug class
**               child of Critter class
*********************************************************************/

#include "Game.hpp"
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include <iostream>

Doodlebug::Doodlebug(int r, int c, int s) : Critter::Critter(r, c) {
    this->type_ = DOODLEBUG;
    this->step_ = s;
    this->lastAte_ = 0;
}

Doodlebug::Doodlebug(int r, int c, int s, int a, int l) : Critter::Critter(r, c) {
    this->type_ = DOODLEBUG;
    this->step_ = s;
    this->age_ = a;
    this->lastAte_ = l;
}

int Doodlebug::getLastAte() {
    return this->lastAte_;
}

void Doodlebug::move(Critter ***grid, Game game) {
    bool check[4] = {false, false, false, false};
    bool hasAnt = false;
    bool emptySpace[4] = {false, false, false, false};
    bool hasMoved = false;
    int count = 0;
    int random;

    do { //checks for ants first, loops until finds ant or all directions checked
        do { //checks a random direction, loops if already checked
            random = rand() % 4;
        } while (check[random]);
        check[random] = true;
        if (random == 0) { //row+1 (down)
            if (row_ + 1 < game.getRows()) { //if in bounds
                if (!grid[row_ + 1][col_]) { //if null
                    emptySpace[random] = true; //remembers the space as empty
                } else if (grid[row_ + 1][col_]->getType() == ANT) { //if has ant
                    //increments steps and resets lastAte
                    this->step_++;
                    this->lastAte_ = 0;
                    //delete Ant object
                    delete grid[row_ + 1][col_];
                    //moves Doodle
                    grid[row_ + 1][col_] = new Doodlebug(row_ + 1, col_, step_, age_ + 1, lastAte_);
                    //deletes old doodle spot and sets to null
                    delete grid[row_][col_];
                    grid[row_][col_] = nullptr;
                    hasAnt = true;
                    hasMoved = true;
                } else { //else increases count
                    ++count;
                }
            } else { //increases count if space is out of bounds
                ++count;
            }
        } else if (random == 1) { //row-1 (up)
            if (row_ > 0) {
                if (!grid[row_ - 1][col_]) {
                    emptySpace[random] = true;
                } else if (grid[row_ - 1][col_]->getType() == ANT) {
                    this->step_++;
                    this->lastAte_ = 0;
                    delete grid[row_ - 1][col_];
                    grid[row_ - 1][col_] = new Doodlebug(row_ - 1, col_, step_, age_ + 1, lastAte_);
                    delete grid[row_][col_];
                    grid[row_][col_] = nullptr;
                    hasAnt = true;
                    hasMoved = true;
                } else {
                    ++count;
                }
            } else {
                ++count;
            }
        } else if (random == 2) { //col+1 (right)
            if (col_ + 1 < game.getCols()) {
                if (!grid[row_][col_ + 1]) {
                    emptySpace[random] = true;
                } else if (grid[row_][col_ + 1]->getType() == ANT) {
                    this->step_++;
                    this->lastAte_ = 0;
                    delete grid[row_][col_ + 1];
                    grid[row_][col_ + 1] = new Doodlebug(row_, col_ + 1, step_, age_ + 1, lastAte_);
                    delete grid[row_][col_];
                    grid[row_][col_] = nullptr;
                    hasAnt = true;
                    hasMoved = true;
                } else {
                    ++count;
                }
            } else {
                ++count;
            }
        } else if (random == 3) {
            if (col_ > 0) {
                if (!grid[row_][col_ - 1]) { //col-1 (left)
                    emptySpace[random] = true;
                } else if (grid[row_][col_ - 1]->getType() == ANT) {
                    this->step_++;
                    this->lastAte_ = 0;
                    delete grid[row_][col_ - 1];
                    grid[row_][col_ - 1] = new Doodlebug(row_, col_ - 1, step_, age_ + 1, lastAte_);
                    delete grid[row_][col_];
                    grid[row_][col_] = nullptr;
                    hasAnt = true;
                    hasMoved = true;
                } else {
                    ++count;
                }
            } else {
                ++count;
            }
        }
    } while (!hasAnt && (!check[0] || !check[1] || !check[2] || !check[3]));
    if (!hasAnt) { //if no ant was found
        //checks if any of the spaces checked were empty
        if (emptySpace[0] || emptySpace[1] || emptySpace[2] || emptySpace[3]) {
            do { //if there were empty spaces, picks random numbers until
                 //it picks one of the empty ones
                random = rand() % 4;
            } while (!emptySpace[random]);
            //moves to an empty space
            if (random == 0) {
                this->lastAte_++;
                this->step_++;
                grid[row_ + 1][col_] = new Doodlebug(row_ + 1, col_, step_, age_ + 1, lastAte_);
                delete grid[row_][col_];
                grid[row_][col_] = nullptr;
                hasMoved = true;
            } else if (random == 1) {
                this->lastAte_++;
                this->step_++;
                grid[row_ - 1][col_] = new Doodlebug(row_ - 1, col_, step_, age_ + 1, lastAte_);
                delete grid[row_][col_];
                grid[row_][col_] = nullptr;
                hasMoved = true;
            } else if (random == 2) {
                this->lastAte_++;
                this->step_++;
                grid[row_][col_ + 1] = new Doodlebug(row_, col_ + 1, step_, age_ + 1, lastAte_);
                delete grid[row_][col_];
                grid[row_][col_] = nullptr;
                hasMoved = true;
            } else if (random == 3) {
                this->lastAte_++;
                this->step_++;
                grid[row_][col_ - 1] = new Doodlebug(row_, col_ - 1, step_, age_ + 1, lastAte_);
                delete grid[row_][col_];
                grid[row_][col_] = nullptr;
                hasMoved = true;
            }
        }
    }
    if (!hasMoved) { //still increases steps and age if not moved
        this->step_++;
        increaseAge();
    }
}

void Doodlebug::breed(Critter ***grid, Game game) {
    bool check[4] = {false, false, false, false};
    bool hasBred = false;
    int count = 0;
    int random;
    //breed function is the same as Ant::breed(Critter***, Game)
    //except checks for different ages
    if (age_ > 7) {
        if (age_ % 8 == 0) {
            do {
                do {
                    random = rand() % 4;
                } while (check[random]);
                check[random] = true;
                if (random == 0) {
                    if (row_ + 1 < game.getRows()) {
                        if (!grid[row_ + 1][col_]) {
                            grid[row_ + 1][col_] = new Doodlebug(row_ + 1, col_, step_);
                            hasBred = true;
                        } else {
                            ++count;
                        }
                    } else {
                        ++count;
                    }
                } else if (random == 1) {
                    if (row_ > 0) {
                        if (!grid[row_ - 1][col_]) {
                            grid[row_ - 1][col_] = new Doodlebug(row_ - 1, col_, step_);
                            hasBred = true;
                        } else {
                            ++count;
                        }
                    } else {
                        ++count;
                    }
                } else if (random == 2) {
                    if (col_ + 1 < game.getCols()) {
                        if (!grid[row_][col_ + 1]) {
                            grid[row_][col_ + 1] = new Doodlebug(row_, col_ + 1, step_);
                            hasBred = true;
                        } else {
                            ++count;
                        }
                    } else {
                        ++count;
                    }
                } else if (random == 3) {
                    if (col_ > 0) {
                        if (!grid[row_][col_ - 1]) {
                            grid[row_][col_ - 1] = new Doodlebug(row_, col_ - 1, step_);
                            hasBred = true;
                        } else {
                            ++count;
                        }
                    } else {
                        ++count;
                    }
                }
            } while (!hasBred && count < 4);
        }
    }
}

void Doodlebug::starve(Critter ***grid) {
    //deletes starving Doodlebugs
    //age check happens in grid_functions.cpp to reduce function calls
    delete grid[row_][col_];
    grid[row_][col_] = nullptr;
}
