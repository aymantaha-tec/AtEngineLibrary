/*-----------------------------------
  AtEngineStructFunctions.h
  Author: Ayman Taha
  Description: This header file contains functions that operate on the structs defined in AtEngineStructs.h.
-----------------------------------*/

#pragma once

#include <iostream>
#include "AtEngineStructs.h"

using namespace std;

// Forward declaration for the AtEngine namespace
namespace AtEngine {

    int readPositiveNumber(const string& Message);
}

namespace AtEngineStructFuncs {

    // 1. Gets user input and fills the stFullName struct
    /**
     * @brief Gets user input and fills the stFullName struct.
     * The function prompts the user to enter their first name, last name, and age.
     * Ensures that the first name and last name are not empty and that the age is greater than 0.
     * @return A stFullName structure containing the user's first name, last name, and age.
     */
    AtEngineStructs::stFullName getFullNameInput() {
        AtEngineStructs::stFullName fullName;

        // Prompt for first name and ensure it's not empty
        do {
            cout << "Enter first Name: ";
            getline(cin, fullName.firstName);
        } while (fullName.firstName.empty());

        // Prompt for last name and ensure it's not empty
        do {
            cout << "Enter last Name: ";
            getline(cin, fullName.lastName);
        } while (fullName.lastName.empty());

        // Prompt for age and ensure it's a positive number
        do {
            cout << "Enter age: ";
            cin >> fullName.age;

            if (cin.fail() || fullName.age <= 0) {
                cin.clear(); // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid age. Please enter a positive number.\n";
            }
        } while (fullName.age <= 0);

        return fullName;
    }

    // 2. Displays the contents of stFullName struct
    /**
     * @brief Displays the contents of stFullName struct.
     * The function prints the first name, last name, and age to the console.
     * @param fullName The stFullName struct to display.
     */
    void displayFullName(const AtEngineStructs::stFullName& fullName) {
        cout << "\nFull Name: " << fullName.firstName << " " << fullName.lastName << "\nAge: " << fullName.age << endl;
         
    }

    // 3. Function to get task duration input from the user
    /**
     * @brief Function to get task duration input from the user.
     * Prompts the user to enter the number of days, hours, minutes, and seconds,
     * and stores these values in a strTaskDuration structure.
     * @return A strTaskDuration structure containing the user input.
     */
    AtEngineStructs::stTaskDuration  getTaskDurationInput()
    {
        AtEngineStructs::stTaskDuration taskDuration;

        taskDuration.numberOfDays = AtEngine::readPositiveNumber("Please enter the number of days: ");
        taskDuration.numberOfHours = AtEngine::readPositiveNumber("Please enter the number of hours: ");
        taskDuration.numberOfMinutes = AtEngine::readPositiveNumber("Please enter the number of minutes: ");
        taskDuration.numberOfSeconds = AtEngine::readPositiveNumber("Please enter the number of seconds: ");

        return taskDuration;
    };
}