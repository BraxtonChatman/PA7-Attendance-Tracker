#include"menu.h"



//Displays menu options
void Menu::printMenu()
{
	std::cout << "1. Import Course List" << std::endl;
	std::cout << "2. Load Master List" << std::endl;
	std::cout << "3. Store MasterList" << std::endl;
	std::cout << "4. Mark Absences" << std::endl;
	std::cout << "5. Edit absences" << std::endl;
	std::cout << "6. Generate Report" << std::endl;
	std::cout << "7. Exit" << std::endl;
}

//calls print menu and prompts selection 
void Menu::mainMenu()
{
	//selection variable
	int selection = 0;

	//loops until exit option is selected
	while (selection != 7)
	{
		system("cls");

		//displays menu
		printMenu();
		std::cout << std::endl;

		//prompts selection
		std::cout << "Please select an option..." << std::endl;
		std::cin >> selection;

		switch (selection) {
		case 1:
			importCourseList();
			std::cout << "Class list imported" << std::endl;
			system("pause");
			break;

		case 2:
			loadMasterList();
			break;

		case 3:
			storeMasterList();
			break;

		case 4:
			markAbsences();
			break;

		case 5:
			editAbsences();
			break;

		case 6:
			generateReport();
			break;

		case 7:
			std::cout << "Exiting Attendance Tracker Application." << std::endl;
			system("pause");
			break;

		default:
			std::cout << "Invalid selection" << std::endl;
			system("pause");
			std::cin.clear();
			std::cin.ignore(20, '\n');
			break;
		}
	}
}

//overwrites masterList with values read in from .csv
void Menu::importCourseList()
{
	//the list has values in it already that need to be overwritten
	if(masterList.getHeadPtr()!=nullptr)
		masterList.~List();

	std::fstream fileStream;
	fileStream.open("classList.csv");

	Data tempData;
	char junkString[100] = "";
	fileStream.getline(junkString, 100, '\n');

	while (!fileStream.eof())
	{
		fileStream >> tempData;
		masterList.insertAtFront(tempData);
	}

	fileStream.close();
}

void Menu::loadMasterList()
{
	std::fstream fileStream;
	fileStream.open("master.txt");

	Data tempData;

	while (!fileStream.eof())
	{
		fileStream >> tempData;
		masterList.insertAtFront(tempData);
	}

	fileStream.close();
}

void Menu::storeMasterList()
{
	std::fstream fileStream;
	fileStream.open("master.txt");

	Node<Data>* pCurrent = masterList.getHeadPtr();

	while (pCurrent != nullptr)
	{
		fileStream << pCurrent->getData();
		
		pCurrent = pCurrent->getNextPtr();
	}

	fileStream.close();
}

void Menu::markAbsences()
{
	Node<Data>* pCurrent = masterList.getHeadPtr();
	char tempChar = '\0';
	int tempInt = 0;
	std::string currentDate = "";

	time_t t = time(0);
	struct tm * now = localtime(&t);

	currentDate.append(std::to_string(now->tm_year + 1900));
	currentDate.append("-");
	currentDate.append(std::to_string(now->tm_mon+1));
	currentDate.append("-");
	currentDate.append(std::to_string(now->tm_mday));

	while (pCurrent != nullptr)
	{
		system("cls");

		std::cout << "Name: " << pCurrent->getData().getName() << std::endl;
		std::cout << "Is student absent? - 1/Y/A absent, 0/N/P present" << std::endl;
		std::cin >> tempChar;

		//invalid character loop
		while (tempChar != '1' && tempChar != 'Y' && tempChar != 'A' && tempChar != '0' && tempChar != 'N' && tempChar != 'P')
		{
			std::cout << "Invalid selection, please enter valid character." << std::endl;
			system("pause");
			std::cin.clear();
			std::cin.ignore(20, '\n');

			std::cin >> tempChar;
		}

		//If student is selected as being absent
		if (tempChar != '0' && tempChar != 'N' && tempChar != 'P')
		{
			pCurrent->getData().getAbsences().push(currentDate);
			pCurrent->getData().setNumberAbsences(1 + pCurrent->getData().getNumAbsences());

		}

		pCurrent = pCurrent->getNextPtr();
	}
}

//incomplete function
void Menu::editAbsences()
{
	std::cout << "Please enter ID number of student whose absence you wish to edit." << std::endl;
	int ID = 0, index = 0;
	std::string date = "";
	bool studentFound = false, dateFound = false;
	std::cin >> ID;

	Node<Data>* pCurrent = masterList.getHeadPtr();

	while (pCurrent != nullptr && !studentFound)
	{
		if (pCurrent->getData().getIdNumber() == ID)
		{
			studentFound = true;
			std::cout << "Please enter date of absence you would like to edit in yyyy-m-dd format" << std::endl;
			std::cin >> date;

			index = 0;
			while (index < pCurrent->getData().getNumAbsences() && !dateFound)
			{
				if (date == pCurrent->getData().getAbsences().peek(index))
					dateFound = true;
				index++;
			}

			if (dateFound)
			{
				--index;
				std::cout << "Please enter date you would like to change it to in yyyy-m-dd format. Enter \"NA\" if you wish to remove the absence" << std::endl;

				std::cin >> date;

				pCurrent->getData().getAbsences().editAbsence(index, date);
			}
			else if (!dateFound)
			{
				std::cout << "Date not found in student's absence record." << std::endl;
				system("pause");
			}
		}

		pCurrent = pCurrent->getNextPtr();

	}
	if (!studentFound)
	{
		std::cout << "Student not found, returning to menu..." << std::endl;
		system("pause");
	}
}

void Menu::generateReport()
{
		//selection prompt
		system("cls");
		std::cout << "1. Generate Report for all students" << std::endl;
		std::cout << "2. Generate report for all students with at least an input number of absences" << std::endl;
		std::cout << "3. Return to menu" << std::endl;

		Node<Data>* pCurrent = masterList.getHeadPtr();
		int selection = 0;
		std::cin >> selection;

		//invalid selection loop
		while (selection != 1 && selection != 2 && selection != 3)
		{
			std::cout << "Invalid input, please select valid option." << std::endl;
			system("pause");
			std::cin.clear();
			std::cin.ignore(20, '\n');
			std::cin >> selection;
		}

		//generate report for all students
		if (selection == 1)
		{
			while (pCurrent != nullptr)
			{
				std::cout << "Name: " << pCurrent->getData().getName() << "," << "Most recent absence: ";
				if (pCurrent->getData().getNumAbsences() == 0)
					std::cout << "NA" << std::endl;
				else
				{
					std::cout << pCurrent->getData().getAbsences().peek() << std::endl;
				}

				pCurrent = pCurrent->getNextPtr();
			}
		}

		//all students missing more than some number of absences
		else if (selection == 2)
		{
			std::cout << "Please enter number you wish to search by:";
			std::cin >> selection;

			while (pCurrent != nullptr)
			{
				if (pCurrent->getData().getNumAbsences() >= selection)
					std::cout << "Name: " << pCurrent->getData().getName() << "," << "Most recent absence: " << pCurrent->getData().getAbsences().peek() << std::endl;

				pCurrent = pCurrent->getNextPtr();
			}
		}

		system("pause");
}


