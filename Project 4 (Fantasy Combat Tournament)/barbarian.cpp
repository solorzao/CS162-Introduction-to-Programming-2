/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 4
* Date: 03 Mar 2019
* Description: This is the implementation file for the barbarian
* class. It defines the functions of the barbarian class.
*******************************************************************/

#include "barbarian.hpp"
#include <cstdlib>

Barbarian::Barbarian(std::string n)  //constructor that initializes attribute values unique to class
{
	name = n;
	type = "Barbarian";
	armor_pts = 0;
	strength_pts = 12;
}

int Barbarian::attack()  //attack function
{
	attack_pts = (rand() % 6 + 1) + (rand() % 6 + 1);

	return attack_pts;
}

void Barbarian::defense(int opp_attack_pts)  //defense function
{
	defense_pts = (rand() % 6 + 1) + (rand() % 6 + 1);

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

std::string Barbarian::get_type()  //return type as string
{
	return type;
}

std::string Barbarian::get_name()
{
	return name;
}

int Barbarian::get_strength()  //return current strength pts
{
	return strength_pts;
}

int Barbarian::get_armor()  //return current armor pts
{
	return armor_pts;
}

int Barbarian::get_damage_taken()  //return damage taken
{
	return damage_taken;
}

int Barbarian::get_attack_pts()  //return attack pts
{
	return attack_pts;
}

int Barbarian::get_defense_pts()  //return defense pts
{
	return defense_pts;
}

void Barbarian::recovery()	//restore half of damage taken(only int quotient)
{
	total_damage_taken = 12 - strength_pts;

	strength_pts += (total_damage_taken / 2);
}


