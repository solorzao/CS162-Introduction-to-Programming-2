/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Specification file for the final room class. Declares
* functions.
*********************************************************************/

#ifndef ROOMB_HPP
#define ROOMB_HPP

#include "space.hpp"

class RoomB : public Space  //inherit from abstract class
{
public:

	RoomB();  //constructor

	virtual Space* getRight() override;  //override virtual functions to make concrete class
	virtual Space* getLeft() override;
	virtual Space* getTop() override;
	virtual Space* getBottom() override;
	virtual std::string getName() override;

	virtual void setRight(Space*) override;
	virtual void setLeft(Space*) override;
	virtual void setTop(Space*) override;
	virtual void setBottom(Space*) override;

	virtual int trial(Player*) override;

	virtual ~RoomB() {};  //destructor

};

#endif