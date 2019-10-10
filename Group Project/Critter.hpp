/*********************************************************************
** File name:    Critter.hpp
** Author:       Group 3
** Date:         02/14/19
** Description:  Creates critter object
*********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

enum Type {
    ANT, DOODLEBUG
};

class Critter {
protected:
    int row_, col_, age_, step_;
    int lastAte_;
    Type type_;
public:
    Critter(int, int);

    virtual ~Critter();

    void setRow(int);

    void setCol(int);

    void increaseAge();

    void setType(Type);

    int getRow();

    int getCol();

    int getAge();

    int getStep();

    virtual int getLastAte();

    Type getType();

    virtual void move(Critter ***, Game) = 0;

    virtual void breed(Critter ***, Game) = 0;

    virtual void starve(Critter ***) = 0;
};

#endif
