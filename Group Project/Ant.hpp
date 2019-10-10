/*********************************************************************
** File name:    Ant.hpp
** Author:       Group 3
** Date:         02/14/19
** Description:  Declaration of Ant class
**               child of Critter class
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

class Ant : public Critter {
private:
public:
    Ant(int, int, int);

    Ant(int, int, int, int);

    void move(Critter ***, Game);

    void breed(Critter ***, Game);

    void starve(Critter ***);
};

#endif
