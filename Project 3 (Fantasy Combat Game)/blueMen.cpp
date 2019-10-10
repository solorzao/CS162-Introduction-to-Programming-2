/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 3
* Date: 16 Feb 2019
* Description: This is the implementation file for the blue men 
* class. It defines the functions of the blue men class.
*******************************************************************/

#include "blueMen.hpp"
#include <cstdlib>

BlueMen::BlueMen()  //constructor that initializes attribute values unique to class
{
	armor_pts = 3;
	type = "Blue Men";
	strength_pts = 12;
}

int BlueMen::attack()  //attack function
{
	attack_pts = (rand() % 10 + 1) + (rand() % 10 + 1);

	return attack_pts;
}

void BlueMen::defense(int opp_attack_pts)  //defense function
{
	//adjust current armor pts based on strength pts
	if (strength_pts > 8)
	{
		defense_pts = (rand() % 6 + 1) + (rand() % 6 + 1) + (rand() % 6 + 1);
	}
	else if ((strength_pts > 4) && (strength_pts <= 8))
	{
		defense_pts = (rand() % 6 + 1) + (rand() % 6 + 1);
	}
	else if (strength_pts <= 4)
	{
		defense_pts = (rand() % 6 + 1);
	}

	defense_pts += armor_pts;  //add armor pts to defense total

	damage_taken = opp_attack_pts - defense_pts; //damage taken calculated by subtracting defense from offense pts
	
	if (damage_taken < 0)  //prevent damage taken from being negative, else adds to strength pts
	{
		damage_taken = 0;
	}

	strength_pts = strength_pts - damage_taken;  //subtract damage taken from strength pts

	if (strength_pts < 0)  //prevent strength points from being negative
	{
		strength_pts = 0;
	}

}

std::string BlueMen::get_type()  //return type as string
{
	return type;
}

int BlueMen::get_strength()  //return current strength pts
{
	return strength_pts;
}

int BlueMen::get_armor()  //return current armor pts
{
	return armor_pts;
}

int BlueMen::get_damage_taken()  //return damage taken
{
	return damage_taken;
}

int BlueMen::get_attack_pts()   //return attack pts
{
	return attack_pts;
}

int BlueMen::get_defense_pts()  //return defense pts
{
	return defense_pts; 
}

