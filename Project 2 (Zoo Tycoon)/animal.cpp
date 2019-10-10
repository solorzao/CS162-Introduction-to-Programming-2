/******************************************************************
 * * Name: Oliver Solorzano
 * * Course: CS 162 W 2019
 * * Assignment: Project 2 (Zoo Tycoon)
 * * Date: 03 Jan 2019
 * * Description: This is the implementation file for the animal class.
 * * It contains a constructor that initializes specific variables for
 * * the class.
 * *******************************************************************/

#include "animal.hpp"

Animal::Animal(int a, int c, int b, int po)  //constructor that takes values for age, cost, babies, and payoff
{
	age = a;
	cost = c; 
	number_of_babies = b;
	payoff = po;
}

