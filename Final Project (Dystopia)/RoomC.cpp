/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Implementation file for the Room C class. It defines
* the functions for the class and the trial associated with the room.
*********************************************************************/
#include <limits>
#include "RoomC.hpp"

RoomC::RoomC()
{
	name = "Room C";  //set room name
}


Space* RoomC::getRight()  //get room pointers
{
	return right;
}

Space* RoomC::getLeft()
{
	return left;
}

Space* RoomC::getTop()
{
	return top;
}

Space* RoomC::getBottom()
{
	return bottom;
}

std::string RoomC::getName()
{
	return name;
}

void RoomC::setRight(Space *room)  //set room pointers
{
	right = room;
}

void RoomC::setLeft(Space *room)
{
	left = room;
}

void RoomC::setTop(Space *room)
{
	top = room;
}

void RoomC::setBottom(Space *room)
{
	bottom = room;
}

int RoomC::trial(Player* inmate)  //pass user through room trial
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
	std::cout << " |    ---------------------    |" << std::endl;
	std::cout << " |    |                    |   |" << std::endl;
	std::cout << " |    |      CELL #353     |   |" << std::endl;
	std::cout << " |    |                    |   |" << std::endl;
	std::cout << " |    |        (";

	if (inmate->getScore() < 100)
	{
		std::cout << "0";
	}

	std::cout << inmate->getScore() << ")       |   |" << std::endl;
	std::cout << " |    |    ____________    |   |" << std::endl;
	std::cout << " |    |   |  ________  |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | | Room D | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |____|_  | |        | |   |   |" << std::endl;
	std::cout << " |/O\\   | | |        | |   |   |" << std::endl;
	std::cout << " |-|-   | | |        | |   |___| " << std::endl;
	std::cout << " |_/\\___|_|_|________|_|___|[D]|" << std::endl;

	std::cout << "\n***You see a small child trapped inside a cage on the left, and a keycard in a box on the right.***" << std::endl;
	std::cout << "\nAttention Human #531879605, you will be allowed to open one box. The other will remain locked indefinitely." << std::endl;
	std::cout << "\nFor your third test, make the appropriate decision. You may begin." << std::endl;

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
		else if (userChoice == 1 && !haveKeyCard)  //if user wants to interact and hasn't been correct yet
		{
			bool doneInside = false;
			int answer;
			while (!doneInside)
			{
				std::cout << "1. Release the small child." << std::endl;
				std::cout << "2. Release the keycard." << std::endl;
				std::cout << "\nSelect an option and press [Enter] ";

				std::cin >> answer;

				if (std::cin.fail())
				{
					std::cout << "\n***Invalid entry, please try again***" << std::endl;
					std::cin.clear();  //clear flags
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //ignore input until next \n
				}
				else if (answer == 2)
				{

					std::cout << "\nCongratulations Human #531879605, you have made the right decision." << std::endl;
					std::cout << "\nA human that allows emotion to direct their decision-making is unpredictable." << std::endl;
					inmate->addToInventory("Room D Keycard");
					std::cout << "\n***Room D Keycard has been added to your inventory***" << std::endl;
					doneInside = true;  //exit inner loop
					haveKeyCard = true;

				}
				else if (answer == 1)
				{
					std::cout << "\n***The cage doesn't open***" << std::endl;
					std::cout << "\nIncorrect, you have allowed emotion to cloud your decision-making. Your score will be penalized. " << std::endl;
					outcome = 2;
					doneInside = true;
					done = true;  //exit outer loop
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
			if (inmate->checkInventory("Room D Keycard"))
			{
				std::cout << "\n***You have used your Room D Keycard to open the door. You step through.***" << std::endl;
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
	return outcome;  //return outcome to decide next step
		
}
