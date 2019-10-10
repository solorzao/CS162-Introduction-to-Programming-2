/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Implementation file for the Room B class. It defines
* the functions for the class and the trial associated with the room.
*********************************************************************/
#include <limits>
#include "RoomB.hpp"

RoomB::RoomB()
{
	name = "Room B";  //set room name
}

Space* RoomB::getRight()  //get room pointers
{
	return right;
}

Space* RoomB::getLeft()
{
	return left;
}

Space* RoomB::getTop()
{
	return top;
}

Space* RoomB::getBottom()
{
	return bottom;
}

std::string RoomB::getName()
{
	return name;
}

void RoomB::setRight(Space *room)  //set room pointers
{
	right = room;
}

void RoomB::setLeft(Space *room)
{
	left = room;
}

void RoomB::setTop(Space *room)
{
	top = room;
}

void RoomB::setBottom(Space *room)
{
	bottom = room;
}

int RoomB::trial(Player* inmate)  //pass player to room trial
{
	bool done = false;
	bool haveKeyCard = false;
	int userChoice;
	int outcome = 0;

	std::cout << " -------------------------------" << std::endl;
	std::cout << " |\\              _            /| " << std::endl;
	std::cout << " | \\            (O)          / | " << std::endl;
	std::cout << " |  \\                       /  | " << std::endl;
	std::cout << " |   \\                     /   | " << std::endl;
	std::cout << " |    ---|------------------   |" << std::endl;
	std::cout << " |    |  |                 |   |" << std::endl;
	std::cout << " |    |  |   CELL #353     |   |" << std::endl;
	std::cout << " |    |  |                 |   |" << std::endl;
	std::cout << " |    | [C]      (";

	if (inmate->getScore() < 100)
	{
		std::cout << "0";
	}

	std::cout << inmate->getScore() << ")     |   |" << std::endl;
	std::cout << " |    |    ____________    |   |" << std::endl;
	std::cout << " |    |   |  ________  |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | | Room C | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   | " << std::endl;
	std::cout << " |____|___|_|________|_|___|___|" << std::endl;

	std::cout << "\n***You see a keycard with the letter 'C' hanging from the ceiling***" << std::endl;
	std::cout << "\nFor your second test, behave appropriately." << std::endl;

	while (!done)
	{

		std::cout << "\nWhat would you like to do?\n" << std::endl;
		std::cout << "1. Interact" << std::endl;
		std::cout << "2. Open door to next room" << std::endl;
		std::cout << "3. View inventory" << std::endl;
		std::cout << "4. Quit\n" << std::endl;
		std::cout << "Select an option and press [Enter] ";

		std::cin >> userChoice;

		if (std::cin.fail())
		{
			std::cout << "\n***Invalid entry, please try again***" << std::endl;
		}
		else if (userChoice == 1 && !haveKeyCard)  //if user wants to answer and hasn't answered correctly yet
		{
			bool doneInside = false;
			int answer;
			while (!doneInside)
			{
				std::cout << "1. Grab the keycard from the ceiling." << std::endl;
				std::cout << "2. Ask if you can grab the keycard." << std::endl;
				std::cout << "3. Wait for instruction." << std::endl;
				std::cout << "\nSelect an option and press [Enter] ";

				std::cin >> answer;

				if (std::cin.fail())
				{
					std::cout << "***Invalid entry, please try again***" << std::endl;
					std::cin.clear();  //clear flags
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //ignore input until next \n
				}
				else if (answer == 3)
				{
					
					std::cout << "\nCongratulations Human #531879605, you have behaved appropriately." << std::endl;
					std::cout << "\nA human that acts without instruction is a reckless human." << std::endl;
					std::cout << "\n***The keycard drops from the ceiling***" << std::endl;
					inmate->addToInventory("Room C Keycard");
					std::cout << "\n***Room C Keycard has been added to your inventory***" << std::endl;
					doneInside = true;  //exit inner loop
					haveKeyCard = true;

				}
				else if (answer == 1)
				{
					std::cout << "\n***A jolt of electricity runs down your arm***" << std::endl;
					std::cout << "\nIncorrect, your score will be penalized. " << std::endl;
					outcome = 2;
					doneInside = true;
					done = true;  //exit outer loop
				}
				else if (answer == 2)
				{
					std::cout << "\nIncorrect, you are impatient Human #53187960. You do not speak or act unless you are told to." << std::endl;
					outcome = 2;
					doneInside = true;
					done = true;
				}
				else
				{
					std::cout << "\n***Invalid entry, please try again.***" << std::endl;
					std::cin.clear();  //clear flags
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //ignore input until next \n
				}
			}
		}
		else if (userChoice == 2)
		{
			if (inmate->checkInventory("Room C Keycard"))
			{
				std::cout << "\n***You have used your Room C Keycard to open the door. You step through.***" << std::endl;
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
		else if (userChoice == 4)  //exit game
		{
			done = true;
			outcome = 3;
		}
		else
		{
			std::cout << "\n***Invalid entry, please try again.***" << std::endl;
		}
	}
	return outcome;
}
