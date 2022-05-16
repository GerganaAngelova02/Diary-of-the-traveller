#pragma once

#include<iostream>

class String {
	char* string;
	size_t size;

	void copy(const String& other);
	void free();
public:
	String();
	String(const char* string);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	size_t getSize()const;
	char* getString()const;

	String& operator+=(const String& other);

	friend std::ostream& operator<< (std::ostream& out, const String& data);
	friend std::istream& operator>>(std::istream& in, String& data);

	friend bool operator==(const String& first, const String& second);
	friend bool operator<=(const String& first, const String& second);
	friend bool operator<(const String& first, const String& second);
};

String operator+ (const String& first, const String& second);
