/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 3
* Date: 16 Feb 2019
* Description: This is the specification file for the Harry Potter class.
* It contains the overrides the functions of the abstract character 
* class to become a concrete class. It also inherits all protected
* member variables.
*******************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "character.hpp"  //include header file for parent class

class HarryPotter : public Character  //inherit all protected variables and public functions of character
{
private:

	int lifeCount;

public:

	HarryPotter();  //declare constructor

	virtual int attack() override;  //override all pure virtual functions of abstract parent class
	virtual void defense(int) override;
	virtual std::string get_type() override;
	virtual int get_strength() override;
	virtual int get_armor() override;
	virtual int get_damage_taken() override;
	virtual int get_attack_pts() override;
	virtual int get_defense_pts() override;

	virtual ~HarryPotter() {};  //declare virtual destructor
};
#endif


