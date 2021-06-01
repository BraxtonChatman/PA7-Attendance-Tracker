#pragma once
#include"Stack.h"


class Data {
public:
	//-structors
	Data();
	~Data();


	//setters
	void setRecordNumber(int newRecordNumber);
	void setIdNumber(int newIdNumber);
	void setName(std::string newName);
	void setEmail(std::string newEmail);
	void setUnits(int newUnits);
	void setProgram(std::string newProgram);
	void setLevel(std::string newLevel);
	void setNumberAbsences(int newNumberAbsences);

	
	//getters
	int getRecordNumber();
	int getIdNumber();
	std::string getName();
	std::string getEmail();
	int getUnits();
	std::string getProgram();
	std::string getLevel();
	int getNumAbsences();
	Stack &getAbsences();


	//copy assignment operator
	void operator=(Data &dataToCopy);

private:
	int recordNumber;
	int idNumber;
	std::string name;
	std::string email;
	int units;
	std::string program;
	std::string level;
	int numAbsences;
	Stack Absences;
};

std::fstream & operator >> (std::fstream &lhs, Data &rhs);
std::fstream & operator<<(std::fstream &lhs, Data &rhs);