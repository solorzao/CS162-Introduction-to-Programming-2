/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Specification file for the game class. Declares
* functions.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "space.hpp"
#include "player.hpp"
#include "startRoom.hpp"

class Game
{
public:

	Space *currentRoom = nullptr;  //declare pointers to keep track of rooms
	Space *temp = nullptr;
	Space *temp1 = nullptr;
	Space *temp2 = nullptr;
	Player *inmate = nullptr;

	Game(); //constructor

	void updateCurrentRoom(Space *);  //declare functions
	void intro();
	bool playGame();
	bool winMessage();
	void loseMessage();
	bool exitMessage();
	

	~Game();  //destructor

};
#endif


