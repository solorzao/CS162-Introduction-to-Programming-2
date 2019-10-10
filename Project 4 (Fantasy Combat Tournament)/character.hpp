/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 4
* Date: 03 Mar 2019
* Description: This is the specification file for the abstract
* character class. It contains protected variables and public functions
* that are inherited that are inherited by the child classes. Common
* attributes of child classes are attack pts, defense pts, armor pts,
* strength pts, and damage taken. All functions except glare_check
* need to be overriden to create a concrete class.
*******************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

class Character
{
protected:

	int attack_pts, defense_pts, armor_pts, strength_pts, damage_taken, total_damage_taken;  //variables to be inherited by child classes
	
	
	std::string name, type;

public:
	//pure virtual functions
	virtual int attack() = 0;
	virtual void defense(int) = 0;
	virtual std::string get_type() = 0;
	virtual std::string get_name() = 0;
	virtual int get_strength() = 0;
	virtual int get_armor() = 0;
	virtual int get_damage_taken() = 0;
	virtual int get_attack_pts() = 0;
	virtual int get_defense_pts() = 0;
	virtual void recovery() = 0;
	
	virtual bool charm_check() {  //created virtual charm function and defined it, so it doesn't need to be overriden by every class
		return false;			  //all child classes except vampire will return always return false
	};

	virtual ~Character() {};
};
#endif
