#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>



class Stack {
public:
	Stack();
	~Stack();

	bool isEmpty();
	void push(std::string newAbsence);
	std::string pop();
	std::string peek();

	std::string peek(int absenceNumber);
	void editAbsence(int index, std::string newDate);

	void setNumAbsences(int newNumAbsences);


private:
	std::string mAbsences[50];
	int numAbsences;
};