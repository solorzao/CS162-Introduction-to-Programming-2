/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Implementation file for the start room class. It defines
* the functions for the class and the trial associated with the room.
*********************************************************************/

#include "startRoom.hpp"
#include "space.hpp"
#include "player.hpp"
#include <limits>
#include <iostream>

startRoom::startRoom()
{
	name = "Starting Room";  //set name
}

Space* startRoom::getRight()
{
	return right;  //return room pointer to right
}

Space* startRoom::getLeft() 
{
	return left;  //return room pointer to left
}

Space* startRoom::getTop()
{
	return top;  //return room pointer to top
}

Space* startRoom::getBottom() 
{
	return bottom;  //return room pointer to bottom
}

std::string startRoom::getName() 
{
	return name;  //return name of room
}

void startRoom::setRight(Space *room)
{
	right = room;  //set right pointer
}

void startRoom::setLeft(Space *room)
{
	left = room;  //set left pointer
}

void startRoom::setTop(Space *room)
{
	top = room;  //set top pointer
}

void startRoom::setBottom(Space *room)
{
	bottom = room;  //set bottom pointer
}

int startRoom::trial(Player* inmate)  //pass player through room trial
{
	bool done = false;
	int userChoice;
	int outcome;

	while (!done)
	{
		std::cout << "\nWhat would you like to do?\n" << std::endl;
		std::cout << "1. Stay here" << std::endl;
		std::cout << "2. Open door to next room" << std::endl;
		std::cout << "3. View inventory" << std::endl;
		std::cout << "4. Quit\n" << std::endl;
		std::cout << "Select an option and press [Enter] ";

		std::cin >> userChoice;

		if (std::cin.fail())
		{
			std::cout << "\n***Invalid entry, please try again***" << std::endl;
			std::cin.clear();  //clear flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //ignore input until next \n
		}
		else if (userChoice == 1)
		{
			std::cout << "\nWhat are you waiting for Human #531879605? You may proceed." << std::endl;
		}
		else if (userChoice == 2)
		{
			if (inmate->checkInventory("Room A Keycard"))
			{
				std::cout << "\n***You have used your Room A Keycard to open the door. You step through.***" << std::endl;
				outcome = 1;
				done = true;
			}
			else 
			{
				std::cout << "\n***You don't have the key to that room yet***" << std::endl;
			}
		}
		else if (userChoice == 3)
		{
			inmate->viewInventory();  //view inventory
		}
		else if (userChoice == 4)  //user wants to quit
		{
			done = true;
			outcome = 3;  //exit, end game
		}
		else
		{
			std::cout << "\n***Invalid entry, please try again.***" << std::endl;
			std::cin.clear();  //clear flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //ignore input until next \n
		}
	}
	return outcome;  //return outcome to game to determine next step
}
