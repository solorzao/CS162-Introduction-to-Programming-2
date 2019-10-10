/*****************************************************************************
 * Name: Oliver Solorzano
 * Course: CS 162
 * Assignment: Project 1 (Langston's Ant)
 * Date: 23 Jan 2019
 * Description: This is the specification file for the ant class. It contains the 
 * function prototypes and variables associated with ant movement on the board.
 * ****************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

enum ORIENTATION {NORTH, SOUTH, EAST, WEST};  //create enum to store ant orientation

class Ant
{
private:

	ORIENTATION currentOrientation;  //declare enum variable

public:
	
	int locationRow = 0, locationColumn = 0, previousRow = 0, previousCol = 0;

	char currentSpace = ' ';  //declare variables, set values
	
	void createAntLocation(int, int);  //function prototypes
	void setPreviousLocation(int, int);
	void setAntLocation(char** array, int, int);
	void antMove(char** array);
	
};

#endif

