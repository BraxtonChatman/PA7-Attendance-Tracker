#include"Data.h"


//default constructor
Data::Data()
{
	setRecordNumber(0);
	setIdNumber(0);
	setName("");
	setEmail("");
	setUnits(0);
	setProgram("");
	setLevel("");
	setNumberAbsences(0);
}

//destructor
Data::~Data()
{

}

//setters
void Data::setRecordNumber(int newRecordNumber)
{
	this->recordNumber = newRecordNumber;
}
void Data::setIdNumber(int newIdNumber)
{
	this->idNumber = newIdNumber;
}
void Data::setName(std::string newName)
{
	this->name = newName;
}
void Data::setEmail(std::string newEmail)
{
	this->email = newEmail;
}
void Data::setUnits(int newUnits)
{
	this->units = newUnits;
}
void Data::setProgram(std::string newProgram)
{
	this->program = newProgram;
}
void Data::setLevel(std::string newLevel)
{
	this->level = newLevel;
}
void Data::setNumberAbsences(int newNumberAbsences)
{
	this->numAbsences = newNumberAbsences;
}

//getters
int Data::getRecordNumber()
{
	return this->recordNumber;
}
int Data::getIdNumber()
{
	return this->idNumber;
}
std::string Data::getName()
{
	return this->name;
}
std::string Data::getEmail()
{
	return this->email;
}
int Data::getUnits()
{
	return this->units;
}
std::string Data::getProgram()
{
	return this->program;
}
std::string Data::getLevel()
{
	return this->level;
}
int Data::getNumAbsences()
{
	return this->numAbsences;
}
Stack& Data::getAbsences()
{
	return this->Absences;
}



//overloaded copy assignment operator
void Data::operator=(Data &dataToCopy)
{
	setRecordNumber(dataToCopy.recordNumber);
	setIdNumber(dataToCopy.idNumber);
	setName(dataToCopy.name);
	setEmail(dataToCopy.email);
	setUnits(dataToCopy.units);
	setProgram(dataToCopy.program);
	setLevel(dataToCopy.level);
	setNumberAbsences(dataToCopy.numAbsences);
}


//overloaded stream extraction operator for reading data from .csv
std::fstream & operator >> (std::fstream &lhs, Data &rhs)
{
	char line[150]="";	

	lhs.getline(line, 150, ',');
	rhs.setRecordNumber(atoi(line));

	lhs.getline(line, 150, ',');
	rhs.setIdNumber(atoi(line));

	lhs.getline(line, 150, '\"');
	lhs.getline(line, 150, '\"');
	rhs.setName(line);

	lhs.getline(line, 150, ',');
	lhs.getline(line, 150, ',');

	rhs.setEmail(line);

	lhs.getline(line, 150, ',');
	rhs.setUnits(atoi(line));

	lhs.getline(line, 150, ',');
	rhs.setProgram(line);

	lhs.getline(line, 150, '\n');
	rhs.setLevel(line);

	return lhs;
}


//overloaded stream insertion operator for writing data to master.txt
std::fstream & operator<<(std::fstream &lhs, Data &rhs)
{
	lhs << rhs.getRecordNumber() << ",";
	lhs << rhs.getIdNumber() << ",";
	lhs << rhs.getName() << ",";
	lhs << rhs.getEmail() << ",";
	lhs << rhs.getUnits() << ",";
	lhs << rhs.getProgram() << ",";
	lhs << rhs.getLevel() << std::endl;

	return lhs;
}