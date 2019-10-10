/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Specification file for the start room class. Declares
* functions.
*********************************************************************/

#ifndef STARTROOM_HPP
#define STARTROOM_HPP

#include "space.hpp"
#include "player.hpp"

class startRoom: public Space  //inherits from abstract class
{
public:

	startRoom();  //constructor

	virtual Space* getRight() override;  //overrides virtual functions to create concrete class
	virtual Space* getLeft() override;
	virtual Space* getTop() override;
	virtual Space* getBottom() override;
	virtual std::string getName() override;

	virtual void setRight(Space*) override;
	virtual void setLeft(Space*) override;
	virtual void setTop(Space*) override;
	virtual void setBottom(Space*) override;

	virtual int trial(Player*) override;

	virtual ~startRoom() {};  //destructor

};

#endif
