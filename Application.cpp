#include "Application.h"
#include"String.h"
#include "Journey.h"
#include<cstring>

#pragma warning(disable :4996) 


void TravellingApp::run()
{
	do
	{
		int choice =commands.printHeading();
		if (choice == REGISTER)
		{
			registration();
		}
		else if (choice == LOG_IN)
			login();
		else if (choice == EXIT)
		{
			std::cout << "Thank you for using the dairy of the traveller!" << std::endl;
		}
			
	} while(commands.getCommand() != EXIT);

}

bool TravellingApp::isDigit(char ch)
{
	return '0' <= ch && ch <= '9';
}
bool TravellingApp::isLetterC(char ch)
{
	return 'A' <= ch && ch <= 'Z';
}
bool TravellingApp::isLetterS(char ch)
{
	return 'a' <= ch && ch <= 'z';
}
bool TravellingApp::isCorrectPhotoName(String name)
{
	for (int i = 0; i < name.getSize(); i++)
	{
		if (isDigit(name.getString()[i]) || isLetterS(name.getString()[i]) 
			|| isLetterC(name.getString()[i]) || name.getString()[i] == '_' || name.getString()[i] == '.')
			return true;
	}
	return false;
}
bool TravellingApp::isCorrectPhotoFormat(String photo)
{
	char extension[4];
	for (int i = photo.getSize()-1; i> photo.getSize()-4; i--)
	{
		for (int j = 3; j > 0; j--)
		{
			extension[j] = photo.getString()[i];
		}
	}
	if (extension == "jpeg")
		return true;
	else if (extension == ".png")
		return true;
}

void TravellingApp::recordUser()
{
	String userName, email, password;

	std::cout << "Please enter your username:";
	std::cin >> userName;
	currentUser.setUsername(userName);
	std::cout << "Please enter your email:";
	std::cin >> email;
	currentUser.setEmail(email);
	std::cout << "Please enter your password:";
	std::cin >> password;
	currentUser.setPassword(password);
	currentUser.saveUser();
}

void TravellingApp::recordDestination()
{
	Journey visit;
	String destination,comment;
	Date beginning, ending;
	int grade;
	String photos;

	int destCount;
	std::cout << "Please enter the number of destinations you would like to share:";
	std::cin >> destCount;

	for (int i = 0; i < destCount; i++)
	{
		std::cout << "Please enter destination number " << i + 1 << " that you have visited:";
		std::cin >> destination;
		visit.setDestination(destination);

		do 
		{
			std::cout << "Please enter the start date of your journey number " << i + 1<< ' ';
			std::cin >> beginning;

			std::cout << "Please enter the end date of your journey number " << i + 1<< ' ';
			std::cin >> ending;

			if (ending < beginning)
				std::cout << "The end date can not be before the start date!Please try againg.";

		} while (ending < beginning);
		visit.setStart(beginning);
		visit.setStart(ending);

		do
		{
			std::cout << "Please enter a rating from 1 to 5 to your journey number " << i + 1<< ' ';
			std::cin >> grade;
		} while (grade<1 && grade>5);
		visit.setGrage(grade);

		std::cout << "Please enter a comment to your journey number " << i + 1<<' ';
		std::cin >> comment;
		visit.setComment(comment);

		do
		{
			std::cout << "Please enter the name of a photo file in .jpeg or .png format  to your journey number " << i + 1;
			std::cin >> photos;
		} while (!isCorrectPhotoName(photos) && !isCorrectPhotoFormat(photos));
		visit.setPhotos(photos);

		currentUser.addJourney(visit);
		currentUser.saveJourneys();
	}
}

void TravellingApp::registration()
{
	recordUser();
	recordDestination();
	std::cout<< "You have successfully created an account!"<< std::endl;
	std::cout << " Please login to your account to be able see the other users' travel experience." << std::endl;
}


int TravellingApp::getFileSize(std::ifstream& file)
{
	int currentPosition = file.tellg();

	file.seekg(0, std::ios::end);
	int result = file.tellg();
	file.seekg(currentPosition);
	return result;
}



void TravellingApp::login()
{
	String entryUserName,entryPassword,recordUserName,recordPassword;
	std::cout << "Please enter your username here:";
	std::cin >> entryUserName;

	std::cout << "Please enter your password here:";
	std::cin >> entryPassword;

	std::ifstream fileUsers("database.txt");
	if (!fileUsers.is_open())
	{
		std::cout << "The file can not be opened!" << std::endl;
		return;
	}
	char line[100];
	bool isLoggedIn = false;
	int hasPassedComma = 0;
	while (!fileUsers.eof())
	{
		fileUsers.getline(line, 100);
		for (int i = 0; i < 101; i++)
		{
			if (line[i] != ',' && hasPassedComma == 0)
				recordUserName.getString()[i] = line[i];
			if (line[i] == ',')
				hasPassedComma++;
			if (line[i] != ',' && hasPassedComma == 1)
				recordPassword.getString()[i] = line[i];
		}
	}
	fileUsers.close();

	if ( entryUserName==recordUserName)
	{
		if (entryPassword==recordPassword)
		{
			isLoggedIn = true;
			std::cout << "Successfully logged in! ";
		}
		else
		{
			isLoggedIn = false;
			std::cout << "Incorrect password! Please try again." << std::endl;
		}
	}
	else
	{
		isLoggedIn = false;
		std::cout << " Username not found! Please try again." << std::endl;
	}
	if (isLoggedIn = true)
	{
		int choice = commands.searchDestination();
		if (choice == DESTINATION)
			printDestinationInfo();
		else if (choice == EXIT)
		{
			std::cout << "Thank you for using the dairy of the traveller!" << std::endl;
		}
	}
}
void TravellingApp::printDestinationInfo()
{
	String place;
	
	std::cout << "Please enter the place you would like to find a review for: ";
	std::cin >> place;


	std::ifstream fileDest("all_users_destinations.txt");
	if (!fileDest.is_open())
	{
		std::cout << "The file can not be opened!" << std::endl;
		return;
	}

	char text[100];

	String destDB;
	while (!fileDest.eof())
	{
		fileDest.getline(text , 100);
		for (int i = 0; i < 21; i++)
		{
			if (text[i] != ',')
			{
				destDB.getString()[i] = text[i];
			}
		}
		if (destDB == place)
		{
			for (int j = 0; j < 101; j++)
				std::cout << text[j];
		}
	}
	fileDest.close();
}
