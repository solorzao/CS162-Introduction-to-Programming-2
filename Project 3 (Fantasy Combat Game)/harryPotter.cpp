/*******************************************************************
* Name: Oliver Solorzano
* Course: CS 162 W 2019
* Assignment: Project 3
* Date: 16 Feb 2019
* Description: This is the implementation file for the harry potter 
* class. It defines the functions of the harry potter class.
*******************************************************************/

#include "harryPotter.hpp"
#include <cstdlib>
#include <iostream>

HarryPotter::HarryPotter()  //constructor that initializes attribute values unique to class
{
	armor_pts = 0;
	type = "Harry Potter";
	strength_pts = 10;
	lifeCount = 1;
}

int HarryPotter::attack()  //attack function
{
	attack_pts = (rand() % 6 + 1) + (rand() % 6 + 1);

	return attack_pts;
}

void HarryPotter::defense(int opp_attack_pts)  //defense function
{
	defense_pts = (rand() % 6 + 1) + (rand() % 6 + 1);

	defense_pts += armor_pts;  //add armor pts to defense total

	damage_taken = opp_attack_pts - defense_pts;  //damage taken calculated by subtracting defense from offense pts

	if (damage_taken < 0)  //prevent damage taken from being negative, else adds to strength pts
	{
		damage_taken = 0;
	}

	strength_pts = strength_pts - damage_taken;  //subtract damage taken from strength pts

	if ((strength_pts <= 0) && (lifeCount == 1))  //if strength falls below zero, ressurect
	{
		std::cout << "Harry Potter took a deadly blow, but the boy who lived, lives again! And he's back with with a vengeance (double HP). " << std::endl;
		strength_pts = 20;
		lifeCount = 0;
	}

	if (strength_pts < 0)  //prevent strength points from being negative
	{
		strength_pts = 0;
	}

}

std::string HarryPotter::get_type()  //return type as string
{
	return type;
}

int HarryPotter::get_strength()  //return current strength pts
{
	return strength_pts;
}

int HarryPotter::get_armor()  //return current armor pts
{
	return armor_pts;
}

int HarryPotter::get_damage_taken()  //return damage taken
{
	return damage_taken;
}

int HarryPotter::get_attack_pts()  //return attack pts
{
	return attack_pts;
}

int HarryPotter::get_defense_pts()  //return defense pts
{
	return defense_pts;
}
