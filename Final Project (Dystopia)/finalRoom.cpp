/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Implementation file for the final room class. It defines
* the functions for the class and the trial associated with the room.
*********************************************************************/
#include <limits>
#include "finalRoom.hpp"

FinalRoom::FinalRoom()
{
	name = "Final Room";  //set name for room
}


Space* FinalRoom::getRight()  //get room pointers
{
	return right;
}

Space* FinalRoom::getLeft()
{
	return left;
}

Space* FinalRoom::getTop()
{
	return top;
}

Space* FinalRoom::getBottom()
{
	return bottom;
}

std::string FinalRoom::getName()
{
	return name;
}

void FinalRoom::setRight(Space *room)  //set room pointers
{
	right = room;
}

void FinalRoom::setLeft(Space *room)
{
	left = room;
}

void FinalRoom::setTop(Space *room)
{
	top = room;
}

void FinalRoom::setBottom(Space *room)
{
	bottom = room;
}

int FinalRoom::trial(Player* inmate)  //pass user through room trial
{
	bool done = false;
	int userChoice;

	while (!done)
	{
		std::cout << "\nWhat would you like to do?\n" << std::endl;
		std::cout << "1. Stay here" << std::endl;
		std::cout << "2. Get on platform and leave" << std::endl;
		std::cout << "3. View inventory" << std::endl;
		std::cout << "\nSelect an option and press [Enter]" << std::endl;

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
			std::cout << "\n***The platform begins moving up and lights start flashing***" << std::endl;
			done = true;  //exit loop
		}
		else if (userChoice == 3)
		{
			inmate->viewInventory();
		}
		else
		{
			std::cout << "\n***Invalid entry, please try again.***" << std::endl;
			std::cin.clear();  //clear flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //ignore input until next \n
		}
	}
	return 0;
}
