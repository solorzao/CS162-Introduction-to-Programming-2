/*******************************************************************
 * Name: Oliver Solorzano
 * Course: CS 162 W 2019
 * Assignment: Project 1 (Langston's Ant)
 * Date: 23 Jan 2019
 * Description: This is the specification file for the board class. 
 * It contains the function prototypes and associated variables for
 * the class. It contains functions that manipulate the board ot keep track
 * of the ant movement and print the results to the user.
 * *********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
private:

public:

	char** simulationBoard = nullptr;  //declare variables, set array to null
	
	void createBoard(int, int);  //function prototypes
	void setBoard(int, int);
	void updateBoardAnt(int, int);
	void updatePreviousSpace(char, int, int);
	void printBoard(int, int);
	void deleteBoard(int);

};

#endif

