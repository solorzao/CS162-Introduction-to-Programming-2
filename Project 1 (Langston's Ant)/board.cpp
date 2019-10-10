/***********************************************************************
 * Name: Oliver Solorzano
 * Course: CS 162 W 2019
 * Assignment: Project 1 (Langston's Ant)
 * Date: 23 Jan 2019
 * Description: This is the implementation file for the board class. It contains 
 * the functions related to board control. They include actions like board updates,
 * printing the board, deleting allocated memory for the board, and setting it at 
 * start (the size and borders).
 * ***********************************************************************/

#include "board.hpp"
#include <iostream>

using std::cout;
using std::endl;


void Board::createBoard(int rows, int columns)  //allocate memory for board based on user rows/columns
{
	
	simulationBoard = new char*[rows + 2];  

	for (int i = 0; i <= rows + 2; i++)
	{
		simulationBoard[i] = new char[columns + 2];
	}
	
	setBoard(rows, columns);  //set board after allocation
}

void Board::setBoard(int rows, int columns)
{
	for (int i = 0; i < rows + 2; i++)
	{
		for (int j = 0; j < columns + 2; j++)
		{
			simulationBoard[i][j] = {' '};  //set ant spaces to blank
		}
	}

	for (int i = 0; i <= 0; i++)
	{
		for (int j = 0; j <= columns + 1; j++)
		{
			simulationBoard[i][j] = { '-' };  //set top border
		}
	}
	
	for (int i = 0; i <= rows + 1; i++)
	{
		for (int j = 0; j <= 0; j++)
		{
			simulationBoard[i][j] = { '|' };  //set side border
		}
	}

	for (int i = rows + 1; i <= rows + 1; i++)
	{
		for (int j = 1; j <= columns + 1; j++)
		{
			simulationBoard[i][j] = { '-' };
		}
	}

	for (int i = 0; i <= rows + 1; i++)
	{
		for (int j = columns + 1; j <= columns + 1; j++)
		{
			simulationBoard[i][j] = { '|' };
		}
	}
}

void Board::updateBoardAnt(int row, int col)
{
	simulationBoard[row][col] = '*';  //update ant position on board
}

void Board::updatePreviousSpace(char space, int row, int col)
{
	simulationBoard[row][col] = space;  //update space ant was previously on
}

void Board::printBoard(int rows, int columns)
{
	for (int i = 0; i <= rows + 1; i++)
	{
		for (int j = 0; j <= columns + 1; j++)
		{
			cout << simulationBoard[i][j] << " ";  //print board to user
		}
		cout << endl;
	}
}

void Board::deleteBoard(int columns)
{
	for (int i = 0; i <= columns + 2; i++)
	{
		delete[] simulationBoard[i];  //delete first dimension of board, take columns to delete appropriate amount
	}	

	delete[] simulationBoard;  //delete 2nd dimension of board
}

