/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 4 
* Date: 03 Mar 2019
* Description:  This is the implementation file for the vampire
* class. It defines the functions of the vampire class.
*******************************************************************/

#include "vampire.hpp"
#include <cstdlib>
#include <iostream>

Vampire::Vampire(std::string n)  //constructor that initializes attribute values unique to class
{
	name = n;
	type = "Vampire";
	armor_pts = 1;
	strength_pts = 18;
}

int Vampire::attack()  //attack function
{
	attack_pts = (rand() % 12 + 1);

	return attack_pts;
}

void Vampire::defense(int opp_attack_pts)  //defense function
{
	defense_pts = (rand() % 6 + 1);

	defense_pts += armor_pts;  //add armor pts to defense total

	int charm_chance = (rand() % 2 + 1);

	if (charm_chance == 1)
	{
		damage_taken = opp_attack_pts - defense_pts;  //damage taken calculated by subtracting defense from offense pts
		charm = false;
	}

	else if (charm_chance == 2) //if roll is 2, use charm
	{
		std::cout << "Vampire used Charm!" << std::endl;
		charm = true;  //set charm bool to true
		damage_taken = 0;
	}

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

std::string Vampire::get_type()  //return type as string
{
	return type;
}

std::string Vampire::get_name()	//return name
{
	return name;
}

int Vampire::get_strength()  //return current strength pts
{
	return strength_pts;
}

int Vampire::get_armor()  //return current armor pts
{
	return armor_pts;
}

int Vampire::get_damage_taken()  //return damage taken
{
	return damage_taken;
}

int Vampire::get_attack_pts()  //return attack pts
{
	return attack_pts;
}

int Vampire::get_defense_pts()  //return defense pts
{
	return defense_pts;
}

void Vampire::recovery()	//restore half of damage taken
{
	total_damage_taken = 18 - strength_pts;

	strength_pts += (total_damage_taken / 2);
}

bool Vampire::charm_check()  //return glare status
{
	return charm;
}

