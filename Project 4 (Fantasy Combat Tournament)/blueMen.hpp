/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 4
* Date: 03 Mar 2019
* Description: This is the specification file for the blue men class.
* It contains the overrides the functions of the abstract character
* class to become a concrete class. It also inherits all protected
* member variables.
*******************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"  //include header file for parent class

class BlueMen : public Character  //inherit all protected variables and public functions of character
{

public:

	BlueMen(std::string);  //declare constructor

	virtual int attack() override;  //override all pure virtual functions of abstract parent class
	virtual void defense(int) override;
	virtual std::string get_type() override;
	virtual std::string get_name() override;
	virtual int get_strength() override;
	virtual int get_armor() override;
	virtual int get_damage_taken() override;
	virtual int get_attack_pts() override;
	virtual int get_defense_pts() override;
	virtual void recovery() override;

	virtual ~BlueMen() {};  //declare virtual destructor

};
#endif
