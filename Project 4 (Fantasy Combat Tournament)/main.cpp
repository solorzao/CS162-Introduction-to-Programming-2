/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 4
* Date: 03 Mar 2019
* Description:  This is the main function for the Fantasy Combat
* Game program. It creates a game and controls flow.
*******************************************************************/

#include <iostream>
#include <ctime>  //include ctime library for seeding rand()

#include "game.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	bool play = false;
	bool playAgain = false;  //create bool for asking user if they want to continue playing
	int game_count = 0;
	std::srand(time(0));  //seeding function for rand()

	do
	{
		Game *game1 = new Game;  //create pointer to new game object
		
		game1->intro();  //output intro, program title

		if (game_count <= 0) //only print initial ask once
		{
			play = game1->ask_to_play();
			game_count++; //increment so loop only runs once
		}
		
		if (play)
		{
			bool tournament_done = false;

			game1->character_selection();  //choose characters

			do
			{
				tournament_done = game1->battle();  //battle

			} while (!tournament_done); //if tournament isn't done, battle again

			delete game1;  //delete game object after finish
		}

		playAgain = game1->ask_to_play_again();  //ask user if they want to play again

	} while (playAgain); //if user wants to play again make new game

	return 0;
}
