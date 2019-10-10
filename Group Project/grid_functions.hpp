/*********************************************************************
** File name:    grid_functions.hpp
** Author:       Group 3
** Date:         02/14/19
** Description:  Header file for grid functions of Predator-Prey game
*********************************************************************/

#ifndef GRID_FUNCTIONS_HPP
#define GRID_FUNCTIONS_HPP

Critter ***createGrid(Critter ***, Game);

void print(Critter ***, Game);

void executeStep(Critter ***, Game, int);

void clearMemory(Critter ***, Game);

void populate(Critter ***, Game);

#endif
