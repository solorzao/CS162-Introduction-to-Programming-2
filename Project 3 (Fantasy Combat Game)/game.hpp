/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 3
* Date: 16 Feb 2019
* Description: This is the specification file for the game class.
* It defines functions for creating and modifying a combat game
* that uses character objects.
*******************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"

class Game 
{
private:

	Character* players[2];  //create array pointing to character objects

	int roll_die_turn();  //function to roll die and determine who goes first

public:

	void intro();					//function prototypes
	void character_selection();
	bool ask_to_play_again();
	void battle();
	void display_status1_pre();
	void display_status1_post();
	void display_status2_pre();
	void display_status2_post();

};


#endif
