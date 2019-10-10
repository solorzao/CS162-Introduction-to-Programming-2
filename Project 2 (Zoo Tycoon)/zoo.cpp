/******************************************************************
 * * Name: Oliver Solorzano
 * * Course: CS 162 W 2019
 * * Assignment: Project 2 (Zoo Tycoon)
 * * Date: 03 Jan 2019
 * * Description: This is the implementation file for the zoo class. It
 * * holds all the functions that manipulate the game flow and variables.
 * *******************************************************************/

#include <iostream>
#include <iomanip>
#include "zoo.hpp"
#include <stdlib.h>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void Zoo::increase_capacity(Tiger** &array)  
{
	Tiger **temp = new Tiger*[tiger_capacity * 2]; //create new pointer to pointers that is 2x the capacity of old one

	for (int i = 0; i < tiger_number; i++)       // Run through the loop for the size of the original array
	{
		temp[i] = array[i];		// Add old objects to new array in same position
	}

	delete[] array;		// Delete old array 
	array = temp;  //assign new address to array

	tiger_capacity *= 2;  //double tiger capacity variable
}

void Zoo::increase_capacity(Penguin** &array)
{
	Penguin **temp = new Penguin*[penguin_capacity * 2];	//create new pointer to pointers that is 2x the capacity of old one

	for (int i = 0; i < penguin_number; i++)       // Run through the loop for the size of the original array
	{
		temp[i] = array[i];		// Add old objects to new array in same position
	}

	delete[] array;		// Delete old array 
	array = temp;  //assign new address to array

	penguin_capacity *= 2;	//double penguin capacity variable
}

void Zoo::increase_capacity(Turtle** &array)
{
	Turtle **temp = new Turtle*[turtle_capacity * 2];	//create new pointer to pointers that is 2x the capacity of old one

	for (int i = 0; i < turtle_number; i++)       // Run through the loop for the size of the original array
	{
		temp[i] = array[i];		// Add old objects to new array in same position
	}

	delete[] array;		// Delete old array 
	array = temp;  //assign new address to array

	turtle_capacity *= 2;	//double turtle capacity variable
}

void Zoo::add_tiger()  //function for adding tigers
{
	bool finished = false;  //declare and initialize bool for loop

	do
	{
		if (tiger_capacity > tiger_number)  //if able to store new tiger allocate and add
		{
			tigers[tiger_number] = new Tiger;
			tigers[tiger_number]->age = 3;
			tiger_number++;
			bank_account -= 10000;
			finished = true;  //exit loop
		}
		else
		{
			increase_capacity(tigers);  //if no room, allocate more storage
		}
	} while (finished != true);  //if not finished keep looping
}

void Zoo::add_penguin()  //function for adding penguins
{
	bool finished = false;  //declare and initialize bool for loop

	do
	{
		if (penguin_capacity > penguin_number)   //if able to store new penguin allocate and add
		{
			penguins[penguin_number] = new Penguin;
			penguins[penguin_number]->age = 3;
			penguin_number++;
			bank_account -= 1000;
			finished = true;  //exit loop
		}
		else
		{
			increase_capacity(penguins);  //if no room, allocate more storage
		}
	} while (finished != true);  //if not finished keep looping
}

void Zoo::add_turtle()  //function for adding turtles
{
	bool finished = false;  //declare and initialize bool for loop

	do
	{
		if (turtle_capacity > turtle_number)  //if able to store new turtle allocate and add
		{
			turtles[turtle_number] = new Turtle;
			turtles[turtle_number]->age = 3;
			turtle_number++;
			bank_account -= 100;
			finished = true;  //exit loop
		}
		else
		{
			increase_capacity(turtles);  //if no room, allocate more storage
		}
	} while (finished != true);  //if not finished keep looping
}

bool Zoo::zoo_day()  //function for carrying out daily operations
{
	cout << "\n\nDay " << zoo_day_count << endl;

	for (int i = 0; i < tiger_number; i++)  //increase animal ages by 1
	{
		tigers[i]->age += 1;
	}

	for (int i = 0; i < penguin_number; i++)
	{
		penguins[i]->age += 1;
	}

	for (int i = 0; i < turtle_number; i++)
	{
		turtles[i]->age += 1;
	}

	feed_animals();  //feed animals and calculate cost

	random_event();  //create random event for the day

	calculate_profit();  //calculate the payoff for each animal and profit for the day

	bool animal_selected = false;  //set bool for menu

	do
	{
		std::string userChoice;
		
		cout << "\nThe day is almost over! Would you "
			"like to purchase another animal for your zoo?" << endl;  //print menu and options to user

		cout << "\n-----------------Animal Choices ------------------" << endl;
		cout << "\n1. Tiger ($10,000)" << endl;
		cout << "\n2. Penguin ($1000)" << endl;
		cout << "\n3. Turtle ($100)" << endl;
		cout << "\n4. No purchase " << endl;

		cout << "\nCurrent Tiger Population: " << tiger_number << endl;
		cout << "Current Penguin Population: " << penguin_number << endl;
		cout << "Current Turtle Population: " << turtle_number << endl;

		cout << "\nPlease choose option (1), (2), (3), or (4) and press [Enter] ";

		getline(cin, userChoice);  //get user choice

		if (userChoice == "1")
		{
			cout << "\n***You chose to purchase a Tiger! It will be in your zoo the next day.***" << endl;
			add_tiger();
			animal_selected = true;  //if tiger chosen, add tiger, exit loop
		}

		else if (userChoice == "2")
		{
			cout << "\n***You chose to purchase a Penguin! It will be in your zoo the next day.***" << endl;
			add_penguin();
			animal_selected = true;  //if penguin chosen, add penguin, exit loop
		}

		else if (userChoice == "3")
		{
			cout << "\n***You chose to purchase a Turtle! It will be in your zoo the next day.***" << endl;
			add_turtle();
			animal_selected = true;  //if turtle chosen, add turtle, exit loop
		}
		else if (userChoice == "4")
		{
			cout << "\n***You chose to not purchase an animal today.***" << endl;
			animal_selected = true;  //if user chooses not to purchase, exit loop
		}
		else  //if input invalid, ask again
		{
			cout << "Invalid entry. Please try again" << endl;
		}

	} while (animal_selected != true);

	bool keep_playing = true;

	if (bank_account <= 0)  //if bank account is 0 or negative, exit game, user has no money left
	{
		cout << "\nIt looks like you're out of money! Your Zoo"
			" has gone bankrupt. Better luck next time!" << endl;  
	
		keep_playing = false;  //end game
	}
	else
	{
		std::string userChoice;
		bool valid_entry = false;

		cout << std::fixed << std::setprecision(2);  //print two decimal places

		cout << "\nAnother day, another dollar. Your zoo account balance is currently: $"
			<< bank_account << ". Would you like to keep playing? (Y/N)" << endl;

		do {

			cout << "\nChoose (Y) or (N) and press [Enter] ";

			getline(cin, userChoice);

			for (auto &c : userChoice)  //convert all characters in string to uppercase
			{
				c = toupper(c);
			}

			if (userChoice == "Y")
			{
				cout << "\nYou chose to keep playing!" << endl;
				valid_entry = true;
				keep_playing = true;  //if user wants to keep playing, exit loop and return bool to keep playing
			}

			else if (userChoice == "N")
			{
				cout << "\nYou chose to quit. The game "
					"will now end, goodbye!" << endl;  

				valid_entry = true;  //if user wants to quit, exit loop and return bool to end game
				keep_playing = false;
			}

			else  //if input invalid, ask again
			{
				cout << "Invalid entry. Please try again" << endl;
			}
		} while (valid_entry != true);
	}

	zoo_day_count += 1;  //add 1 to day count
	daily_cost = 0;  //reset daily cost to 0
	daily_profit = 0;  //reset daily profit to 0

	return keep_playing;  
}

void Zoo::feed_animals()  //function to feed animals
{
	for (int i = 0; i < tiger_number; i++)
	{
		daily_cost += ((tigers[i]->base_food_cost) * tiger_number);  //loop through tigers to determine cost

	}

	for (int i = 0; i < penguin_number; i++)
	{
		daily_cost += ((penguins[i]->base_food_cost) * penguin_number);  //loop through penguins to determine cost
	}

	for (int i = 0; i < turtle_number; i++)
	{
		daily_cost += ((turtles[i]->base_food_cost) * turtle_number);  //loop through turtles to determine cost
	}

	cout << "\n***The cost of feeding your animals for the day was: $" << 
		daily_cost << "***" <<endl;  //print cost to user

}

void Zoo::calculate_profit()  //function to calculate profit
{
	for (int i = 0; i < tiger_number; i++)
	{
		daily_profit += ((tigers[i]->payoff) * tiger_number);  //loop through tigers to calculate payoff
	}

	for (int i = 0; i < penguin_number; i++)
	{
		daily_profit += ((penguins[i]->payoff) * penguin_number);  //loop through penguins to calculate payoff
	}

	for (int i = 0; i < turtle_number; i++)
	{
		daily_profit += ((turtles[i]->payoff) * turtle_number);  //loop through turtles to calculate payoff
	}

	cout << "\n***The payoff from your animals for the day was: $" <<
		daily_profit << "***" << endl;  //print total payoff to user

	daily_profit -= daily_cost;  //subtract cost from revenue

	cout << "\n***Your total profit for the day was: $" <<
		daily_profit << "***" << endl;  //print total profit for the day to user

	bank_account += daily_profit;  //add profit to bank account

}

void Zoo::random_event()  //function for choosing random event
{
	int event_rand_number;

	event_rand_number = rand() % 4 + 1;  //choose random number from number of possible events

	current_event = static_cast<EVENT>(event_rand_number);  //convert int to EVENT enum

	if (current_event == SICK)
	{
		sick_animal();  //call sick function
	}
	else if (current_event == BOOM)
	{
		double bonus = 0;
		bonus += (tiger_number) * (rand() % 500 + 250);  //calculate bonus based on number of tigers and random value between 250-500
		daily_profit += bonus;  //add bonus to profit for the day

		cout << "\n***Congrats! There was a huge attendance "
			"today, the tigers were a big hit!";
		cout << " You earned $" << bonus << " in extra "
			"revenue.***" << endl;  //tell user about bonus and quantity
	}
	else if (current_event == BIRTH)
	{
		animal_birth();  //call birth function
	}

}

void Zoo::sick_animal()
{
	int animal_rand_number;

	animal_rand_number = rand() % 3 + 1;  //choose random number from list of possible animals

	rand_animal = static_cast<ZOO_ANIMAL>(animal_rand_number);    //convert int to ZOO_ANIMAL enum

	if ((rand_animal == TIGER) && (tiger_number > 0))  //check to see if there are tigers in the zoo before proceeding
	{
		int tiger = rand() % tiger_number + 1;  //choose random tiger to die
		tiger -= 1;  //decrease value by one to get proper array position

		delete tigers[tiger];  //delete tiger at chosen location
		tiger_number--;  //decrement tiger count by 1
		cout << "\n***Oh no! A tiger fell sick and passed away!***" << endl;

		for (int i = tiger; i < tiger_number; i++)
		{
			tigers[i] = tigers[i + 1];  //shift tiger objects over after removing one
		}
	}

	else if ((rand_animal == PENGUIN) && (penguin_number > 0))  //see above
	{
		int penguin = rand() % penguin_number + 1;
		penguin -= 1;

		delete penguins[penguin];
		penguin_number--;
		cout << "\n***Oh no! A penguin fell sick and passed away!***" << endl;

		for (int i = penguin; i < penguin_number; i++)
		{
			penguins[i] = penguins[i + 1];
		}
	}

	else if ((rand_animal == TURTLE) && (turtle_number > 0))  //see above
	{
		int turtle = rand() % turtle_number + 1;
		turtle -= 1;

		delete turtles[turtle];
		turtle_number--;
		cout << "\n***Oh no! A turtle fell sick and passed away!***" << endl;

		for (int i = turtle; i < turtle_number; i++)
		{
			turtles[i] = turtles[i + 1];
		}
	}

}

void Zoo::animal_birth()
{
	int check = 0;  //check accumulator
	
	int animal_rand_number;

	animal_rand_number = rand() % 3 + 1;  //choose random int from number of possible animals

	rand_animal = static_cast<ZOO_ANIMAL>(animal_rand_number);  //convert int to ZOO_ANIMAL enum

	do {
		
		if (rand_animal == TIGER)  //based on animal choose if
		{
			for (int i = 0; i < tiger_number; i++)  //loop through all existing tigers
			{
				if ((tigers[i]->age) >= 3)  //if tiger is old enough to have baby, continue
				{
					for (int j = 0; j < (tigers[i]->number_of_babies); j++)  //find location to add babies
					{
						if (tiger_capacity < tiger_number)  //check capacity, if not enough room, make more
						{
							increase_capacity(tigers);  
						}

						if (tiger_capacity > tiger_number)  //if enough room create new tiger
						{
							tigers[tiger_number] = new Tiger;
							tigers[tiger_number]->age = 0;  //set new tiger age to 0
							tiger_number++;  //increment tiger count
						}
						
					}

					cout << "\n***" << tigers[i]->number_of_babies << " tiger(s) were born!***" << endl;
					i = tiger_number;  //break top loop
					check = 3;  //set check to 3 to exit parent loop
				}
	
			}

			rand_animal = PENGUIN;  //if not tigers are of age, check next animal
			check++;  //increment check counter by 1, if incremented by two other checks, exit loop(no animals old enough)
		}

		else if (rand_animal == PENGUIN)  //see above
		{
			for (int i = 0; i < penguin_number; i++)
			{
				if ((penguins[i]->age) >= 3)
				{
					for (int j = 0; j < (penguins[i]->number_of_babies); j++)
					{
						if (penguin_capacity < penguin_number)
						{
							increase_capacity(penguins);
						}

						if (penguin_capacity > penguin_number)
						{
							penguins[penguin_number] = new Penguin;
							penguins[penguin_number]->age = 0;
							penguin_number++;
						}

					}

					cout << "\n***" << penguins[i]->number_of_babies << " penguin(s) were born!***" << endl;
					i = penguin_number;
					check = 3;
				}

			}
			rand_animal = PENGUIN;
			check++;
		}

		else if (rand_animal == TURTLE)  //see above
		{
			for (int i = 0; i < turtle_number; i++)
			{
				if ((turtles[i]->age) >= 3)
				{
					for (int j = 0; j < (turtles[i]->number_of_babies); j++)
					{
						if (turtle_capacity < turtle_number)
						{
							increase_capacity(turtles);
						}

						if (turtle_capacity > turtle_number)
						{
							turtles[turtle_number] = new Turtle;
							turtles[turtle_number]->age = 0;
							turtle_number++;
						}

					}

					cout << "\n***" << turtles[i]->number_of_babies << " turtle(s) were born!***" << endl;
					i = turtle_number;
					check = 3;
				}

			}

			rand_animal = PENGUIN;
			check++;
		}

		
	} while (check < 3);  //if check is less than 3, loop again
}

void Zoo::set_up_game()
{
	cout << "************* Hello, Welcome to Zoo Tycoon! ***************" << endl;  //print intro message

	cout << "\nThe starting balance in your bank account is: $" << bank_account << endl;

	cout << "\nWe will start by selecting how many animals"
		" you would like to purchase for your new business." << endl;

	bool tiger_finished = false;  //set bool to make sure all starting animals are selected
	bool penguin_finished = false;
	bool turtle_finished = false;

	do 
	{
		std::string userChoice;

		cout << "\nHow many Tigers would you like to purchase? The cost"
			" of each Tiger is: $10,000."<< endl;

		cout << "\n(Stats: Can have 1 baby, food is twice as expensive, daily payoff is 20% of initial cost)" << endl;

		cout << "\nWould you like (1) or (2) Tigers to start? Choose and press [Enter] ";

		getline(cin, userChoice);


		if (userChoice == "1")  //if user chooses to buy one tiger, continue
		{
			cout << "\n***You chose to purchase 1 Tiger.***" << endl;
			
			bank_account -= 10000;  //subtract cost from account
			tigers[0] = new Tiger;  //create new tiger object in array
			tiger_number += 1;  //increase tiger count

			tiger_finished = true;  //exit tiger choice
		}

		else if (userChoice == "2")  //see above
		{
			cout << "\n***You chose to purchase 2 Tigers.***" << endl;
			
			bank_account -= 20000;
			tigers[0] = new Tiger;
			tigers[1] = new Tiger;
			tiger_number += 2;

			tiger_finished = true;
		}

		else  //if input invalid, ask again
		{
			cout << "Invalid entry. Please try again" << endl;
		}

	} while (tiger_finished != true);  //if user has selected an appropriate option, continue
	
	do
	{
		std::string userChoice;  //see above

		cout << "\nHow many Penguins would you like to purchase? The cost"
			" of each Penguin is: $1,000." << endl;

		cout << "\n(Stats: Can have 5 babies, food cost is normal, daily payoff is 10% of initial cost)" << endl;

		cout << "\nWould you like (1) or (2) Penguins to start? Choose and press [Enter] ";

		getline(cin, userChoice);


		if (userChoice == "1")  //see above
		{
			cout << "\n***You chose to purchase 1 Penguin.***" << endl;
			
			bank_account -= 1000;
			penguins[0] = new Penguin;
			penguin_number += 1;

			penguin_finished = true;
		}

		else if (userChoice == "2")  //see above
		{
			cout << "\n***You chose to purchase 2 Penguins.***" << endl;
			
			bank_account -= 1000;
			penguins[0] = new Penguin;
			penguins[1] = new Penguin;
			penguin_number += 2;
			
			penguin_finished = true;
		}
			

		else  //if input invalid, ask again
		{
			cout << "Invalid entry. Please try again" << endl;
		}

	} while (penguin_finished != true);  //see above

	do
	{
		std::string userChoice;  //see above

		cout << "\nHow many Turtles would you like to purchase? The cost"
			" of each turtle is: $100." << endl;

		cout << "\n(Stats: Can have 10 babies, food is half as expensive, daily payoff is 5% of initial cost)" << endl;

		cout << "\nWould you like (1) or (2) Turtles to start? Choose and press [Enter] ";

		getline(cin, userChoice);


		if (userChoice == "1")  //see above
		{
			cout << "\n***You chose to purchase 1 Turtle.***" << endl;
			
			bank_account -= 100;
			turtles[0] = new Turtle;
			turtle_number += 1;

			turtle_finished = true;
			
		}

		else if (userChoice == "2")  //see above
		{
			cout << "\n***You chose to purchase 2 Turtles.***" << endl;
			
			bank_account -= 200;
			turtles[0] = new Turtle;
			turtles[1] = new Turtle;
			turtle_number += 2;

			turtle_finished = true;
			
		}

		else  //if input invalid, ask again
		{
			cout << "Invalid entry. Please try again" << endl;
		}

	} while (turtle_finished != true);  //see above

}

Zoo::~Zoo()  //destructor that deletes allocated objects at end of program
{	
	for (int i = 0; i < tiger_number; i++)
	{
		delete tigers[i];
	}

	for (int i = 0; i < penguin_number; i++)
	{
		delete penguins[i];
	}

	for (int i = 0; i < turtle_number; i++)
	{
		delete turtles[i];
	}

	delete[] tigers; 
	delete[] penguins;
	delete[] turtles;
}


