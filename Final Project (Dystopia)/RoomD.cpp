/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Implementation file for the Room D class. It defines
* the functions for the class and the trial associated with the room.
*********************************************************************/
#include <limits>
#include "RoomD.hpp"

RoomD::RoomD()
{
	name = "Room D";  //set room name
}


Space* RoomD::getRight()  //get room pointers
{
	return right;
}

Space* RoomD::getLeft()
{
	return left;
}

Space* RoomD::getTop()
{
	return top;
}

Space* RoomD::getBottom()
{
	return bottom;
}

std::string RoomD::getName()
{
	return name;
}

void RoomD::setRight(Space *room)  //set room pointers
{
	right = room;
}

void RoomD::setLeft(Space *room)
{
	left = room;
}

void RoomD::setTop(Space *room)
{
	top = room;
}

void RoomD::setBottom(Space *room)
{
	bottom = room;
}

int RoomD::trial(Player* inmate)  //pass user through room trial
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
	std::cout << " |    |   | |  Exit  | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   | " << std::endl;
	std::cout << " |____|___|_|________|_|___|___|" << std::endl;

	std::cout << "\nFor your final test, swear your devotion to the Council." << std::endl;

	std::cout << "\nWho, and ONLY who, influences and dictates your decisions?" << std::endl;

	while (!done)
	{
		std::cout << "\nWhat would you like to do?\n" << std::endl;
		std::cout << "1. Answer the question" << std::endl;
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
				std::cout << "\nWho and only who, influences and dictates your decisions?" << std::endl;
				std::cout << "\nWhat is your answer?\n" << std::endl;
				std::cout << "1. Family." << std::endl;
				std::cout << "2. Friends." << std::endl;
				std::cout << "3. Myself." << std::endl;
				std::cout << "4. The Council, without question. " << std::endl;
				std::cout << "\nSelect an option and press [Enter] ";

				std::cin >> answer;

				if (std::cin.fail())
				{
					std::cout << "\n***Invalid entry, please try again***" << std::endl;
					std::cin.clear();  //clear flags
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //ignore input until next \n
				}
				else if (answer == 4)
				{
					std::cout << "\nCongratulations Human #531879605, you have answered correctly." << std::endl;
					inmate->addToInventory("Final Keycard");
					std::cout << "\n***Final Keycard has been added to your inventory***" << std::endl;
					doneInside = true;  //exit inner loop
					haveKeyCard = true;

				}
				else if (answer == 1 || answer == 2 || answer == 3)
				{
					std::cout << "\nIncorrect, your score will be penalized. " << std::endl;
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
			if (inmate->checkInventory("Final Keycard"))
			{
				std::cout << "\n***You have used your Final Keycard to open the door. You step through.***" << std::endl;
				outcome = 4;
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
	return outcome;  //return outcome to determine next step
}
