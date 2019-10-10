/******************************************************************
 * * Name: Oliver Solorzano
 * * Course: CS 162 W 2019
 * * Assignment: Project 2 (Zoo Tycoon)
 * * Date: 03 Jan 2019
 * * Description: This is the specification file for the animal class.
 * * It declares all the member variables and functions for the class.
 * *******************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal   //create parent class
{

public: //All member variables and functions are public and inheritable

	int age,	//declare variables for class 
		cost, 
		number_of_babies, 
		payoff;

	double base_food_cost = 250;	//declare and initialize food cost to base
	
	Animal(int, int, int, int);  //set constructor to take values for a ll variables except food cost

};

#endif
