#include "Commands.h"
#include"Constants.h"


int Commands::printHeading()
{
	int choice;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "           Welcome to the diary of the traveler!           " << std::endl;
	std::cout << "------------------------- Options --------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Press 1 to register " << std::endl;
	std::cout << "Press 2 to log in" << std::endl;
	std::cout << "Press 3 to exit" << std::endl;
	std::cout << "Enter your choice here: ";
	do
	{
		std::cin >> choice;
		if (choice != REGISTER && choice != LOG_IN && choice != EXIT)
			std::cout << "Please select one of the available options above and try again!";
	} while (choice != REGISTER && choice != LOG_IN && choice != EXIT);
	system("CLS");

	std::cout << "Thank you! Your choice has been recorded." << std::endl;
	return choice;
	system("CLS");
}

int Commands::getCommand() const
{
	return command;
}

int Commands::searchDestination()
{
	int choice;
	std::cout << "Press 4 to search reviews for your desired destination. " << std::endl;
	std::cout << "Press 3 to exit" << std::endl;
	std::cout << "Enter your choice here: ";
	do
	{
		std::cin >> choice;
		if (choice != DESTINATION && choice != EXIT)
			std::cout << "Please select one of the available options above and try again!";
	} while (choice != DESTINATION && choice != EXIT);

	std::cout << "Thank you! Your choice has been recorded.";
	return choice;
	system("CLS");
}

