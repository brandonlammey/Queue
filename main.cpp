/*
 * File Name: main.cpp
 * Author: Brandon Lammey 
 * Description: Main to call on test cases for a Queue data structure.  
 */

#include<iostream>

// #include<stdexcept>
// #include<string>
// #include<fstream>

#include "Queue.h"
#include "PreconditionViolationException.h"

int main(int argc, char** argv)
{ 

	// string input = "";
	// std::string fileInput = argv[1];

	// std::ifstream readFile; 
	// readFile.open(fileInput);

	// readFile >> input; 

	std::string testString;
	std::cout << "Enter string: ";
	std::cin >> testString;

	Queue<string> testQueue; //test queue object

	testQueue.enqueue(testString);
	std::cout << "In Queue: " << testQueue.peekFront() << '\n';
	testQueue.dequeue();
	
	// while(!readFile.eof())
	// {
	// 	readFile >> input; //read in next command / name
	// }
	
	std::cout<< '\n';
	return(0); 
}
