/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 3
* Date: 16 Feb 2019
* Description:  This is the implementation file for the game class.
* It defines all the functions for the game class.
*******************************************************************/

#include "game.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"

#include <string> 
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void Game::intro()  //print program title to user
{
	cout << "**********Welcome to the Fantasy Combat Game**********" << endl;
}

void Game::character_selection()  
{
	int loopNum = 0; //set loop number, needs to go through twice

	do
	{
		std::string userChoice;
		cout << "\nSelect two characters to battle, may the best one win!" << endl;

		if (loopNum == 0) //if on first loop, choose first character
		{
			cout << "\nPlease choose your first character from the options below: " << endl;
		}
		else if (loopNum == 1)  //if on second loop, choose second character
		{
			cout << "\nPlease choose your second character from the options below: " << endl;
		}

		cout << "\n1. Vampire" << endl;  //print menu to user
		cout << "\n2. Barbarian" << endl;
		cout << "\n3. Blue Men" << endl;
		cout << "\n4. Medusa" << endl;
		cout << "\n5. Harry Potter" << endl;

		cout << "\nPlease choose an option and press [Enter] ";

		getline(cin, userChoice);  //get user choice  

		if (userChoice == "1") //choose vampire
		{
			cout << "\n***You chose Vampire***\n" << endl;
			players[loopNum] = new Vampire;  //create new vampire object in character array
			loopNum += 1; //increment loop count
		}

		else if (userChoice == "2")  //choose barbarian
		{
			cout << "\n***You chose Barbarian***\n" << endl;
			players[loopNum] = new Barbarian;  //create new vampire object in character array
			loopNum += 1;  //increment loop count
		}

		else if (userChoice == "3")  //choose blue men
		{
			cout << "\n***You chose Blue Men***\n" << endl;
			players[loopNum] = new BlueMen;  //create new blue men object in array
			loopNum += 1;  //increment loop count
		}
		else if (userChoice == "4")  //choose medusa 
		{
			cout << "\n***You chose Medusa***\n" << endl;
			players[loopNum] = new Medusa;  //create new medusa object in array
			loopNum += 1;  //increment loop count
		}
		else if (userChoice == "5")
		{
			cout << "\n***You chose Harry Potter***" << endl;
			players[loopNum] = new HarryPotter;  //create new harry potter object
			loopNum += 1;  //increment loop count
		}

		else
		{
			cout << "\n***Invalid option, please try again***" << endl;
		}

	} while (loopNum != 2);  //once user selects two, exit loop

}

bool Game::ask_to_play_again()  //function to ask player to loop again
{
	int userChoice;  
	bool valid = false;
	bool playAgain;

	do
	{
		cout << "\nWhat would you like to do? " << endl;

		cout << "\n1. Play again " << endl;
		cout << "2. Exit the game " << endl;

		cout << "\nPlease choose (1) or (2) and press [Enter] " << endl;

		cin >> userChoice;

		cin.clear();
		cin.ignore(100, '\n');

		if (userChoice == 1)  //play again
		{
			cout << "\n***You chose to play again!***" << endl;
			playAgain = true;  //return bool
			valid = true;  //set to true to exit
		}

		else if (userChoice == 2)
		{
			cout << "\n***You chose to exit the game, goodbye!***" << endl;
			playAgain = false;  //return bool
			valid = true;  //set to true to exit
		}

		else
		{
			cout << "\n***Invalid entry, please try again.***" << endl;
		}
		
	} while (!valid);  //if not valid, keep looping

	return playAgain;  //return bool to keep playing or not
}

int Game::roll_die_turn()  //roll die for who goes first
{
	int roll = rand() % 6 + 1;
	return roll;
}

void Game::battle()
{
	int roll_result = roll_die_turn();  //roll die
	int round_count = 1;  //track rounds

	cout << "Let the battle begin! " << endl;

	cout << "\nPress [Enter] to start the first round! " << endl;
	cin.get();

	if (roll_result > 3)  //if roll > 3, player 1 attacks first
	{
		do 
		{
			cout << "Round #" << round_count << endl;

			display_status1_pre();
			players[1]->defense(players[0]->attack());  //player 1 attacks, print pre and post info of attack
			display_status1_post();

			if (players[1]->get_strength() > 0)  
			{
				display_status2_pre();
				players[0]->defense(players[1]->attack());  //if player 2 not dead, player 2 attacks, print pre and post info 
				display_status2_post();
			}

			round_count++; //increment round counter

			if ((players[1]->get_strength() > 0) && (players[0]->get_strength() > 0))  //if not dead, print next round option
			{
				cout << "\nPress [Enter] to play the next round! " << endl;
				cin.get();
			}
			

		} while ((players[1]->get_strength() > 0) && (players[0]->get_strength() > 0));  //if not dead, play next round
	}
	else if (roll_result <= 3)  //if roll <= 3, player 2 goes first
	{
		do
		{
			cout << "\nRound #" << round_count << endl;  //print round

			display_status2_pre();
			players[0]->defense(players[1]->attack()); //player 2 attacks, print pre and post info of attack
			display_status2_post();

			if (players[0]->get_strength() > 0)
			{
				display_status1_pre();
				players[1]->defense(players[0]->attack()); //if player 1 not dead, player 1 attacks, print pre and post info 
				display_status1_post();
			}

			round_count++;

			if ((players[1]->get_strength() > 0) && (players[0]->get_strength() > 0))  //if not dead, print next round option
			{
				cout << "\nPress [Enter] to play the next round! " << endl;
				cin.get();
			}
			
		} while ((players[1]->get_strength() > 0) && (players[0]->get_strength() > 0));  //if not dead, play next round
	}

	cout << "\n***The battle is over! ";

	if (players[0]->get_strength() <= 0)  //if player 1 is dead, player 2 wins
	{
		cout << "Player 2: " << players[1]->get_type() << " has won the match!***" << endl;
	}

	else if (players[1]->get_strength() <= 0)  //if player 2 is dead, player 1 wins
	{
		cout << "Player 1: " <<  players[0]->get_type() << " has won the match!***" << endl;
	}

	delete players[0];  //delete objects after battle ends
	delete players[1];

}

void Game::display_status1_pre()  //pre attack stats for player 1 as attacker
{
	cout << "\nAttacker: " << players[0]->get_type() << " (Player 1)" << endl;
	cout << "Defender: " << players[1]->get_type() << " (Player 2)" << " Armor: " << players[1]->get_armor() << " HP: " << players[1]->get_strength() << endl;
}

void Game::display_status1_post()
{
	if (players[1]->get_damage_taken() == 0 && (players[1]->charm_check()))  //if charmed, let user know
	{
		cout << players[0]->get_type() << " was charmed and didn't attack this turn!" << endl;
	}

	else  //print post attack stats if not charmed
	{
		cout << "Damage dealt by " << players[0]->get_type() << " was: " << players[0]->get_attack_pts() << endl;
		cout << "Damage blocked by " << players[1]->get_type() << " was: " << players[1]->get_defense_pts() << endl;
	}

	cout << players[1]->get_type() << "'s HP is now: " << players[1]->get_strength() << endl;
}

void Game::display_status2_pre()  //pre attack stats for player 2 as attacker
{
	cout << "\nAttacker: " << players[1]->get_type() << " (Player 2)" << endl;
	cout << "Defender: " << players[0]->get_type() << " (Player 1)" << " Armor: " << players[0]->get_armor() << " HP: " << players[0]->get_strength() << endl;
}

void Game::display_status2_post()
{
	if ((players[0]->get_damage_taken() == 0) && (players[0]->charm_check()))  //if charmed let user know
	{
		cout << players[1]->get_type() << " was charmed and didn't attack this turn!" << endl;
	}

	else  //print post attack stats if not charmed
	{
		cout << "Damage dealt by " << players[1]->get_type() << " was: " << players[1]->get_attack_pts() << endl;
		cout << "Damage blocked by " << players[0]->get_type() << " was: " << players[0]->get_defense_pts() << endl;
	}

	cout << players[0]->get_type() << "'s HP is now: " << players[0]->get_strength() << endl;
}

