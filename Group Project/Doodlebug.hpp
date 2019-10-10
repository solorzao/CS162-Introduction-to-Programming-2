/*********************************************************************
** File name:    Doodlebug.hpp
** Author:       Group 3
** Date:         02/14/19
** Description:  Declaration of the Doodlebug class
**               child of Critter class
*********************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

class Doodlebug : public Critter {
private:
    //int lastAte;  [moved to critter]
public:
    Doodlebug(int, int, int);

    Doodlebug(int, int, int, int, int);

    int getLastAte();

    void move(Critter ***, Game);

    void breed(Critter ***, Game);

    void starve(Critter ***);
};

#endif
