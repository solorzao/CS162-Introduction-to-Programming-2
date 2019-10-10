/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 3
* Date: 16 Feb 2019
* Description:  This is the implementation file for the medusa 
* class. It defines the functions of the medusa class.
*******************************************************************/

#include "medusa.hpp"
#include <cstdlib>
#include <iostream>

Medusa::Medusa()   //constructor that initializes attribute values unique to class
{
	armor_pts = 3;
	type = "Medusa";
	strength_pts = 8;
}

int Medusa::attack()   //attack function
{
	attack_pts = (rand() % 6 + 1) + (rand() % 6 + 1);

	if (attack_pts == 12) //if 12, use glare, overpower to ensure opponent dies
	{
		std::cout << "Medusa used glare!" << std::endl;
		attack_pts = 1000;
	}

	return attack_pts;
}

void Medusa::defense(int opp_attack_pts)  //defense function
{
	defense_pts = (rand() % 6 + 1);

	defense_pts += armor_pts;  //add armor pts to defense total

	damage_taken = opp_attack_pts - defense_pts;  //damage taken calculated by subtracting defense from offense pts

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

std::string Medusa::get_type()  //return type as string
{
	return type;
}

int Medusa::get_strength()  //return current strength pts
{
	return strength_pts;
}

int Medusa::get_armor()  //return current armor pts
{
	return armor_pts;
}

int Medusa::get_damage_taken()  //return damage taken
{
	return damage_taken;
}

int Medusa::get_attack_pts()  //return attack pts
{
	return attack_pts;
}

int Medusa::get_defense_pts()  //return defense pts
{
	return defense_pts;
}
