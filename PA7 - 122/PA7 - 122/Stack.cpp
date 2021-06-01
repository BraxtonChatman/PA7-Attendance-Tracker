#include"Stack.h"


Stack::Stack()
{
	numAbsences = 0;

	for (int n = 0; n < 50; n++)
	{
		mAbsences[n] = "";
	}
}
Stack::~Stack()
{

}

bool Stack::isEmpty()
{
	bool val = false;
	if (this->numAbsences == 0)
		val = true;
	return val;
}
void Stack::push(std::string newAbsence)
{
	this->mAbsences[numAbsences] = newAbsence;
	this->numAbsences++;
}
std::string Stack::pop()
{
	if (numAbsences != 0)
	{
		std::string poppedAbsence = "";
		poppedAbsence = mAbsences[numAbsences - 1];
		mAbsences[numAbsences - 1] = "";
		numAbsences--;
		return poppedAbsence;
	}
}
std::string Stack::peek()
{
	if (numAbsences!=0)
	{
		return mAbsences[numAbsences-1];
	}
}

std::string Stack::peek(int absenceNumber)
{
	return mAbsences[absenceNumber];
}

void Stack::editAbsence(int index, std::string newDate)
{
	if (newDate == "NA")
	{
		mAbsences[index] = "";
		numAbsences--;
	}
	else
	{
		mAbsences[index] = newDate;
	}
}


void Stack::setNumAbsences(int newNumAbsences)
{
	numAbsences = newNumAbsences;
}

