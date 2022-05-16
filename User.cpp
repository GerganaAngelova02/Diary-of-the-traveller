#include "User.h"

bool User::isDigit(char ch)
{
	return '0' <= ch && ch <= '9';
}
bool User::isLetterC(char ch)
{
	return 'A' <= ch && ch <= 'Z';
}
bool User::isLetterS(char ch)
{
	return 'a' <= ch && ch <= 'z';
}
bool User::containsOnlyLetterAndNumbers(String data)
{
	for (int i = 0; i < data.getSize(); i++)
	{
		if (isDigit(data.getString()[i]) || isLetterS(data.getString()[i]) || isLetterC(data.getString()[i]))
			return true;
	}
	return false;
}


User::User(String username, String email, String password, DynamicArray<Journey> trips)
{
	setUsername(username);
	setEmail(email);
	setPassword(password);
	this->trips = trips;
}

void User::setUsername(String username)
{
	if (containsOnlyLetterAndNumbers(username))
		this->username = username;
	else
		std::cout << "Invalid username! The username should contain only letters and numbers.Plase try again." << std::endl;
}

void User::setEmail(String email)
{
	this -> email = email;
}

void User::setPassword(String password)
{
	this->password = password;
}

String User::getName() const
{
	return username;
}

String User::getEmail() const
{
	return email;
}

String User::getPassword() const
{
	return password;
}

void User::addJourney(const Journey trip)
{
	trips.add(trip);
}

void User::saveUser() const
{
	std::ofstream file("database.txt", std::ios::app);
	if (!file.is_open())
	{
		std::cout << "The file can not be opened!" << std::endl;
		return;
	}
	file << getName() << ',' << getPassword() << ',' << getEmail() << "\n";
	file.close();
}

void User::saveJourneys() const
{
	String filename = getName();
	filename += ".db";
	std::ofstream file(filename.getString(), std::ios::app);
	if (!file.is_open())
		std::cout << "The file can not be opened!" << std::endl;
	int tripsCount = trips.getSize();
	for (int i = 0; i < tripsCount; i++)
	{
		file << trips[i].getDestination() << ',' << trips[i].getStart() << ',' << trips[i].getEnd() << ',' << trips[i].getGrade() << ',' << trips[i].getComment() << ',' << trips[i].getPhotos() << '\n';
	}
	file.close();

	std::ofstream usersAndDestFile("all_users_destinations.txt", std::ios::app);
	if (!usersAndDestFile.is_open())
		std::cout << "The file can not be opened!" << std::endl;

	for (int i = 0; i < tripsCount; i++)
	{
		usersAndDestFile << trips[i].getDestination() << ',' << trips[i].getStart() << ',' << trips[i].getEnd() 
			<< ',' << trips[i].getGrade() << ',' << trips[i].getComment() << ',' << trips[i].getPhotos() << '\n';
	}
	usersAndDestFile.close();
}
