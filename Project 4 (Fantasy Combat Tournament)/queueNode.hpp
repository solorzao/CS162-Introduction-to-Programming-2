/************************************************************************************************
* Name: Oliver Solorzano
* Date: 03 Mar 2019
* Course: CS 162 W 2019
* Assignment: Project 4
* Description: This is the specification file for the queue node structure. It declares the variables
* and a constructor for the class.
************************************************************************************************/

#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

#include "character.hpp"

struct QueueNode {

	Character *fighter = nullptr;
	
	QueueNode *next = nullptr;
	QueueNode *prev = nullptr;

	~QueueNode() {
		delete fighter;
	};
};

#endif

