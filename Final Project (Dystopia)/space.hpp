/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Specification file for the space class. It is abstract
* and contains virtual functions.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include "player.hpp"

class Space
{
protected:

	Space *top = nullptr;  //pointers to other space objects
	Space *right = nullptr;
	Space *left = nullptr;
	Space *bottom = nullptr;

	std::string name;  //name of space
	
public: 
	
	virtual Space* getRight() = 0;  //virtual functions
	virtual Space* getLeft() = 0;
	virtual Space* getTop() = 0;
	virtual Space* getBottom() = 0;
	virtual std::string getName() = 0;
	virtual void setRight(Space*) = 0;
	virtual void setLeft(Space*) = 0;
	virtual void setTop(Space*) = 0;
	virtual void setBottom(Space*) = 0;

	virtual int trial(Player*) = 0;

	virtual ~Space(){}; //virtual destructor
};

#endif