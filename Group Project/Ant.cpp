/*********************************************************************
** File name:    Ant.cpp
** Author:       Group 3
** Date:         02/14/19
** Description:  Definitions for Ant class
**               child of Critter class
*********************************************************************/

#include "Game.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include <iostream>

Ant::Ant(int r, int c, int s) : Critter::Critter(r, c) {
    this->type_ = ANT;
    this->step_ = s;
}

Ant::Ant(int r, int c, int s, int a) : Critter::Critter(r, c) {
    this->type_ = ANT;
    this->step_ = s;
    this->age_ = a;
}

void Ant::move(Critter ***grid, Game game) {
    int random;
    int count = 0;
    bool emptySpace = false;
    bool check[4] = {false, false, false, false};
    bool hasMoved = false;
    do { //loops while !emptySpace, and !check[0-3]
        if (!check[0] || !check[1] || !check[2] || !check[3]) { //if any are false
            do { //loops while !emptySpace and count < 4
                do {
                    random = rand() % 4;
                } while (check[random]);
                check[random] = true;
                if (random == 0) {
                    //if row_+1 (down) is null and not out of bounds
                    if (row_ + 1 < game.getRows() && !grid[row_ + 1][col_]) {
                        emptySpace = true; //emptySpace is now true
                        this->step_++;
                        //copy critter to new spot, set old spot as nullptr
                        grid[row_ + 1][col_] = new Ant(row_ + 1, col_, step_, age_ + 1);
                        delete grid[row_][col_];
                        grid[row_][col_] = nullptr;
                        hasMoved = true;
                        //this->setRow(row_ + 1);
                    } else { //if row_+1 (down) is not null
                        ++count; //just increase the count
                    }
                } else if (random == 1) {
                    if (row_ > 0 && !grid[row_ - 1][col_]) { //row_-1 (up)
                        emptySpace = true;
                        this->step_++;
                        grid[row_ - 1][col_] = new Ant(row_ - 1, col_, step_, age_ + 1);
                        delete grid[row_][col_];
                        grid[row_][col_] = nullptr;
                        hasMoved = true;
                        //this->setRow(row_ - 1);
                    } else {
                        ++count;
                    }
                } else if (random == 2) {
                    if (col_ + 1 < game.getCols() && !grid[row_][col_ + 1]) { //col+1 (right)
                        emptySpace = true;
                        this->step_++;
                        grid[row_][col_ + 1] = new Ant(row_, col_ + 1, step_, age_ + 1);
                        delete grid[row_][col_];
                        grid[row_][col_] = nullptr;
                        hasMoved = true;
                        //this->setCol(col_ + 1);
                    } else {
                        ++count;
                    }
                } else if (random == 3) {
                    if (col_ > 0 && !grid[row_][col_ - 1]) { //col-1 (left)
                        emptySpace = true;
                        this->step_++;
                        grid[row_][col_ - 1] = new Ant(row_, col_ - 1, step_, age_ + 1);
                        delete grid[row_][col_];
                        grid[row_][col_] = nullptr;
                        hasMoved = true;
                        //this->setCol(col_ - 1);
                    } else {
                        ++count;
                    }
                }
            } while (!emptySpace && count < 4);
        }
    } while (!emptySpace && (!check[0] || !check[1] || !check[2] || !check[3]));
    if (!hasMoved) { //if ant never moves, still increases step and age
        this->step_++;
        increaseAge();
    }
}

void Ant::breed(Critter ***grid, Game game) {
    bool check[4] = {false, false, false, false};
    bool hasBred = false;
    int count = 0;
    int random;
    if (age_ > 2) { //checks that the ant is old enough
        if (age_ % 3 == 0) { //ants breed every 3 steps in age
            do { //loops while !hasBred && directions checked (count) < 4
                do { //picks a random direction, loops if already checked
                    random = rand() % 4;
                } while (check[random]);
                check[random] = true;
                if (random == 0) {  //row+1 (down)
                    //checks that the spot is in bounds
                    if (row_ + 1 < game.getRows()) {
                        //if nullptr
                        if (!grid[row_ + 1][col_]) {
                            //breeds
                            grid[row_ + 1][col_] = new Ant(row_ + 1, col_, step_);
                            hasBred = true;
                        } else {  //else increases count of directions checked
                            ++count;
                        }
                    } else { //increases count if spot is out of bounds
                        ++count;
                    }
                } else if (random == 1) {  //row-1 (up)
                    if (row_ > 0) {
                        if (!grid[row_ - 1][col_]) {
                            grid[row_ - 1][col_] = new Ant(row_ - 1, col_, step_);
                            hasBred = true;
                        } else {
                            ++count;
                        }
                    } else {
                        ++count;
                    }
                } else if (random == 2) {  //col+1 (right)
                    if (col_ + 1 < game.getCols()) {
                        if (!grid[row_][col_ + 1]) {
                            grid[row_][col_ + 1] = new Ant(row_, col_ + 1, step_);
                            hasBred = true;
                        } else {
                            ++count;
                        }
                    } else {
                        ++count;
                    }
                } else if (random == 3) {  //col-1 (left)
                    if (col_ > 0) {
                        if (!grid[row_][col_ - 1]) {
                            grid[row_][col_ - 1] = new Ant(row_, col_ - 1, step_);
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

void Ant::starve(Critter ***grid) {
    delete grid[row_][col_];
    grid[row_][col_] = nullptr;
}
