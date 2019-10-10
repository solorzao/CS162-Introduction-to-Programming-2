/*************************************************************************
 * Name: Oliver Solorzano
 * Course: CS 162 W 2019
 * Assignment: Project 1
 * Date: 23 Jan 2019
 * Description: This is the implementation file for the ant class. It contains 
 * the functions that control ant movement. The ant should move forward one space
 * with each step; if the space it lands on is blank, it will turn right, if the 
 * space is black it will turn left. It then updates the space is landed on to the 
 * opposite character.
 *************************************************************************/

#include "ant.hpp"
#include <iostream>

using std::cout;
using std::endl;

void Ant::createAntLocation(int rows, int columns)  //create variables to store ant location
{
	locationRow = (rows - 1);
	locationColumn = (columns - 1);
}


void Ant::setPreviousLocation(int row, int col)  //create variables to store previous ant location
{
	previousRow = row;
	previousCol = col;
}


void Ant::setAntLocation(char** array, int row, int column)  //set starting ant location
{

	array[row][column] = { '*' };  //display ant on board as '*'

	locationRow = row;
	locationColumn = column;

	currentOrientation = NORTH;  //set default orientation to north

}

void Ant::antMove(char** array)  //function that dictates ant movement, based on orientation and current space character
{

	if (currentOrientation == NORTH)  //if ant is facing north
	{
		if (array[locationRow - 1][locationColumn] == ' ')  //if space is blank, turn right, change space to black
		{
			currentOrientation = EAST;  //change orientation to east

			currentSpace = '#';  //store current space

			locationRow--;  //decrement location, ant moves up by one space
		}
		else if (array[locationRow - 1][locationColumn] == '#')
		{
			currentOrientation = WEST;
			
			currentSpace = ' ';

			locationRow--;
		}

		else if (array[locationRow - 1][locationColumn] == '-')
		{
			currentOrientation = SOUTH;  //if ant hits border, change orientation, don't move
		}


	}

	else if (currentOrientation == SOUTH)
	{
		if (array[locationRow + 1][locationColumn] == ' ') 
		{
			currentOrientation = WEST;

			currentSpace = '#';

			locationRow++;
		}

		else if (array[locationRow + 1][locationColumn] == '#')
		{
			currentOrientation = EAST;

			currentSpace = ' ';

			locationRow++;
		}

		else if (array[locationRow + 1][locationColumn] == '-')
		{
			currentOrientation = NORTH;
		}
	}

	else if (currentOrientation == EAST)
	{
		if (array[locationRow][locationColumn + 1] == ' ')
		{
			currentOrientation = SOUTH;

			currentSpace = '#';

			locationColumn++;
		}

		else if (array[locationRow][locationColumn + 1] == '#')
		{
			currentOrientation = NORTH;

			currentSpace = ' ';

			locationColumn++;
		}

		else if (array[locationRow][locationColumn + 1] == '|')
		{
			currentOrientation = WEST;
		}

	}

	else if (currentOrientation == WEST)
	{
		if (array[locationRow][locationColumn - 1] == ' ')
		{
			currentOrientation = NORTH;

			currentSpace = '#';

			locationColumn--;
		}

		else if (array[locationRow][locationColumn - 1] == '#')
		{
			currentOrientation = SOUTH;

			currentSpace = ' ';

			locationColumn--;
		}

		else if (array[locationRow][locationColumn - 1] == '|')
		{
			currentOrientation = EAST;
		}
	}

}




