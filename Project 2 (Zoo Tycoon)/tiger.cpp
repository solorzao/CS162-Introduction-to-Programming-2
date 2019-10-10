/******************************************************************
 * * Name: Oliver Solorzano
 * * Course: CS 162 W 2019
 * * Assignment: Project 2 (Zoo Tycoon)
 * * Date: 03 Jan 2019
 * * Description: This is the implementation file for the tiger class.
 * * It contains a constructor that intializes the variables to unique
 * * values of the class.
 * *******************************************************************/

#include "tiger.hpp"

//initialize base constructor with variables specific to the tiger class 

Tiger::Tiger() : Animal{1, 10000, 1, 2000} 
{
	base_food_cost *= 5;  //modify food cost for tiger class(5x)
}


