/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 4
* Date: 03 Mar 2019
* Description:  This is the implementation file for the game class.
* It defines all the functions for the game class.
*******************************************************************/

#include "game.hpp"
#include "queue.hpp"

#include <string> 
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

Game::Game()
{
	team1Lineup = new Queue;
	team2Lineup = new Queue;
	losers = new Queue;
}

void Game::intro()  //print program title to user
{
	cout << "**********Welcome to the Fantasy Combat Game**********" << endl;
}

void Game::character_selection()
{
	int loopNum = 0, teamLimit, team1Total = 0, team2Total = 0; //create variables to hold selection limits, loop counter
	
	bool valid = false;

	std::string characterName;
	
	cout << "\nSelect your teams!" << endl;

	do
		{
			cout << "\nHow many fighters would you like on each team? (Max: 10): ";

			cin >> teamLimit;  //ask user for input

			cin.clear();  //clear input for next
			cin.ignore(100, '\n');

			if (cin.fail())  //if not int, ask again
			{
				cout << "\n**********Invalid entry. Please try again**********" << endl;
			}

			else if (teamLimit >= 1 && teamLimit <= 10)
			{
				cout << "\nEach team will have " << teamLimit << " fighters! " << endl;
				team1Total = team2Total = teamLimit;
				valid = true;
			}

			else //if out of range, ask again
			{
				cout << "\n**********Invalid entry. Please try again**********" << endl;
			}

		} while (valid != true);

	do
	{
		std::string userChoice;
		
		cout << "\nPlease choose a character for Team 1 from the options below: " << endl;
		cout << "\nYou have " << team1Total << " choices remaining." << endl;

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
			cout << "What would you like to name this fighter? ";

			getline(cin, characterName);

			team1Lineup->addBack(userChoice, characterName);

			team1Total -= 1; //increment loop count
		}

		else if (userChoice == "2")  //choose barbarian
		{
			cout << "\n***You chose Barbarian***\n" << endl;
			cout << "What would you like to name this fighter? ";

			getline(cin, characterName);

			team1Lineup->addBack(userChoice, characterName);

			team1Total -= 1; //increment loop count
		}

		else if (userChoice == "3")  //choose blue men
		{
			cout << "\n***You chose Blue Men***\n" << endl;
			cout << "What would you like to name this fighter? ";

			getline(cin, characterName);

			team1Lineup->addBack(userChoice, characterName);

			team1Total -= 1; //increment loop count
		}
		else if (userChoice == "4")  //choose medusa 
		{
			cout << "\n***You chose Medusa***\n" << endl;
			cout << "What would you like to name this fighter? ";

			getline(cin, characterName);

			team1Lineup->addBack(userChoice, characterName);

			team1Total -= 1; //increment loop count
		}
		else if (userChoice == "5")
		{
			cout << "\n***You chose Harry Potter***" << endl;
			cout << "What would you like to name this fighter? ";

			getline(cin, characterName);

			team1Lineup->addBack(userChoice, characterName);

			team1Total -= 1; //increment loop count
		}

		else
		{
			cout << "\n***Invalid option, please try again***" << endl;
		}

	} while (team1Total != 0);  //once user selects two, exit loop

	do
	{
		std::string userChoice;

		cout << "\nPlease choose a character for Team 2 from the options below: " << endl;
		cout << "\nYou have " << team2Total << " choices remaining." << endl;

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
			cout << "What would you like to name this fighter? ";

			getline(cin, characterName);

			team2Lineup->addBack(userChoice, characterName);

			team2Total -= 1; //increment loop count
			
		}

		else if (userChoice == "2")  //choose barbarian
		{
			cout << "\n***You chose Barbarian***\n" << endl;
			cout << "What would you like to name this fighter? ";

			getline(cin, characterName);

			team2Lineup->addBack(userChoice, characterName);

			team2Total -= 1; //increment loop count
		}

		else if (userChoice == "3")  //choose blue men
		{
			cout << "\n***You chose Blue Men***\n" << endl;
			cout << "What would you like to name this fighter? ";

			getline(cin, characterName);

			team2Lineup->addBack(userChoice, characterName);

			team2Total -= 1; //increment loop count
		}
		else if (userChoice == "4")  //choose medusa 
		{
			cout << "\n***You chose Medusa***\n" << endl;
			cout << "What would you like to name this fighter? ";

			getline(cin, characterName);

			team2Lineup->addBack(userChoice, characterName);

			team2Total -= 1; //increment loop count
		}
		else if (userChoice == "5")
		{
			cout << "\n***You chose Harry Potter***" << endl;
			cout << "What would you like to name this fighter? ";

			getline(cin, characterName);

			team2Lineup->addBack(userChoice, characterName);

			team2Total -= 1; //increment loop count
		}

		else
		{
			cout << "\n***Invalid option, please try again***" << endl;
		}

	} while (team2Total != 0);  //once user selects two, exit loop

	cout << "\nThe teams are: " << endl;	//print team lineupe to user

	cout << "\nTeam 1:\n" << endl;

	team1Lineup->printQueue();

	cout << "\nTeam 2: \n" << endl;

	team2Lineup->printQueue();

	cout << "\nLet the tournament begin!\n" << endl;

}

bool Game::ask_to_play()
{
	int userChoice;
	bool valid = false;
	bool play = false;

	do
	{
		cout << "\nWhat would you like to do? " << endl;

		cout << "\n1. Play " << endl;
		cout << "2. Exit " << endl;

		cout << "\nPlease choose (1) or (2) and press [Enter] ";

		cin >> userChoice;

		cin.clear();
		cin.ignore(100, '\n');

		if (userChoice == 1)  //play 
		{
			cout << "\n***You chose to play!***" << endl;
			play = true;  //return bool
			valid = true;  //set to true to exit
		}

		else if (userChoice == 2)  //exit
		{
			cout << "\n***You chose to exit, goodbye!***" << endl;
			play = false;  //return bool
			valid = true;  //set to true to exit
		}

		else
		{
			cout << "\n***Invalid entry, please try again.***" << endl;
		}

	} while (!valid);  //if not valid, keep looping

	return play;  //return bool to play or not
}

bool Game::ask_to_play_again()  //function to ask player to loop again
{
	int userChoice;
	bool valid = false;
	bool playAgain = false;

	do
	{
		cout << "What would you like to do? " << endl;

		cout << "\n1. Play again " << endl;
		cout << "2. Exit the game " << endl;

		cout << "\nPlease choose (1) or (2) and press [Enter] ";

		cin >> userChoice;

		cin.clear();
		cin.ignore(100, '\n');

		if (userChoice == 1)  //play again
		{
			cout << "\n***You chose to play again!***\n" << endl;
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

bool Game::battle()
{
	bool tournament_over = false;
	int roll_result = roll_die_turn();  //roll die
	int round_count = 1;  //track rounds

	cout << "\nBattle # " << battle_count << endl;
	
	//print names of fighters
	cout << "\nTeam 1: " << team1Lineup->head->fighter->get_name() << " (" << team1Lineup->head->fighter->get_type() << ") VS Team 2: " <<
		team2Lineup->head->fighter->get_name() << " (" << team2Lineup->head->fighter->get_type() << ")" << endl;

	cout << "\nLet the fight begin! " << endl;

	cout << "\nPress [Enter] to start the battle." << endl;
	cin.get();

	if (roll_result > 3)  //if roll > 3, team 1 attacks first
	{
		do
		{
			cout << "\nRound #" << round_count << endl;

			display_status1_pre();
			team2Lineup->head->fighter->defense(team1Lineup->head->fighter->attack());  //team 1 attacks, print pre and post info of attack
			display_status1_post();

			if (team2Lineup->head->fighter->get_strength() > 0)
			{
				display_status2_pre();
				team1Lineup->head->fighter->defense(team2Lineup->head->fighter->attack());  //if team 2 fighter not dead, attacks, print pre and post info 
				display_status2_post();
			}

			round_count++; //increment round counter

			if ((team2Lineup->head->fighter->get_strength() > 0) && (team1Lineup->head->fighter->get_strength() > 0))  //if not dead, print next round option
			{
				cout << "\nPress [Enter] to play the next round! " << endl;
				cin.get();
			}


		} while ((team2Lineup->head->fighter->get_strength() > 0) && (team1Lineup->head->fighter->get_strength() > 0));  //if not dead, play next round
	}
	else if (roll_result <= 3)  //if roll <= 3, player 2 goes first
	{
		do
		{
			cout << "\nRound #" << round_count << endl;  //print round

			display_status2_pre();
			team1Lineup->head->fighter->defense(team2Lineup->head->fighter->attack()); //team 2 attacks, print pre and post info of attack
			display_status2_post();

			if (team1Lineup->head->fighter->get_strength() > 0)
			{
				display_status1_pre();
				team2Lineup->head->fighter->defense(team1Lineup->head->fighter->attack()); //if team 1 fighter not dead, team 1 attacks, print pre and post info 
				display_status1_post();
			}

			round_count++; //increment round count

			if ((team2Lineup->head->fighter->get_strength() > 0) && (team1Lineup->head->fighter->get_strength() > 0))  //if not dead, print next round option
			{
				cout << "\nPress [Enter] to play the next round! " << endl;
				cin.get();
			}

		} while ((team2Lineup->head->fighter->get_strength() > 0) && (team1Lineup->head->fighter->get_strength() > 0));  //if not dead, play next round
	}

	cout << "\n***The fight is over!***\n" << endl;

	if (team1Lineup->head->fighter->get_strength() <= 0)  //if team 1 fighter is dead, team 2 fighter wins
	{
		cout << "\n=====Match Results=====" << endl;

		cout << "\nBattle # " << battle_count << ":" << endl;

		cout << "\nTeam 1: " << team1Lineup->head->fighter->get_name() << " (" << team1Lineup->head->fighter->get_type() << ") VS Team 2: " <<
			team2Lineup->head->fighter->get_name() << " (" << team2Lineup->head->fighter->get_type() << ")" << endl;

		cout << "\n***Team 2: " << team2Lineup->head->fighter->get_name() << " (" << team2Lineup->head->fighter->get_type() << ") has won the fight!***" << endl;
		team2Lineup->head->fighter->recovery();
		team2Points += 2;
		team1Points -= 1;
		team2Lineup->moveWinner();
		team1Lineup->moveLoser(losers);
	}

	else if (team2Lineup->head->fighter->get_strength() <= 0)  //if team 2 fighter is dead, team 1 fighter wins
	{
		cout << "\n=====Match Results=====" << endl;

		cout << "\nBattle # " << battle_count << ":" << endl;

		cout << "\nTeam 1: " << team1Lineup->head->fighter->get_name() << " (" << team1Lineup->head->fighter->get_type() << ") VS Team 2: " <<
			team2Lineup->head->fighter->get_name() << " (" << team2Lineup->head->fighter->get_type() << ")" << endl;

		cout << "\n***Team 1: " << team1Lineup->head->fighter->get_name() << " (" << team1Lineup->head->fighter->get_type() << ") has won the fight!***" << endl;
		team1Lineup->head->fighter->recovery(); //call recoery function for winner
		team1Points += 2; //add points to winner's team
		team2Points -= 1; //subtract points from loser's team
		team1Lineup->moveWinner(); //move winner to back of queue
		team2Lineup->moveLoser(losers); //move loser to losers queue
	}

	if (team1Lineup->isEmpty() || team2Lineup->isEmpty()) //if either lineup has no more fighters, the tournament is over
	{
		tournament_over = true;  //return true to end battle loop
		wrapUp();
	}

	battle_count++; //increment battle counter

	return tournament_over;

}

void Game::display_status1_pre()  //pre attack stats for player 1 as attacker
{
	cout << "\nAttacker: " << team1Lineup->head->fighter->get_name() << " (" << team1Lineup->head->fighter->get_type() << ", (Team 1)" << endl;
	cout << "Defender: " << team2Lineup->head->fighter->get_name() << " (" << team2Lineup->head->fighter->get_type() << ", Team 2)" << " Armor: " << team2Lineup->head->fighter->get_armor() << " HP: " << team2Lineup->head->fighter->get_strength() << endl;
}

void Game::display_status1_post()
{

	if (team2Lineup->head->fighter->get_damage_taken() == 0 && (team2Lineup->head->fighter->charm_check()))  //if charmed, let user know
	{
		cout << team1Lineup->head->fighter->get_name() << " (" << team1Lineup->head->fighter->get_type() << ") was charmed and didn't attack this turn!" << endl;
	}

	else  //print post attack stats if not charmed
	{
		cout << "Damage dealt by " << team1Lineup->head->fighter->get_name() << " (" << team1Lineup->head->fighter->get_type() << ") was: " << team1Lineup->head->fighter->get_attack_pts() << endl;
		cout << "Damage blocked by " << team2Lineup->head->fighter->get_name() << " (" << team2Lineup->head->fighter->get_type() << ") was: " << team2Lineup->head->fighter->get_defense_pts() << endl;
	}

	cout << team2Lineup->head->fighter->get_name() << "'s (" << team2Lineup->head->fighter->get_type() << ") HP is now: " << team2Lineup->head->fighter->get_strength() << endl;
}

void Game::display_status2_pre()  //pre attack stats for player 2 as attacker
{
	cout << "\nAttacker: " << team2Lineup->head->fighter->get_name() << " (" << team2Lineup->head->fighter->get_type() << ", Team 2)" << endl;
	cout << "Defender: " << team1Lineup->head->fighter->get_name() << " (" << team1Lineup->head->fighter->get_type() << ", Team 1)" << " Armor: " << team1Lineup->head->fighter->get_armor() << " HP: " << team1Lineup->head->fighter->get_strength() << endl;
}

void Game::display_status2_post()
{
	if ((team1Lineup->head->fighter->get_damage_taken() == 0) && (team1Lineup->head->fighter->charm_check()))  //if charmed let user know
	{
		cout << team2Lineup->head->fighter->get_name() << " (" << team2Lineup->head->fighter->get_type() << ") was charmed and didn't attack this turn!" << endl;
	}

	else  //print post attack stats if not charmed
	{
		cout << "Damage dealt by " << team2Lineup->head->fighter->get_name() << " (" << team2Lineup->head->fighter->get_type() << ") was: " << team2Lineup->head->fighter->get_attack_pts() << endl;
		cout << "Damage blocked by " << team1Lineup->head->fighter->get_name() << " (" << team1Lineup->head->fighter->get_type() << ") was: " << team1Lineup->head->fighter->get_defense_pts() << endl;
	}

	cout << team1Lineup->head->fighter->get_name() << "'s (" << team1Lineup->head->fighter->get_type()  << ") HP is now: " << team1Lineup->head->fighter->get_strength() << endl;
}

void Game::wrapUp()
{
	char userChoice;
	bool valid = false;
	
	cout << "\n=*=*=*=*=*=The Tournament is over!!!=*=*=*=*=*=" << endl;

	cout << "\n***Final Results***" << endl;

	cout << "\nTeam 1 Total: " << team1Points << " pts." << endl;

	cout << "\nTeam 2 Total: " << team2Points << " pts." << endl;

	if (team1Points > team2Points)
	{
		cout << "\nTeam 1 has won the Tournament!" << endl;
	}
	else if (team2Points > team1Points)
	{
		cout << "\nTeam 2 has won the Tournament!" << endl;
	}
	else if (team1Points == team2Points)
	{
		cout << "\nThe tournament ends in a tie!" << endl;
	}

	do
	{
		cout << "\nWould you like to see the ranking for the losers in the tournament? (Y/N): ";

		cin >> userChoice;

		userChoice = toupper(userChoice);

		cin.clear();
		cin.ignore(100, '\n');

		if (cin.fail())
		{
			cout << "\nInvalid option, please try again." << endl;
		}
		else if (userChoice == 'Y')
		{
			cout << "\n";
			losers->printQueue(); //print losers queue 
			valid = true;
		}
		else if (userChoice == 'N')
		{
			valid = true; //exit loop
		}

	} while (!valid);

}

Game::~Game() //delete allocated queue objects
{
	delete team1Lineup;
	delete team2Lineup;
	delete losers;
}


