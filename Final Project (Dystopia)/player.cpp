/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Implementation file for the player class. Defines
* functions related to user score and other parameters.
*********************************************************************/

#include "player.hpp"
#include "space.hpp"

#include <iostream>

Player::Player()
{
	score = 100;  //set initial score to 100
	itemCount = 0;  //set initial inventory count

	for (int i = 0; i < 6; i++)
	{
		inventory[i] = " ";  //set all inventory slots to empty
	}

	addToInventory("Room A Keycard");  //begin with Keycard A
}

int Player::getScore()
{
	return score;  //return score
}



void Player::setScore(int newScore)
{
	score = newScore;  //set new score
}



void Player::viewInventory()
{
	for (int i = 0; i < 6; i++)  
	{
		std::cout << (i+1) << ") " << inventory[i] << " ";  //print current inventory
	}
	std::cout << std::endl;
}

bool Player::checkInventory(std::string item)
{
	bool haveItem = false;

	for (int i = 0; i < 6; i++)
	{
		if (inventory[i] == item)  //search for passed value in inventory, return true if found
		{
			haveItem = true;
		}
	}

	return haveItem;
}

void Player::addToInventory(std::string item)
{
	inventory[itemCount] = item;  //add item to inventory
	itemCount++;
}
