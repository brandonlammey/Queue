/*
 * File Name: Queue.h
 * Author: Brandon Lammey 
 * Description: Inherits queue interface. Implements all methods from QueueInterface. 
 * Uses node class to build a queue of nodes. Any invalid calls returns meaningful error messages. 
 */

#ifndef QUEUE_H
#define QUEUE_H
#include "QueueInterface.h"
#include "Node.h"
#include "PreconditionViolationException.h"
#include<iostream>



//implemetns all methods from stackInterface
template<typename T>
class Queue: public QueueInterface<T>
{
	//precondition, postcondition, return, and throws comments in this class
	//use templated node class as building block of the queue

	private:
	Node<T>* m_frontPtr; //front node in queue
	Node<T>* m_rearPtr; //rear node in queue
	
	public:
	Queue(); // Constructor 
	~Queue(); //Destructor 
	

	//returns true if the queue is empty false otherwise
	bool isEmpty() const;

	//checks available memory
	//if enough memory adds node to end of queue
	//else throws exception
	void enqueue(const T& newEntry) throw (PreconditionViolationException);

	//Checks if queue is empty 
	//front node in queue is removed
	//throws PreconditionViolationException when dequeue is attempted on an empty queue. 
	void dequeue() throw (PreconditionViolationException);

	//assumes the stack is not empty
	//returns the value at the front of the queue 
	//throws a PreconditionViolationException if queue is empty
	T peekFront() const throw(PreconditionViolationException);

	
};

#include "Queue.hpp"
#endif
