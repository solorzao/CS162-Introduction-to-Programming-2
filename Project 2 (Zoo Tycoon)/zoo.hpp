/******************************************************************
 * * Name: Oliver Solorzano
 * * Course: CS 162 W 2019
 * * Assignment: Project 2 (Zoo Tycoon)
 * * Date: 03 Jan 2019
 * * Description: This is the specification file for the zoo class. It
 * * declares all the member variables and functions for the class.
 * *******************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "animal.hpp"  //include animal header file
#include "tiger.hpp"  //include tiger header file
#include "penguin.hpp"  //include penguin header file
#include "turtle.hpp"  //include turtle header file

//enums are used to determine events and animals chosen
enum EVENT {SICK = 1, BOOM = 2, BIRTH = 3, NONE = 4};  //create enum variables for event
enum ZOO_ANIMAL {TIGER = 1, PENGUIN = 2, TURTLE = 3};  //create enum variables for animals

class Zoo
{

private:

	//create double variables for finances
	double long bank_account{ 100000 }, daily_cost{ 0 }, daily_profit{ 0 };
	EVENT current_event;  //declare variable for random event
	ZOO_ANIMAL rand_animal;  //declare variable for random animal
	
	int tiger_capacity{ 10 },  //declare and intialize variables, capacity starts at 10 for each animal
		tiger_number{ 0 },  //animal population starts at 0
		penguin_capacity{ 10 },
		penguin_number{ 0 },
		turtle_capacity{ 10 },
		turtle_number{ 0 },
		day_count{ 1 },  //starts at day 1
		zoo_day_count{ 1 };  
	
	Tiger **tigers = new Tiger*[10];  //create pointers to pointers pointing to animal objects
	Penguin **penguins = new Penguin*[10];
	Turtle **turtles = new Turtle*[10];

	void increase_capacity(Tiger** &array);  //declare functions for increasing array size, takes reference
	void increase_capacity(Penguin** &array);
	void increase_capacity(Turtle** &array);

	void add_tiger();  //declare function for adding animals
	void add_penguin();
	void add_turtle();
	
	void feed_animals();  //declare functions for feeding animal cost and profit calculation
	void calculate_profit();
	
	void random_event();  //declare function for creating a random event
	void sick_animal();  //declare function for choosing sick animal
	void animal_birth();  //declare function for choosing animal birth

public:

	void set_up_game();  //create function for setting up game variables
	bool zoo_day();  //create function that performs all actions for the day

	~Zoo();  //destructor that deletes dynamically allocated arrays of objects
};

#endif
