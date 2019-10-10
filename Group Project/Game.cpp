/*********************************************************************
** File name:    Game.cpp
** Author:       Group 3
** Date:         02/14/19
** Description:  Definitions for Game class
**               Game class stores parameters for the Predator-Prey
**               simulation.
*********************************************************************/

#include "Game.hpp"

Game::Game() {
    rows_ = 20;
    cols_ = 20;
    ants_ = 100;
    doodles_ = 5;
    steps_ = 0;
}

/*Game::Game(int r, int c, int a, int d, int s) {
    rows_ = r;
    cols_ = c;
    ants_ = a;
    doodles_ = d;
    steps_ = s;
}*/

void Game::setSteps(int s) {
    steps_ = s;
}

int Game::getRows() {
    return rows_;
}

int Game::getCols() {
    return cols_;
}

int Game::getAnts() {
    return ants_;
}

int Game::getDoodles() {
    return doodles_;
}

int Game::getSteps() {
    return steps_;
}

void Game::setDoodles(int d) {
    doodles_ = d;
}

void Game::setAnts(int a) {
    ants_ = a;
}

void Game::setColumns(int c) {
    cols_ = c;
}

void Game::setRows(int r) {
    rows_ = r;
}
