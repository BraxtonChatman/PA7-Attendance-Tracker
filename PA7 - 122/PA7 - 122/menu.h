#pragma once
#include"List.h"


class Menu {
public:
	void printMenu();
	void mainMenu();

	void importCourseList();
	void loadMasterList();
	void storeMasterList();
	void markAbsences();

	//incomplete function
	void editAbsences();

	void generateReport();


private:
	List<Data> masterList;

};