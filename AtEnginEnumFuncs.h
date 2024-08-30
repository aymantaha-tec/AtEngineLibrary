#pragma once

#include<iostream>
#include "AtEnginEnums.h"

using namespace std;

namespace AtEngineEnumFuncs

{
    // 1. Checks if a number is odd or even
    /**
     * @brief Checks if a number is odd or even.
     * @param Number The number to check.
     * @return enOddOrEven::Odd if the number is odd, enOddOrEven::Even if the number is even.
     */
    AtEngineEnums::enNumberParity checkNumberParity(int Number) {
        if (Number % 2 != 0) {
            return AtEngineEnums::enNumberParity::ODD;
        }
        else {
            return AtEngineEnums::enNumberParity::EVEN;
        }
    };

    // 2. Reads an operation type from the user
    /**
     * @brief Reads an operation type from the user.
     * @return enOperationType corresponding to the operation entered by the user.
     */
    AtEngineEnums::enOperationType readOperationType()
    {
        char ot = '+';
        cout << "Please enter Operation Type (+, -, *, /)?\n";
        cin >> ot;
        return (AtEngineEnums::enOperationType)ot;
    };

    // 5. Checks if a number is prime or non-prime
    /**
     * @brief Checks if a number is prime or non-prime.
     * @param number The number to check.
     * @return enNumberPrimeStatus::PRIME if the number is prime, enNumberPrimeStatus::NON_PRIME if the number is non-prime.
     */
    AtEngineEnums::enNumberPrimeStatus checkPrime(int number)
    {
        if (number <= 1) 
            return AtEngineEnums::enNumberPrimeStatus::NON_PRIME;
       

        int m = round(number / 2);
        for (int counter = 2; counter <= m; counter++)
        {
            if (number % counter == 0)
                return AtEngineEnums::enNumberPrimeStatus::NON_PRIME;
        }
        return AtEngineEnums::enNumberPrimeStatus::PRIME;
    
    };
}