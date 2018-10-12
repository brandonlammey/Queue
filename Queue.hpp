/*
 * File Name: Queue.hpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 05
 * Description: Implements Queue class. 
 */

//#include "QueueInterface.h"
//#include "Node.h"
//#include "PreconditionViolationException.h"
//#include <iostream>

template<typename T>
Queue<T>::Queue()
{
	m_frontPtr = nullptr;//initialize front pointer to null empty stack 
	m_rearPtr = nullptr;//initialize rear pointer to null empty stack 
}

template<typename T>
Queue<T>::~Queue()
{
	while(m_frontPtr!= nullptr)
	{
		Node<T>* tempNodePtr = m_frontPtr->getNext(); //create temp pointer to next node 
		delete(m_frontPtr);//delete front node
		m_frontPtr = tempNodePtr; //set top pointer to next node 		 
	}
	m_rearPtr = m_frontPtr = nullptr; 

}

template<typename T>
bool Queue<T>::isEmpty() const
{
	if(m_frontPtr == nullptr)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

template<typename T>
void Queue<T>::enqueue(const T& newEntry) throw (PreconditionViolationException) 
{
	
	//create new node and set value to passed in parameter	
	Node<T>* newNodePtr = new Node<T>();
	newNodePtr->setValue(newEntry);
	
	if(newNodePtr == nullptr)
	{
		throw PreconditionViolationException("Heap Memory Full");
	}
	else
	{
		if(m_frontPtr == nullptr)
		{	 	
			m_frontPtr = newNodePtr;
			m_rearPtr = newNodePtr; 
			newNodePtr->setNext(nullptr);
		}		
		else
		{		
			m_rearPtr->setNext(newNodePtr);
			m_rearPtr = newNodePtr;

		}
	}
}

template<typename T>
void Queue<T>::dequeue() throw(PreconditionViolationException)
{
	if(m_frontPtr == nullptr)//check to see if queue is empty and handle error
	{
		throw PreconditionViolationException("Can't Dequeue on empty queue");
	}
	else
	{

		Node<T>* tempNodePtr = m_frontPtr->getNext(); //create temp pointer to next node 
		delete(m_frontPtr);//delete top node
		m_frontPtr = tempNodePtr; //set top pointer to next node 


		if(m_frontPtr == nullptr)// last item removed 
		{		
			m_rearPtr = nullptr;
		}


	}	
	
}

template<typename T>
T Queue<T>::peekFront() const throw(PreconditionViolationException)
{
	if(m_frontPtr == nullptr)//check to see if queue is empty and handle error
	{
		throw PreconditionViolationException("Can't Peek on empty queue");
	}
	else
	{
		return(m_frontPtr->getValue());
	}
}

