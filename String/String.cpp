#include "String.h"
#include<iostream>
#include<cstring>

#pragma warning(disable :4996) 

void String::copy(const String& other)
{
	size = other.size;
	string = new char[strlen(other.string) + 1];
	strcpy(string, other.string);

}

void String::free()
{
	delete[]string;
}

String::String()
{

	size = 0;
	string = new char[1];
	string[0] = '\0';
}

String::String(const char* input)
{
	size = strlen(input);
	string = new char[strlen(input) + 1];
	strcpy(string, input);
}

String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

String::~String()
{
	free();
}

size_t String::getSize() const
{
	return size;
}

char* String::getString() const
{
	return string;
}

String& String::operator+=(const String& other)
{
	char* newString = new char[this->size + other.size + 1];
	strcpy(newString, this->string);
	strcat(newString, other.string);

	delete[] string;
	string = newString;
	size = this->size + other.size;
	return *this;
}


std::ostream& operator<<(std::ostream& out, const String& data)
{
	out << data.string;
	return out;
}

std::istream& operator>>(std::istream& in, String& data)
{
	in >> data.string;
	return in;
}

bool operator==(const String& first, const String& second)
{
	return strcmp(first.string, second.string) == 0;
}

bool operator<=(const String& first, const String& second)
{
	return strcmp(first.string, second.string) <= 0;
}

bool operator<(const String& first, const String& second)
{
	return strcmp(first.string, second.string) < 0;
}

String operator+(const String& first, const String& second)
{
	String copy(first);
	copy += second;
	return copy;
}


