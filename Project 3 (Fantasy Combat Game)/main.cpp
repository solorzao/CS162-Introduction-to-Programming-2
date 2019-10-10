/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 3
* Date: 16 Feb 2019
* Description:  This is the main function for the Fantasy Combat
* Game program. It creates a game and controls flow.
*******************************************************************/

#include <iostream>
#include <ctime>  //include ctime library for seeding rand()

#include "game.hpp"

int main()
{
	Game game1;  //create instance of game class
	bool playAgain = false;  //create bool for asking user if they want to continue playing

	std::srand(time(0));  //seeding function for rand()

	game1.intro();  //output intro, program title

	do {

		game1.character_selection();  //choose characters
		game1.battle();  //battle 

		playAgain = game1.ask_to_play_again();  //ask user if they want to play again

	} while (playAgain);  //if user wants to keep playing, keep looping

	return 0;
}