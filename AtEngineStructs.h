/*-----------------------------------
  AtEngineStructs.h
  Author: Ayman Taha
  Description: This header file defines the structs used in the AtEngine library.
-----------------------------------*/

#pragma once

#include <iostream>
using namespace std;

namespace AtEngineStructs {
    // 1. Struct to store full name information
    /**
     * @brief Struct to store full name information.
     * Contains first name, last name, and age.
     */
    struct stFullName 
    {
        string firstName;  ///< The first name of the person
        string lastName;   ///< The last name of the person
        short age;         ///< The age of the person
    };

    // 2. Struct to store task duration information
    /**
     * @brief Struct to store task duration information.
     * Contains the number of days, hours, minutes, and seconds.
     */
    struct stTaskDuration
    {
        int numberOfDays;    ///< The number of days
        int numberOfHours;   ///< The number of hours
        int numberOfMinutes; ///< The number of minutes
        int numberOfSeconds; ///< The number of seconds
    };      
}
