/************************************************************************************************
* Name: Oliver Solorzano
* Date: 03 Mar 2019
* Course: CS 162 W 2019
* Assignment: Project 4
* Description: This is the implementation file for the queue class. It defines the functions
* of the class. The functions include checking if the queue is empty, adding a node to the back
* of the queue, getting the value of the front node, removing the front node, and printing the queue.
************************************************************************************************/

#include "queue.hpp"
#include "queueNode.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

bool Queue::isEmpty()  //check if list is empty
{
	bool emptyCheck = false;

	if (head == nullptr)  //if head pointer isn't pointing to anything, queue is empty
	{
		emptyCheck = true;
	}
	else if (head != nullptr)  //if head pointer is pointing to something, queue has nodes
	{
		emptyCheck = false;
	}

	return emptyCheck;  //return bool
}

 void Queue::addBack(std::string t, std::string name) //take name and type(number based on user input)
{
	std::string type = t;

	if (isEmpty())  //if empty
	{
		head = new QueueNode;  //create new queue node object, set to head
		head->next = head;
		head->prev = head;

		if (type == "1")
		{
			head->fighter = new Vampire(name);
		}
		else if (type == "2")
		{
			head->fighter = new Barbarian(name);
		}
		else if (type == "3")
		{
			head->fighter = new BlueMen(name);
		}
		else if (type == "4")
		{
			head->fighter = new Medusa(name);
		}
		else if (type == "5")
		{
			head->fighter = new HarryPotter(name);
		}
	}
	else if (!isEmpty()) //if not empty
	{
		QueueNode *temp = head;  //create temp pointer to hold address of head

		while (temp->next != head)  //go through list until the object before the head is reached (full circle)
		{
			temp = temp->next;  //set temp to address of next object
		}

		temp->next = new QueueNode();  //once end of circle is reached, create new queue node
		
		if (type == "1")
		{
			temp->next->fighter = new Vampire(name);
		}
		else if (type == "2")
		{
			temp->next->fighter = new Barbarian(name);
		}
		else if (type == "3")
		{
			temp->next->fighter = new BlueMen(name);
		}
		else if (type == "4")
		{
			temp->next->fighter = new Medusa(name);
		}
		else if (type == "5")
		{
			temp->next->fighter = new HarryPotter(name);
		}

		temp = temp->next;  //set temp to new object address
		temp->next = head;  //point next pointer of new object to head to make circular
		head->prev = temp;  //point head prev pointer to new object at back
	}
}

 void Queue::addFront(std::string t, std::string name)  //take name and tyoe(string pulled from get_name)
 {
	 std::string type = t;

	 if (isEmpty())  //if empty
	 {
		 head = new QueueNode();  //create new queue node object, set to head
		 head->next = head;
		 head->prev = head;

		 if (type == "Vampire")
		 {
			 head->fighter = new Vampire(name);
		 }
		 else if (type == "Barbarian")
		 {
			 head->fighter = new Barbarian(name);
		 }
		 else if (type == "Blue Men")
		 {
			 head->fighter = new BlueMen(name);
		 }
		 else if (type == "Medusa")
		 {
			 head->fighter = new Medusa(name);
		 }
		 else if (type == "Harry Potter")
		 {
			 head->fighter = new HarryPotter(name);
		 }
	 }
	 else if (!isEmpty())  //if not empty
	 {
		 QueueNode *temp = head;  //create temp pointer to hold address of head

		 while (temp->next != head)  //go through list until the object before the head is reached (full circle)
		 {
			 temp = temp->next;  //set temp to address of next object
		 }

		 temp->next = new QueueNode();  //once end of circle is reached, create new queue node

		 temp = temp->next; //set temp to point at new object

		 if (type == "Vampire")
		 {
			 temp->fighter = new Vampire(name);
		 }
		 else if (type == "Barbarian")
		 {
			 temp->fighter = new Barbarian(name);
		 }
		 else if (type == "Blue Men")
		 {
			 temp->fighter = new BlueMen(name);
		 }
		 else if (type == "Medusa")
		 {
			 temp->fighter = new Medusa(name);
		 }
		 else if (type == "Harry Potter")
		 {
			 temp->fighter = new HarryPotter(name);
		 }
		
		 temp->next = head; //connect new node to old head
		 temp->prev = head->prev; //connect new node prev to old head prev
		 head->prev = nullptr; //set old head prev to null
		 head = temp;  //set new head to be temp
	 }
 }

void Queue::removeFront()
{
	if (head == nullptr) //if list is empty, do nothing
	{
		cout << endl;
	}
	else if (head->next == head)  //if last object in queue, delete head, set pointer to null
	{
		delete head;
		head = nullptr;
	}

	else //if more than queue node in queue
	{
		QueueNode *temp = head->prev;  //create temp pointer to point to end of circle (before head)
		temp->next = head->next;    //skip over head to create new link
		delete head;;  //delete old head, close gap 
		head = temp->next;  //set new head
		head->prev = temp;   //set head to point back at newly connected object
	}
	
}

void Queue::moveLoser(Queue* toQueue) //takes queue to move to
{
	std::string name = head->fighter->get_name();  //get name of loser
	
	std::string type = head->fighter->get_type();  //get type of loser 

	toQueue->addFront(type, name);  //add node with same name/type to losers queue

	removeFront();  //remove loser from lineup
	
}

void Queue::moveWinner()
{
	QueueNode *temp = head;  //create temp pointer to hold address of head

	Character *swap = nullptr;

	do
	{
		temp = temp->next;  //set temp to address of next object
		swap = temp->fighter;  //swap fighter pointers between nodes from beginning to end
		temp->fighter = temp->next->fighter;
		temp->next->fighter = swap;

	} while (temp->next != head); //once done cycling from beginning to end of circle, exit loop
}

void Queue::printQueue()
{

	if (head != nullptr)
	{
		int count = 1;
		cout << "\n";
		QueueNode* temp = head;  //create temp pointer to hold current head

		do   //while temp pointer isn't pointing to the head (full circle), keep looping
		{
			cout << count << ". " << temp->fighter->get_name() << " (" << temp->fighter->get_type() << ")\n";  //print current node value
			temp = temp->next;  //set temp to address of next node
			count++;

		} while (temp != head);

		cout << endl;
	}
}

Queue::~Queue()
{
	while(!isEmpty()) //if queue isn't empty keep deleting head
	{
		removeFront();
	}

}

