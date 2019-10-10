/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Specification file for the room C class. Declares
* functions.
*********************************************************************/

#ifndef ROOMC_HPP
#define ROOMC_HPP

#include "space.hpp"

class RoomC : public Space  //inherit from abstract class
{
public:

	RoomC();  //constructor

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

	virtual ~RoomC() {};  //destructor

};
#endif