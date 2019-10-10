/******************************************************************
 * * Name: Oliver Solorzano
 * * Course: CS 162 W 2019
 * * Assignment: Project 2 (Zoo Tycoon)
 * * Date: 03 Jan 2019
 * * Description: This is the implementation file for the turtle class.
 * * It contains a constructor that intializes the variables to unique
 * * values of the class.
 * *******************************************************************/

#include "turtle.hpp"

//initialize base constructor with variables specific to the turtle class 

Turtle::Turtle() : Animal{ 1, 100, 10, 5}
{
	base_food_cost *= 0.5;	 //modify food cost for turtle class(0.5x)
}

