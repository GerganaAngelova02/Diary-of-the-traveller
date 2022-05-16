#pragma once
#include <iostream>
#include"Commands.h"
#include"String.h"
#include"DynamicArray.h"
#include"User.h"
#include"Constants.h"
#include"Journey.h"
#include "Dates.h"

class TravellingApp
{
    User currentUser;
    Journey currentJourney;
    Commands commands;

    bool isDigit(char ch);
    bool isLetterC(char ch);
    bool isLetterS(char ch);
    bool isCorrectPhotoName(String name);
    bool isCorrectPhotoFormat(String photo);

    void recordUser() ;
    void recordDestination() ;
    void registration();

    int getFileSize(std::ifstream& file);
    void login();

    void printDestinationInfo();
public:
    void run();
};