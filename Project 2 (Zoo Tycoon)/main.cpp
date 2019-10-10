/******************************************************************
 * * Name: Oliver Solorzano
 * * Course: CS 162 W 2019
 * * Assignment: Project 2 (Zoo Tycoon)
 * * Date: 03 Jan 2019
 * * Description: This is the implementation file for the main function 
 * * in the Zoo Tycoon program. It sets up the game and loops through 
 * * each day. It exits based on user input and ends the program.
 * *******************************************************************/

#include <iostream>
#include "zoo.hpp"  //Include header file for Zoo class

using std::cin;

int main()
{
	Zoo game;		//create instance of zoo class for game
	bool play = false;		//declare bool and initialize to false

	game.set_up_game();  //set up game variables

	do
	{
		play = game.zoo_day();  //return bool after each day, stating if user wants to play or not

	} while (play != false);  //keep looping while user wants to keep playing

	return 0;
}
