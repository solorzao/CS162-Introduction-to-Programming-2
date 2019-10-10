/*********************************************************************
** File name:    Critter.cpp
** Author:       Group 3
** Date:         02/14/19
** Description:  Creates critter object
*********************************************************************/

#include "Game.hpp"
#include "Critter.hpp"

Critter::Critter(int r, int c) {
    this->row_ = r;
    this->col_ = c;
    this->age_ = 0;
    this->lastAte_ = 0;
}

Critter::~Critter() {

}

void Critter::setRow(int r) {
    this->row_ = r;
}

void Critter::setCol(int c) {
    this->col_ = c;
}

void Critter::increaseAge() {
    this->age_++;
}

int Critter::getRow() {
    return this->row_;
}

int Critter::getCol() {
    return this->col_;
}

int Critter::getAge() {
    return this->age_;
}

int Critter::getStep() {
    return this->step_;
}

Type Critter::getType() {
    return this->type_;
}

void Critter::move(Critter ***, Game) {

}

void Critter::breed(Critter ***, Game) {

}

int Critter::getLastAte() {
    return lastAte_;
}

void Critter::starve(Critter ***) {

}

void Critter::setType(Type type) {
    type_ = type;
}
