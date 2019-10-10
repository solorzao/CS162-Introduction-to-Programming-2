/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Specification file for the player class. Declares
* functions.
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
private:

	int score, itemCount;  //declare variables
	std::string inventory[6];  //array to hold items

public:

	Player();  //constructor

	int getScore();  //declare functions
	void setScore(int);
	void viewInventory();
	bool checkInventory(std::string);
	void addToInventory(std::string);

};
#endif


