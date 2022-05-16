#pragma once
#include <iostream>
#include"String.h"
#include"DynamicArray.h"

class Commands
{
	int command;
public:

	int printHeading();
	int getCommand() const;

	int searchDestination();

};