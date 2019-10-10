/*********************************************************************
** File name:    grid_functions.cpp
** Author:       Group 3
** Date:         02/14/19
** Description:  Functions file for grid of Predator-Prey game
*********************************************************************/

#include "Game.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "grid_functions.hpp"
#include <iostream>

Critter ***createGrid(Critter ***grid, Game game) {
    //dynamically allocate 2d array of pointers
    grid = new Critter **[game.getRows()];
    for (int r = 0; r < game.getRows(); r++) {
        grid[r] = new Critter *[game.getCols()];
        //intiates all pointers to nullptr
        for (int c = 0; c < game.getCols(); c++) {
            grid[r][c] = nullptr;
        }
    }
    return grid;
}

void print(Critter ***grid, Game game) {
    for (int r = 0; r < game.getRows(); r++) {
        //Top border
        if (r == 0) {
            for (int i = 0; i < ((game.getCols()) + 2); i++) {
                std::cout << "-";
            }
            std::cout << std::endl;
        }

        for (int c = 0; c < game.getCols(); c++) {

            //Left border
            if (c == 0) {
                std::cout << "|";
            }
            if (!grid[r][c]) {
                std::cout << " ";
            } else {
                if (grid[r][c]->getType() == ANT) {
                    std::cout << "O";
                } else {
                    std::cout << "X";
                }
            }

            //Right border
            if (c == (game.getCols() - 1)) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;

    }

    //Bottom Border
    for (int i = 0; (i < game.getCols() + 2); i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void executeStep(Critter ***grid, Game game, int step) {
    //move doodlebugs
    for (int r = 0; r < game.getRows(); r++) {
        for (int c = 0; c < game.getCols(); c++) {
            //checks if DOODLEBUG
            if (grid[r][c] && grid[r][c]->getType() == DOODLEBUG) {
                //checks if on the same step (hasn't moved yet)
                if (grid[r][c]->getStep() == step) {
                    grid[r][c]->move(grid, game);
                }
            }
        }
    }
    //move ants
    for (int r = 0; r < game.getRows(); r++) {
        for (int c = 0; c < game.getCols(); c++) {
            if (grid[r][c] && grid[r][c]->getType() == ANT) {
                if (grid[r][c]->getStep() == step) {
                    grid[r][c]->move(grid, game);
                }
            }
        }
    }
    //breed
    for (int r = 0; r < game.getRows(); r++) {
        for (int c = 0; c < game.getCols(); c++) {
            if (grid[r][c]) {
                grid[r][c]->breed(grid, game);
            }
        }
    }
    //starve
    for (int r = 0; r < game.getRows(); r++) {
        for (int c = 0; c < game.getCols(); c++) {
            if (grid[r][c] && grid[r][c]->getType() == DOODLEBUG) {
                //if age of doodlebugs is at least 3
                if (grid[r][c]->getLastAte() > 2) {
                    //they starve
                    grid[r][c]->starve(grid);
                }
            }
        }
    }
}

void clearMemory(Critter ***grid, Game game) {
    //clears all dynamically allocated memory
    for (int i = 0; i < game.getRows(); i++) {
        for (int j = 0; j < game.getCols(); j++) {
            delete grid[i][j];
        }
        delete[] grid[i];
    }
    delete[] grid;
}

void populate(Critter ***grid, Game game) {
    int amax = game.getAnts(); //number of ants to place
    int dmax = game.getDoodles(); //number of doodlebugs to place
    int rmax = game.getRows();
    int cmax = game.getCols();
    int t = rmax * cmax; // total number of available spaces

    int a = amax; //initialize ant counter
    int d = dmax; //initialize doodlebug counter
    //loop through grid while there are still critters to place
    while ((a > 0) || (d > 0)) {
        for (int r = 0; r < rmax; r++) {
            for (int c = 0; c < cmax; c++) {
                if (!grid[r][c]) {
                    int roll = std::rand() % (t) + 1; //roll to see if anything is placed
                    if ((roll <= amax) && a > 0) {
                        grid[r][c] = new Ant(r, c, 0); //place ant
                        a--; //decrement number of ants left to place
                    } else if ((roll > (t - dmax)) && (d > 0)) {
                        grid[r][c] = new Doodlebug(r, c, 0); //place doodlebug
                        d--; //decrement number of doodlebugs left to place
                    }
                }
            }
        }
    }
}
