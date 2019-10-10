/****************************************************************************
 * Name: Oliver Solozano
 * Course: CS 162
 * Assignment: Project 1 (Langston's Ant)
 * Date: 23 Jan 2019
 * Description: This is the main file for a program that simulates Langston's Ant.
 * It asks the user for certain parameters such as rows, columns, number of turns,
 * and the starting position of the ant.
 * ****************************************************************************/

#include "board.hpp"
#include "ant.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;

std::string menu();   //function prototypes for choice menus
bool runAgain();

int main()
{
	std::string initialChoice;
	initialChoice = menu();	  //starts program by asking user if they would like to run the sim


	if (initialChoice == "1")   //if user chooses to run program, ask for parameters
	{
		int rows, columns, antLocationRow, antLocationColumn, steps;
		Board SimBoard1;
		Ant SimAnt1;
		
		do
		{
			while (true)
			{
				cout << "\nPlease enter the number of rows for the Board. (Min: 1, Max 100)" << endl;
				cin >> rows;

				cin.clear();
				cin.ignore(1000, '\n');

				if ((rows <= 100) && (rows >= 1))  //validate input, kick back and clear if not valid
				{
					break;
				}
				else
				{
					cout << "\nInvalid entry. Please try again.";  //ask user to enter valid value
				}

			}

			while (true)
			{
				cout << "\nPlease enter the number of columns for the Board. (Min: 1, Max 100)" << endl;
				cin >> columns;

				cin.clear();
				cin.ignore(1000, '\n');

				if ((columns <= 100) && (columns >= 1))   //validate input
				{
					break;
				}
				else
				{
					cout << "\nInvalid entry. Please try again.";  //ask user to enter again if invalid
				}

			}

			while (true)
			{
				cout << "\nPlease enter the number of steps for the simulation. (Min: 1, Max 1000)" << endl;
				cin >> steps;

				cin.clear();
				cin.ignore(1000, '\n');

				if ((steps <= 1000) && (steps >= 1))   //validate input
				{
					break;
				}
				else
				{
					cout << "\nInvalid entry. Please try again."; //if invalid, ask again
				}

			}

			while (true)
			{
				cout << "\nPlease enter the row where you would like the ant to start. Max: " << rows << endl;
				cin >> antLocationRow;

				cin.clear();
				cin.ignore(1000, '\n');

				if ((antLocationRow <= rows) && (antLocationRow >= 1))  //validate input
				{
					break;
				}
				else
				{
					cout << "\nInvalid entry. Please try again.";  //if invalid ask again
				}

			}

			while (true)
			{
				cout << "\nPlease enter the column where you would like the ant to start. Max: " << columns << endl;
				cin >> antLocationColumn;

				cin.clear();
				cin.ignore(1000, '\n');

				if ((antLocationColumn <= columns) && (antLocationColumn >= 1))  //validate input
				{
					break;
				}
				else
				{
					cout << "\nInvalid entry. Please try again.";  //if invalid, ask again
				}

			}

			SimBoard1.createBoard(rows, columns);  //create ant board with user selected rows, columns
			SimAnt1.createAntLocation(rows, columns);  //create variables to store ant location
			SimAnt1.setAntLocation(SimBoard1.simulationBoard, antLocationRow, antLocationColumn);  //set start position for ant 
			SimBoard1.updateBoardAnt(SimAnt1.locationRow, SimAnt1.locationColumn);  //update ant location to variables
			SimBoard1.printBoard(rows, columns);  //print starting board to user
			SimAnt1.setPreviousLocation(antLocationRow, antLocationColumn);  //store previous location, to change back once ant moves

			for (int i = 0; i < steps; i++)  //keep moving ant until steps chosen by user is reached
			{
				SimAnt1.antMove(SimBoard1.simulationBoard);  //move ant
				
				SimBoard1.updatePreviousSpace(SimAnt1.currentSpace, SimAnt1.previousRow, SimAnt1.previousCol);  //update previous location to correct character
				SimBoard1.updateBoardAnt(SimAnt1.locationRow, SimAnt1.locationColumn);  //update current location
				SimAnt1.setPreviousLocation(SimAnt1.locationRow, SimAnt1.locationColumn);  //update previous location

				SimBoard1.printBoard(rows, columns);  //print board to user
			}
			
			SimBoard1.deleteBoard(columns);  //delete allocated array, takes columns to delete appropriate amount requested by user
		
		} while (runAgain());  //run again if user selects true option, else quit
		
		
	}
	
	return 0;
}

string menu()
{
	cout << "Hello, welcome to a simulation program for Langston's Ant." << endl;

	cout << "\nWhat would you like to do? Please choose option (1) or (2)." << endl;

	std::string choice;

	do
	{
		cout << "\n1. Start Langston's Ant simulation" << endl;
		cout << "2. Quit" << endl;

		getline(cin, choice);
						//ask user if they want to run program or quit

		if (choice == "1")  
		{
			cout << "\nYou chose to run the simulation." << endl;
			break;
		}
		
		else if (choice == "2") 
		{
			cout << "\nThe program will now quit, goodbye." << endl;
			break;
		}

		else		//if input is invalid, try again
		{
			cout << "Invalid entry. Please try again" << endl;
		
		}
	} while (true);
	
	return choice;  //return choice to dictate whether program will run or not

	
}

bool runAgain()
{
	std::string runAgain;
	bool runChoice = true;

	while (true)
	{
		cout << "Would you like to run the simulation again? Please enter 'y' or 'n'." << endl;

		getline(cin, runAgain);


		if (runAgain == "Y" || runAgain == "y")  //ask user if they want to run again
		{
			cout << "You chose to run again." << endl;
			runChoice = true;
			break;
		}
		else if (runAgain == "N" || runAgain == "n")
		{
			cout << "The simulation will now end. Goodbye." << endl;
			runChoice = false;
			break;
		}
		else  //if invalid input, ask again
		{
			cout << "\nInvalid entry. Please try again.";
		}

	}

	return runChoice;  //return bool based on choice

}
