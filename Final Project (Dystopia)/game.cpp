/*******************************************************************
* Name: Oliver Solorzano
* Date: 19 Mar 2019
* Class: CS 162 W 2019
* Assignment: Final Project
* Description: Implementation file for the final room class. It defines
* the functions for the class and controls game progression.
*********************************************************************/

#include "game.hpp"
#include "space.hpp"
#include "player.hpp"
#include "startRoom.hpp"
#include "RoomA.hpp"
#include "RoomB.hpp"
#include "RoomC.hpp"
#include "RoomD.hpp"
#include "finalRoom.hpp"

#include <iostream>

Game::Game()  //allocate memory for map, link rooms
{
	inmate = new Player;
	currentRoom = temp1 = new startRoom;
	temp2 = new RoomA;
	temp1->setRight(temp2);
	temp2->setLeft(temp1);
	temp1 = temp2;
	temp2 = new RoomB;
	temp1->setRight(temp2);
	temp2->setLeft(temp1);
	temp1 = temp2;
	temp2 = new RoomC;
	temp1->setRight(temp2);
	temp2->setLeft(temp1);
	temp1 = temp2;
	temp2 = new RoomD;
	temp1->setRight(temp2);
	temp2->setLeft(temp1);
	temp1 = temp2;
	temp2 = new FinalRoom;
	temp2->setLeft(temp1);

}

void Game::updateCurrentRoom(Space *room)  //move to next room
{
	currentRoom = room->getRight();
}

void Game::intro()  //print intro to user
{
	std::cout << "\n***You awake in a brightly lit plain room with a single door. Your head is pounding and you can't remember how you got here.***\n" << std::endl;
	
	
	std::cout << " -------------------------------" << std::endl;
	std::cout << " |\\              _            /| " << std::endl;
	std::cout << " | \\            (O)          / | " << std::endl;
	std::cout << " |  \\                       /  | " << std::endl;
	std::cout << " |   \\                     /   | " << std::endl;
	std::cout << " |    ---------------------    |" << std::endl;
	std::cout << " |    |                    |   |" << std::endl;
	std::cout << " |    |      CELL #353     |   |" << std::endl;
	std::cout << " |    |                    |   |" << std::endl;
	std::cout << " |    |        (100)       |   |" << std::endl;
	std::cout << " |    |    ____________    |   |" << std::endl;
	std::cout << " |    |   |  ________  |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | | Room A | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   |" << std::endl;
	std::cout << " |    |   | |        | |   |   | "  << std::endl;
	std::cout << " |____|___|_|________|_|___|___|" << std::endl;
	

	std::cout << "\n***Suddenly, you hear a robotic voice over an intercom***\n" << std::endl;
	std::cout << " Welcome to Correctional Facility 3xBT0!\n" << std::endl;
	std::cout << " Don't be alarmed Human #531879605, you have been given another chance. Civilization only works with order, \n"
		<< " and you have broken that order. You are in a specialized training facility designed to \n"
		<< " rewire your behavior to meet the Intergalactic Conformity standards. \n" << std::endl;

	std::cout << " Pay close attention to the number on the wall. That is the score for your training. You will start \n at 100 pts. "
		<< "For each failed task your score will become decremented. If it reaches 0, you will fail.\n Each completed task will yield an access card for the next room. \n" << std::endl;
	std::cout << " The Intergalactic Council is merciful and you will be allowed to repeat the training infinitely until \n your behavior conforms to their expectations. If you should decide that conformity is not appealing to\n"
		<< " you, you may say so anytime, and the exile proceedings will begin. \n" << std::endl;
	std::cout << " You will not need to worry about aging and time passing in the outside world. You have been placed in \n a time loop that will reset every time you fail. " << std::endl;

	std::cout << "\n You may begin. \n" << std::endl;
}

bool Game::playGame()  //begin gameplay
{
	int outcome;
	bool keepPlaying = true;
	bool playAgain = false;

	while (((inmate->getScore()) > 0) && (keepPlaying))  //if score isn't zero and user doesn't quit, keep playing
	{
		std::cout << "\nYou are currently in " << currentRoom->getName() << ". \n"<< std::endl;  //print current room
		if (currentRoom->getLeft() != nullptr)
		{
			temp = currentRoom->getLeft();
			std::cout << temp->getName() << " is behind you.\n" << std::endl;  //print room to left

		}
		if (currentRoom->getRight() != nullptr)
		{
			temp = currentRoom->getRight();
			std::cout << temp->getName() << " is in front of you.\n" << std::endl;  //print room to right
		}
		
		outcome = currentRoom->trial(inmate);

		if (outcome == 1)
		{
			currentRoom = currentRoom->getRight(); //if passed test, move to next room
		}
		else if (outcome == 2)
		{
			inmate->setScore((inmate->getScore() - 25));  //if failed, deduct from score
		}
		else if (outcome == 3)  //if wants to quit, exit game
		{
			keepPlaying = exitMessage();
			playAgain = false;
		}
		else if (outcome == 4)  //if won, begin end sequence
		{
			currentRoom = temp2;
			currentRoom->trial(inmate);
			keepPlaying = winMessage();
			playAgain = false;
		}
		
	}

	if ((inmate->getScore()) <= 0)  //if lost, reset game
	{
	loseMessage();
	playAgain = true;
	}

	return playAgain;  //return to main to determine if playing again
}

bool Game::winMessage()  //print winning message
{
	std::cout << "\nCongratulations on your successful reassimilation Human #531879605. You will now be moved for transport. See you again soon." << std::endl;
	return false;
}

void Game::loseMessage()  //print losing message
{
	std::cout << "\nYour score has reached 0. " << std::endl;
	std::cout << "\nReassimilation failed. Resetting time loop. " << std::endl;
}

bool Game::exitMessage()  //print exit message
{
	std::cout << "\nAs you wish Human #531879605, your free will is an unneccesary burden. The exile process will now begin. Goodbye" << std::endl;
	return false;
}

Game::~Game()  //destructor to delete allocated memory
{
	temp1 = temp2->getLeft();  //step through backwards, delete one by one
	delete temp2;
	temp2 = temp1->getLeft();
	delete temp1;
	temp1 = temp2->getLeft();
	delete temp2;
	temp2 = temp1->getLeft();
	delete temp1;
	temp1 = temp2->getLeft();
	delete temp2;
	temp2 = temp1->getLeft();
	delete temp1;
	delete inmate;
}

