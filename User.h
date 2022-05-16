#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include "String.h"
#include"DynamicArray.h"
#include"Journey.h"

class User
{
    String username;
    String email;
    String password;
    DynamicArray<Journey> trips;

    bool isDigit(char ch);
    bool isLetterC(char ch);
    bool isLetterS(char ch);

    bool containsOnlyLetterAndNumbers(String data);
public:
    User() = default;
    User(String username, String email, String password, DynamicArray<Journey> trips);

    void setUsername(String username);
    void setEmail(String email);
    void setPassword(String password);

    String getName()const;
    String getEmail()const;
    String getPassword()const;

    void addJourney(const Journey trip);

    void saveUser() const;//write to file-databse
    void saveJourneys() const; // write to personalbd
};
