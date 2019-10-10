/*********************************************************************
** File name:    main.cpp
** Author:       Group 3
** Date:         02/14/19
** Description:  Main file for Predator-Prey game
**               run ./game
*********************************************************************/

#include <iostream>
#include <limits>
#include <ctime>
#include <string>
#include <cstring>

#include "Game.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include "grid_functions.hpp"


//function prototypes

int start();

bool askToKeepPlaying();

void customize(int steps, Game *);

int main() {
	std::cout << "==========Predator-Prey Game==========" << std::endl;  
	std::cout << "===============Group 3================" << std::endl;
	std::cout << "====Extra Credit options included=====" << std::endl;
  	
	//seed rand
    std::srand(time(0)); 
	
	//Game setup variables
	auto game1 = new Game;
	int steps = 0;

	//Set initial steps
	steps = start();
	game1->setSteps(steps);  

	//Customize game options
	customize(game1->getSteps(), game1);   

	//Create game & populate board
	Critter ***grid1 = nullptr;  
	grid1 = createGrid(grid1, *game1);
	populate(grid1, *game1);

	//Output game info & starting grid
	std::cout << "Game settings" << "\n";
	std::cout << " Rows:            " << game1->getRows() << "\n";
	std::cout << " Columns:         " << game1->getCols() << "\n";
	std::cout << " Ants:            " << game1->getAnts() << "\n";
	std::cout << " Doodlebugs:      " << game1->getDoodles() << "\n";
	std::cout << " Number of steps: " << game1->getSteps() << "\n\n";
	std::cout << "This is the starting game board" << std::endl;
	print(grid1, *game1);
	std::cout << std::endl;
	
	//Variables used in loop that outputs simulation
	int i{0};
	int lastStep{0};
    bool keepPlaying = false;
	
    do 
	{
  		//Loop simulation through number of steps specified by user 
		
        //change i to 0, i < from i to 1, i <=
        for (i = lastStep; i < (game1->getSteps()); i++) {
            std::cout << "This is the step number: " << i + 1 << "\n";
            //was executeStep(grid1, *game1, game1->getSteps());
            //updated last part to i
            executeStep(grid1, *game1, i);
            print(grid1, *game1);
			std::cout << std::endl;
			lastStep += 1;
        }
		
		//Call function to ask user if they want to keep playing
        keepPlaying = askToKeepPlaying();  
		
		//If playing continues, get additional number of steps & update counter
		if (keepPlaying)
		{
			int additionalSteps = start();
			additionalSteps = additionalSteps + game1->getSteps();
			game1->setSteps(additionalSteps);
		}
		
	} while (keepPlaying);  
	
	//Clean up memory
	clearMemory(grid1, *game1);
	delete game1;
    return 0;
}

int start() {
    bool valid = false;  //set bool for valid user input to false
    int steps = 0;
    std::string steps_s;

    do {
        std::cout
                << "\nPlease enter the number of steps you would like the simulation to run for and press [Enter] (Min Steps: 1) ";  //ask user for number of steps
        std::cin >> steps_s;

        if (steps_s.find(".") != std::string::npos) { //check for decimal point
            steps = -1; //if found bias input out of range to bounce at validation
        } else {
            steps = std::stoi(steps_s.c_str()); //else convert to int
        }

        std::cin.clear();  //clear input for next
        std::cin.ignore(100, '\n');

        if (std::cin.fail() || (steps < 1))  //if not int, ask again
        {
            std::cout << "\n**********Invalid entry. Please try again**********" << std::endl;
        } else {
            valid = true;  //if input valid, exit loop
        }

    } while (!valid);

    return steps;  //return number of steps to use in main loop
}

bool askToKeepPlaying() {
    bool valid = false;
    bool keepPlaying = false;
    std::string userChoice;

	do {
		std::cout << "\nWould you like to continue the simulation again? (Y/N) ";  //ask user for number of steps

		getline(std::cin, userChoice);

		if (userChoice == "Y" || userChoice == "y") {
			std::cout << "\n***You chose to continue the simulation again***\n" << std::endl;
			keepPlaying = true;
			valid = true;  //set to true, exit loop
		}
		else if (userChoice == "N" || userChoice == "n") {
			std::cout << "\n***You chose to end the simulation, goodbye.***" << std::endl;
			keepPlaying = false;
			valid = true;  //set to true, exit loop
		}
		else
		{
			std::cout << "\n**********Invalid entry. Please try again**********" << std::endl;
		}

	} while (!valid);

    return keepPlaying;
}

void customize(int steps, Game *game1) {
    std::string userChoice_s;
    int userChoice;
    bool valid = false;

    do {
        std::cout << "\nHow would you like to run the simulation? Please choose option (1) or (2) and press [Enter] "
             << std::endl;

        std::cout << "\n1. Run with default values\n"
             << "\n2. Enter values for the size of the grid rows and columns, the number of ants, and the number of doodlebugs\n"
             << std::endl;

        std::cin >> userChoice_s;
        
        if (userChoice_s.find(".") != std::string::npos) { //check for decimal point
            userChoice = -1; //if found bias input out of range to bounce at validation
        } else {
            userChoice = std::stoi(userChoice_s.c_str()); //else convert to int
        }

        std::cin.clear();  //clear input for next
        std::cin.ignore(100, '\n');

        if (std::cin.fail())  //if not int, ask again
        {
            std::cout << "\n**********Invalid entry. Please try again**********" << std::endl;
        } else if (userChoice == 1) {
            //gamePointer = &game1;
            game1->setDoodles(5);
            game1->setAnts(100);
            game1->setRows(20);
            game1->setColumns(20);
            valid = true;
        } else if (userChoice == 2) {
            std::string rows_s, columns_s, antNumber_s, doodlebugNumber_s;
            int rows, columns, antNumber, doodlebugNumber;
            bool insideValid = false;
			
            do {
                std::cout << "\nPlease enter the number of rows for your grid and press [Enter] (Min: 5, Max: 30) ";
				
		std::cin >> rows_s;
              
                if (rows_s.find(".") != std::string::npos) { //check for decimal point
                    rows = -1; //if found bias input out of range to bounce at validation
                } else {
                    rows = std::stoi(rows_s.c_str()); //else convert to int
                }
                                
                if ((rows < 5) || (rows > 30)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n***Invalid, entry. Please try again.***" << std::endl;
                } else if (rows >= 5 && rows <= 30) {
                    game1->setRows(rows);
                    insideValid = true;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

            } while (!insideValid);

            do {
                std::cout << "\nPlease enter the number of columns for your grid and press [Enter] (Min: 5, Max: 30) ";
                std::cin >> columns_s;
                                
                if (columns_s.find(".") != std::string::npos) { //check for decimal point
                    columns = -1; //if found bias input out of range to bounce at validation
                } else {
                    columns = std::stoi(columns_s.c_str()); //if found bias input out of range to bounce at validation
                }

                if (std::cin.fail() || (columns < 5) || (columns > 30)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n***Invalid, entry. Please try again.***" << std::endl;
                    insideValid = false;
                } else if (columns >= 5 && columns <= 30) {
                    game1->setColumns(columns);
                    insideValid = true;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

            } while (!insideValid);

            do {
                int antUpperLimit = ((rows * columns) - 1);

                std::cout << "\nPlease enter the number of ants for your simulation and press [Enter] (Min: 1, Max: "
                     << antUpperLimit << ") ";
                std::cin >> antNumber_s;

                if (antNumber_s.find(".") != std::string::npos) { //check for decimal point
                    antNumber = -1; //if found bias input out of range to bounce at validation
                } else {
                    antNumber = std::stoi(antNumber_s.c_str()); //if found bias input out of range to bounce at validation
                }

                if (std::cin.fail() || (antNumber < 1) || (antNumber > antUpperLimit)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n***Invalid, entry. Please try again.***" << std::endl;
                    insideValid = false;
                } else if (antNumber >= 1 && antNumber <= antUpperLimit) {
                    game1->setAnts(antNumber);
                    insideValid = true;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

            } while (!insideValid);

            do {
                int doodlebugUpperLimit = ((rows * columns) - antNumber);

                std::cout << "\nPlease enter the number of doodlebugs for your simulation and press [Enter] (Min: 1, Max: "
                     << doodlebugUpperLimit << ") ";
                std::cin >> doodlebugNumber_s;

                if (doodlebugNumber_s.find(".") != std::string::npos) { //check for decimal point
                    doodlebugNumber = -1; //if found bias input out of range to bounce at validation
                } else {
                    doodlebugNumber = std::stoi(doodlebugNumber_s.c_str()); //if found bias input out of range to bounce at validation
                }

                if (std::cin.fail() || (doodlebugNumber < 1) || (doodlebugNumber > doodlebugUpperLimit)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\n***Invalid, entry. Please try again.***" << std::endl;
                    insideValid = false;
                } else if (doodlebugNumber >= 1 && doodlebugNumber <= doodlebugUpperLimit) {
                    game1->setDoodles(doodlebugNumber);
                    insideValid = true;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }

            } while (!insideValid);

            valid = true;
        } else {
            std::cout << "\n**********Invalid entry. Please try again**********" << std::endl;
        }

    } while (!valid);

   
}
