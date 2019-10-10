/************************************************************************************************
* Name: Oliver Solorzano
* Date: 03 Mar 2019
* Course: CS 162 W 2019
* Assignment: Project 4
* Description: this is the specification file for the queue class. It contains the function
* prototypes and member declarations for the class.
************************************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "queueNode.hpp"
#include "character.hpp"

class Queue
{
public:

	int listCount = 0;

	QueueNode *head;

	Queue() { head = nullptr; }  //set head pointer to null upon constructing class object
	
	bool isEmpty();  //function prototypes
	void addBack(std::string t, std::string);
	void addFront(std::string t, std::string);
	void removeFront();
	void moveLoser(Queue*);
	void moveWinner();
	void printQueue();

	~Queue();

};



#endif 
