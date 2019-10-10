/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 4
* Date: 03 Mar 2019
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
#include "queue.hpp"
#include "queueNode.hpp"

class Game
{
private:

	Queue *team1Lineup, *team2Lineup, *losers;  //create array pointing to queue objects

	int team1Points = 0, team2Points = 0, battle_count = 1;

	int roll_die_turn();  //function to roll die and determine who goes first

public:

	Game();

	void intro();					//function prototypes
	void character_selection();
	bool ask_to_play();
	bool ask_to_play_again();
	bool battle();
	void display_status1_pre();
	void display_status1_post();
	void display_status2_pre();
	void display_status2_post();
	void wrapUp();

	~Game();
};

#endif 
