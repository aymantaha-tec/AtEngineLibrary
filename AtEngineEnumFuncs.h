#pragma once

#include<iostream>
#include "AtEngineEnums.h"

using namespace std;

// Forward declaration for the AtEngine namespace
namespace AtEngine {

    int readIntegerOfRange(int from, int to);
    int reverseNumber(int number);
}

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

    // 3. Checks if a number is prime or non-prime
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

    // 4. Reads a day of the week as an enum value
    /**
     * @brief Reads a day of the week as an enum value.
     * @return enDayOfWeek corresponding to the integer input (1 for Sunday, 7 for Saturday).
     */
    AtEngineEnums::enDayOfWeek readDayOfWeek()
    {
        return (AtEngineEnums::enDayOfWeek) AtEngine::readIntegerOfRange(1, 7);
    }

    // 5. Reads a month of the year as an enum value
    /**
     * @brief Reads a month of the year as an enum value.
     * @return enMonthOfYear corresponding to the integer input (1 for January, 12 for December).
     */
    AtEngineEnums::enMonthOfYear readMonthOfYear()
    {
        return (AtEngineEnums::enMonthOfYear)AtEngine::readIntegerOfRange(1, 12);
    }

    // 6. Check if a number is a perfect number
    /**
     * @brief Determines if a number is perfect.
     * A perfect number is a positive integer that is equal to the sum of its proper positive divisors.
     * This function calculates the sum of divisors of a given number and compares it to the number itself.
     * @param number The number to check.
     * @return enPerfectNumberStatus::PERFECT if the number is perfect,
               enPerfectNumberStatus::NOT_PERFECT otherwise.
     * @note This implementation uses a simple brute-force approach to calculate the sum of divisors.
       For very large numbers, more efficient algorithms could be used.
     */
    AtEngineEnums::enPerfectNumberStatus perfectNumberStatus(int number) {

        if (number <= 0) {
            return AtEngineEnums::enPerfectNumberStatus::NOT_PERFECT; // Negative numbers and zero are not perfect
        }

        int sum = 1; // Start with 1 as it is a divisor for every number

        // Loop from 2 to half of the number (since divisors larger than half the number cannot be valid)
        for (int i = 2; i <= number / 2; ++i) {
            if (number % i == 0) {
                sum += i; // Add the divisor to the sum
            }
        }

        // Early exit if sum exceeds the number
        if (sum > number) {
            return AtEngineEnums::enPerfectNumberStatus::NOT_PERFECT;
        }

        // Final check to determine if the number is perfect
        return (sum == number) ?
            AtEngineEnums::enPerfectNumberStatus::PERFECT :
            AtEngineEnums::enPerfectNumberStatus::NOT_PERFECT;
    }

    // 7. Check if a number is a palindrome
    /**
     * @brief Determines if a number is a palindrome.
     * A palindrome is a number that reads the same forwards and backwards.
     * This function compares the given number with its reversed version to check if it is a palindrome.
     * @param number The number to check.
     * @return enPalindromeNumberStatus::PALINDROME if the number is a palindrome,
               enPalindromeNumberStatus::NOT_PALINDROME otherwise.
     * @note This implementation uses the reverseNumber function to reverse the digits of the number
       and then compares the reversed number to the original.
     */
    AtEngineEnums::enPalindromeNumberStatus palindromeNumberStatus(int number)
    {
       return number == AtEngine::reverseNumber(number) ? AtEngineEnums::enPalindromeNumberStatus::PALINDROME : AtEngineEnums::enPalindromeNumberStatus::NOT_PALINDROME;
    }

}
