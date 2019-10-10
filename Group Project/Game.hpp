/*********************************************************************
** File name:    Game.hpp
** Author:       Group 3
** Date:         02/14/19
** Description:  Declaration of the Game class
**               Game class stores parameters for the Predator-Prey
**               simulation.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

class Game {
private:
    int rows_ = 20,
            cols_ = 20,
            ants_ = 100,
            doodles_ = 5,
            steps_ = 0;
public:

    Game();

    //Game(int, int, int, int, int);

    void setSteps(int);

    void setRows(int);

    void setColumns(int);

    void setAnts(int);

    void setDoodles(int);

    int getRows();

    int getCols();

    int getAnts();

    int getDoodles();

    int getSteps();
};

#endif
