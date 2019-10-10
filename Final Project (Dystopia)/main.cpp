/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Main function for the game. Controls flow and
* game continuity.
*********************************************************************/

#include <iostream>
#include "game.hpp"

int main()
{
	bool play = true;

	while (play)  //while user hasn't passed or decided to quit, keep playing
	{
		Game *game1 = new Game;
		game1->intro();
		play = game1->playGame();
		delete game1;  //free allocated memory
	}

	return 0;
}
