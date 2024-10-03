#pragma once

#include<iosfwd>
#include <string>
#include <vector>
#include "AtEngineEnumFuncs.h"
#include "AtEngineStructFuncs.h"


using namespace std;

namespace AtEngine
{
    // 1. Reads a positive number from the user
    /**
     * @brief Reads a positive number from the user.
     * @param Message The message to display to the user.
     * @return The positive number entered by the user.
     */
    int readPositiveNumber(const string& Message = "Please enter a positive number?") {
        int Number;
        cout << Message << endl;
        cin >> Number;
        while (Number < 1 || cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a positive number: " << endl;
            cin >> Number;
        }
        return Number;
    }

    // 2. Reads a number from the user with a custom message
    /**
     * @brief Reads a number from the user with a custom message.
     * @param message The message to display to the user.
     * @return The number entered by the user.
     */
    int readNumber(const string& message) {
        int Number;
        cout << message << endl;
        cin >> Number;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a valid one: " << endl;
            cin >> Number;
        }
        return Number;
    }

    // 3. Calculates half of the number
    /**
     * @brief Calculates half of the number.
     * @param Num The number to be halved.
     * @return Half of the number as a float.
     */
    float calculateHalfNumber(int Num) {
        return (float)Num / 2;
    }

    // 4. Swaps the values of two integers
    /**
     * @brief Swaps the values of two integers.
     * @param a The first integer to be swapped.
     * @param b The second integer to be swapped.
    */
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // 5. Validates if a number is within a specified range
    /**
     * @brief Validates if a number is within a specified range.
     * @param Number The number to be validated.
     * @param From The start of the range.
     * @param To The end of the range.
     * @return True if the number is within the range, false otherwise.
     */
    bool validateNumberInRange(int number, int from, int to) {
        return (number >= from && number <= to);
    }

    // 6. Reads a number from user input until it is within a specified range
    /**
     * @brief Reads a number from user input until it is within a specified range.
     * @param message The message to display to the user.
     * @param from The minimum acceptable value.
     * @param to The maximum acceptable value.
     * @return The number entered by the user that falls within the specified range.
     */
    int readUntilNumberInRange(const string& message, int from, int to) {
        int number = 0;
        do {
            number = readNumber(message + " " + to_string(from) + " to " + to_string(to));
        } while (!validateNumberInRange(number, from, to));

        return number;
    }

    // 7. Prints numbers from 1 to N
    /**
     * @brief Prints numbers from 1 to N.
     * @param N The maximum number to print.
     */
    void printRangeFrom1toN(int n) {
        cout << "Range printed using For Statement:\n";
        for (int counter = 1; counter <= n; counter++) {
            cout << counter << endl;
        }
    }

    // 8. Prints numbers from N to 1 using For statement
    /**
     * @brief Prints numbers from N to 1 using For statement.
     * @param N The starting number to print.
     */
    void printRangeFromNto1(int n) {
        cout << "Range printed using For Statement:\n";
        for (int counter = n; counter >= 1; counter--) {
            cout << counter << endl;
        }
    }

    // 9. Validates the range and the values
    /**
     * @brief Validates the range and the values.
     *
     * This function checks if the range is valid and if the values are within the integer limits.
     *
     * @param start The starting value of the range.
     * @param finish The ending value of the range.
     * @return true if the values are valid, false otherwise.
     *
     * @note This is function number 26 in the library.
     */
    bool validateRange(int start, int finish) {
        // Validate input
        if (finish < start) {
            cout << "Invalid range: finish should be greater than or equal to start for ascending order, or vice versa for descending order.\n";
            return false;
        }

        // Check if values are within valid integer range
        if (std::numeric_limits<int>::min() > start || start > std::numeric_limits<int>::max() ||
            std::numeric_limits<int>::min() > finish || finish > std::numeric_limits<int>::max()) {
            cout << "Input values are outside the valid range of integers.\n";
            return false;
        }

        return true;
    }

    // 10. Prints a range of numbers in ascending or descending order with a specific number type
    /**
    * @brief Prints a range of numbers in ascending or descending order with a specific number type.
    * @param start The starting number to print. Defaults to 1.
    * @param finish The ending number to print.
    * @param ascending If true, prints numbers in ascending order; otherwise, prints in descending order. Defaults to true.
    * @param numberParityIncludeAll Specifies if all numbers, odd numbers, or even numbers should be printed. Defaults to All.
    *
    * @details This function prints numbers from the specified `start` to `finish` in either ascending or descending order,
    * based on the `ascending` parameter. The `numberParityIncludeAll` parameter determines which type of numbers are printed:
    * - `All` prints all numbers in the range.
    * - `Odd` prints only odd numbers.
    * - `Even` prints only even numbers.
    *
    * @note This function handles invalid ranges by printing an error message and returning without printing any numbers.
    */
    void printNumberRange(int start, int finish, bool ascending = true, AtEngineEnums::enNumberParityIncludeAll numberParityIncludeAll = AtEngineEnums::enNumberParityIncludeAll::ALL) {

        // Validate the range
        if (!validateRange(start, finish)) {
            return; // Exit if validation fails
        }

        cout << "Range printed :\n";

        // Print header based on type
        switch (numberParityIncludeAll) {
        case AtEngineEnums::enNumberParityIncludeAll::ALL:
            cout << "All numbers:\n";
            break;
        case AtEngineEnums::enNumberParityIncludeAll::ODD:
            cout << "Odd numbers:\n";
            break;
        case AtEngineEnums::enNumberParityIncludeAll::EVEN:
            cout << "Even numbers:\n";
            break;
        }

        if (ascending) {
            for (int counter = start; counter <= finish; counter++) {
                if  (numberParityIncludeAll  == AtEngineEnums::enNumberParityIncludeAll::ALL ||
                    (numberParityIncludeAll  == AtEngineEnums::enNumberParityIncludeAll::ODD && counter % 2 != 0) ||
                    (numberParityIncludeAll  == AtEngineEnums::enNumberParityIncludeAll::EVEN && counter % 2 == 0)) {
                    cout << counter << endl;
                }
            }
        }
        else {
            for (int counter = finish; counter >= start; counter--) {
                if  (numberParityIncludeAll  == AtEngineEnums::enNumberParityIncludeAll::ALL ||
                    (numberParityIncludeAll  == AtEngineEnums::enNumberParityIncludeAll::ODD && counter % 2 != 0) ||
                    (numberParityIncludeAll  == AtEngineEnums::enNumberParityIncludeAll::EVEN && counter % 2 == 0)) {
                    cout << counter << endl;
                }
            }
        }
    }
    
    // 11. Sums the odd numbers from 1 to N
    /**
    * @brief Sums the odd numbers from 1 to N.
    * @param n The upper bound of the range.
    * @return The sum of odd numbers from 1 to N.
    */
    int sumOddNumbersFrom1toN(int n) {
        int Sum = 0;
        cout << "Sum odd numbers:\n";
        for (int counter = 1; counter <= n; counter++) {
            if (AtEngineEnumFuncs::checkNumberParity(counter) == AtEngineEnums::enNumberParity::ODD) {
                Sum += counter;
            }
        }
        return Sum;
    }

    // 12. Sums the even numbers from 1 to N
    /**
    * @brief Sums the even numbers from 1 to N.
    * @param n The upper bound of the range.
    * @return The sum of even numbers from 1 to N.
    */
    int sumEvenNumbersFrom1toN(int n) {
        int Sum = 0;
        cout << "Sum even numbers:\n";
        for (int counter = 1; counter <= n; counter++) {
            if (AtEngineEnumFuncs::checkNumberParity(counter) == AtEngineEnums::enNumberParity::EVEN) {
                Sum += counter;
            }
        }
        return Sum;
    }

    // 13. Calculates the factorial of N
    /**
    * @brief Calculates the factorial of N.
    * @param N The number to calculate the factorial for.
    * @return The factorial of N.
    */
    int Factorial(int N) {
        int F = 1;
        for (int Counter = N; Counter >= 1; Counter--) {
            F *= Counter;
        }
        return F;
    }

    // 14. Calculates the power of a number raised to a specified exponent
    /**
     * @brief Calculates the power of a number raised to a specified exponent.
     * @param number The base number.
     * @param m The exponent to which the base number is raised.
     * @return The result of raising the base number to the power of the exponent.
     */
    int calculatePowerOfM(int number, int m) {
        if (m == 0) {
            return 1;
        }

        int power = 1;
        for (int i = 0; i < m; i++) {
            power *= number;
        }
        return power;
    }

    // 15. Reads an integer from user input within a specified range
    /**
     * @brief Reads an integer from user input until it is within a specified range.
     * @param from The minimum acceptable value.
     * @param to The maximum acceptable value.
     * @return The number entered by the user that falls within the specified range.
     */
    int readIntegerOfRange(int from, int to) {
        int number;
        while (true) {
            cout << "Please enter an integer between " << from << " and " << to << ": ";
            cin >> number;

            // Check if the input is valid
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter a valid integer." << endl;
                continue;
            }

            // Check if the number is within the range
            if (number < from || number > to) {
                cout << "Number out of range. Please enter an integer between " << from << " and " << to << "." << endl;
            }
            else {
                break;
            }
        }
        return number;
    }

    // 16. Reads a float from the user with a custom message
    /**
     * @brief Reads a float from the user with a custom message.
     * @param message The message to display to the user.
     * @return The float entered by the user.
     */
    float readNumberFloat(const string& message) {
        float number;
        cout << message << endl;
        cin >> number;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Number, Enter a valid one: " << endl;
            cin >> number;
        }
        return number;
    }

    // 17. Calculates the total task duration in seconds using user input
    /**
     * @brief Calculates the total task duration in seconds using user input.
     * @return The total duration in seconds based on user input.
     */
    int taskDurationInSeconds()
    {
        AtEngineStructs::stTaskDuration taskDuration = AtEngineStructFuncs::getTaskDurationInput();

        int durationInSeconds = 0;
        durationInSeconds = taskDuration.numberOfDays * 24 * 60 * 60;
        durationInSeconds += taskDuration.numberOfHours * 60 * 60;
        durationInSeconds += taskDuration.numberOfMinutes * 60;
        durationInSeconds += taskDuration.numberOfSeconds;

        return durationInSeconds;
    }

    // 18. Calculates the total task duration in seconds using provided data
    /**
     * @brief Calculates the total task duration in seconds using provided data.
     * @param taskDuration The stTaskDuration struct containing days, hours, minutes, and seconds.
     * @return The total duration in seconds based on the provided data.
     */
    int taskDurationInSeconds(AtEngineStructs::stTaskDuration taskDuration)
    {
        int durationInSeconds = 0;
        durationInSeconds = taskDuration.numberOfDays * 24 * 60 * 60;
        durationInSeconds += taskDuration.numberOfHours * 60 * 60;
        durationInSeconds += taskDuration.numberOfMinutes * 60;
        durationInSeconds += taskDuration.numberOfSeconds;

        return durationInSeconds;
    }

    // 19. Function to print the details of a task duration with a custom delimiter
    /**
     * @brief Prints the task duration details in the format: days:hours:minutes:seconds.
     * Allows customization of the delimiter between the time components.
     * @param taskDuration The stTaskDuration struct containing days, hours, minutes, and seconds.
     * @param delimiter The character to separate days, hours, minutes, and seconds (default is ':').
     */
    void printTaskDurationDetails(AtEngineStructs::stTaskDuration taskDuration, char delimiter = ':')
    {
        cout << "\n";
        cout << taskDuration.numberOfDays << delimiter
            << taskDuration.numberOfHours << delimiter
            << taskDuration.numberOfMinutes << delimiter
            << taskDuration.numberOfSeconds << "\n";
    }

    // 20. Function to return the name of the day of the week
    /**
     * @brief Returns the name of the day of the week based on the provided enDayOfWeek enum value.
     * @param day The enDayOfWeek enum value representing the day of the week.
     * @return A string representing the name of the day (e.g., "Sunday", "Monday").
     */
    string getDayOfWeek(AtEngineEnums::enDayOfWeek day)
    {
        switch (day)
        {
        case AtEngineEnums::enDayOfWeek::SUNDAY:
            return "Sunday";
        case AtEngineEnums::enDayOfWeek::MONDAY:
            return "Monday";
        case AtEngineEnums::enDayOfWeek::TUESDAY:
            return "Tuesday";
        case AtEngineEnums::enDayOfWeek::WEDNESDAY:
            return "Wednesday";
        case AtEngineEnums::enDayOfWeek::THURSDAY:
            return "Thursday";
        case AtEngineEnums::enDayOfWeek::FRIDAY:
            return "Friday";
        case AtEngineEnums::enDayOfWeek::SATURDAY:
            return "Saturday ";
        default:
            return "Not a valid Day";
        }
    }

    // 21. Function to return the name of the month of the year
    /**
     * @brief Returns the name of the month of the year based on the provided enMonthOfYear enum value.
     * @param month The enMonthOfYear enum value representing the month of the year.
     * @return A string representing the name of the month (e.g., "January", "February").
     */
    string getMonthOfYear(AtEngineEnums::enMonthOfYear month)
    {
        switch (month)
        {
        case AtEngineEnums::enMonthOfYear::JANUARY:
            return "January";
        case AtEngineEnums::enMonthOfYear::FEBRUARY:
            return "February";
        case AtEngineEnums::enMonthOfYear::MARCH:
            return "March";
        case AtEngineEnums::enMonthOfYear::APRIL:
            return "April";
        case AtEngineEnums::enMonthOfYear::MAY:
            return "May";
        case AtEngineEnums::enMonthOfYear::JUNE:
            return "June";
        case AtEngineEnums::enMonthOfYear::JULY:
            return "July";
        case AtEngineEnums::enMonthOfYear::AUGUST:
            return "August";
        case AtEngineEnums::enMonthOfYear::SEPTEMBER:
            return "September";
        case AtEngineEnums::enMonthOfYear::OCTOBER:
            return "October";
        case AtEngineEnums::enMonthOfYear::NOVEMBER:
            return "November";
        case AtEngineEnums::enMonthOfYear::DECEMBER:
            return "December";
        default:
            return "Not a vaild Month";
        }
    }

    // 22. Prints a range of prime numbers in ascending or descending order with a specific number type
    /**
     * @brief Prints a range of prime numbers in ascending or descending order with a specific number type.
     * @param start The starting number to print. Defaults to 1.
     * @param finish The ending number to print.
     * @param ascending If true, prints numbers in ascending order; otherwise, prints in descending order. Defaults to true.
     * @param numberParityIncludeAll Specifies if all prime numbers, odd prime numbers, or even prime numbers should be printed. Defaults to All.
     *
     * @details This function prints prime numbers from the specified `start` to `finish` in either ascending or descending order,
     * based on the `ascending` parameter. The `numberParityIncludeAll` parameter determines which type of prime numbers are printed:
     * - `ALL` prints all prime numbers in the range.
     * - `ODD` prints only odd prime numbers.
     * - `EVEN` prints only even prime numbers.
     *
     * @note This function handles invalid ranges by printing an error message and returning without printing any numbers.
     */
    void printPrimeNumberInRange(int start, int finish, bool ascending = true, AtEngineEnums::enNumberParityIncludeAll numberParityIncludeAll = AtEngineEnums::enNumberParityIncludeAll::ALL)
    {
        // Validate the range
        if (!validateRange(start, finish)) {
            return; // Exit if validation fails
        }

        // Print header based on type
        switch (numberParityIncludeAll) {
        case AtEngineEnums::enNumberParityIncludeAll::ALL:
            cout << "All prime numbers:\n";
            break;
        case AtEngineEnums::enNumberParityIncludeAll::ODD:
            cout << "Odd prime numbers:\n";
            break;
        case AtEngineEnums::enNumberParityIncludeAll::EVEN:
            cout << "Even prime numbers:\n";
            break;
        }

        // Helper lambda for printing if number is prime and matches the parity condition
        auto printIfPrimeAndValidParity = [&](int num) {
            if (AtEngineEnumFuncs::checkPrime(num) == AtEngineEnums::enNumberPrimeStatus::PRIME) {
                if (numberParityIncludeAll == AtEngineEnums::enNumberParityIncludeAll::ALL ||
                    (numberParityIncludeAll == AtEngineEnums::enNumberParityIncludeAll::ODD && num % 2 != 0) ||
                    (numberParityIncludeAll == AtEngineEnums::enNumberParityIncludeAll::EVEN && num == 2)) {
                    cout << num << endl;
                }
            }
            };

        // Ascending or descending order
        if (ascending) {
            for (int counter = start; counter <= finish; counter++) {
                printIfPrimeAndValidParity(counter);
            }
        }
        else {
            for (int counter = finish; counter >= start; counter--) {
                printIfPrimeAndValidParity(counter);
            }
        }
    }

    // 23. Check if a number is perfect
    /**
     * @brief Determines if a given number is a perfect number by using the perfectNumberStatus function.
     *
     * A perfect number is a positive integer that is equal to the sum of its proper positive divisors.
     * This function calls the perfectNumberStatus function to determine if the number is perfect.
     *
     * @param number The number to check.
     * @return true if the number is perfect, false otherwise.
     *
     * @note This function relies on the perfectNumberStatus function to determine the result.
     *       It returns true if the status is PERFECT and false otherwise.
     */
    bool isPerfectNumber(int number) {
        return AtEngineEnumFuncs::perfectNumberStatus(number) == AtEngineEnums::enPerfectNumberStatus::PERFECT;
    }

    // 23. Prints all perfect numbers within a specified range.
    /**
     * @brief Prints all perfect numbers within a specified range.
     *
     * This function iterates through numbers from 'start' to 'finish' and prints those that are perfect numbers.
     *
     * @param start The starting value of the range (inclusive).
     * @param finish The ending value of the range (inclusive).
     */
    void printAllPerfectNumberInRange(int start, int finish) {
        if (!validateRange(start, finish)) {
            return; // Exit if validation fails
        }

        if (start <= 0) start = 1; // Ensure the starting value is positive

        for (int i = start; i <= finish; i++) {
            if (i > 1 && AtEngine::isPerfectNumber(i)) { // Ignore 1, as it's not a perfect number
                cout << i << endl;
            }
        }
    }

    // 24. Prints the digits of a number in reverse order.
    /**
     * @brief Prints the digits of a number in reverse order.
     * This function takes an integer and prints each digit in reverse order, starting from the last digit.
     * @param number The integer whose digits will be printed in reverse order.
     */
    void printDigitsInReverseOrder(int number)
    {
        int lastDigit = 0;
        while (number > 0)
        {
            lastDigit = number % 10;
            number = number / 10;
            cout << lastDigit << endl;
        }
    }

    // 25. Computes the sum of the digits of a number.
    /**
     * @brief Computes the sum of the digits of a number.
     *
     * This function takes an integer and calculates the sum of its digits.
     * @param number The integer whose digits will be summed.
     * @return The sum of the digits of the given number.
     */
    int sumOfDigits(int number)
    {
        int sum = 0, lastDigit = 0;
        while (number > 0)
        {
            lastDigit = number % 10;
            number = number / 10;
            sum += lastDigit;
        }
        return sum;
    }

    // 26. Reverses the digits of a number.
    /**
     * @brief Reverses the digits of a number.
     * This function takes an integer and reverses its digits. It extracts each digit from the original number
     * @param number The integer whose digits will be reversed.
     * @return The reversed number with digits in reverse order.
     */
    int reverseNumber(int number)
    {
        int remainder = 0, reversedNumber = 0;
        while (number > 0)
        {
            remainder = number % 10;
            number /= 10;
            reversedNumber = reversedNumber * 10 + remainder;
        }
        return reversedNumber;
    }

    // 27. Counts the frequency of a specific digit in a number.
    /**
     * @brief Counts the frequency of a specific digit in a number.
     * @param DigitToCheck The digit whose frequency is to be counted.
     * @param Number The integer in which the frequency of the digit is to be counted.
     * @return The frequency of the specified digit within the given number.
     */
    int CountDigitFrequency(short DigitToCheck, int Number)
    {
        int FreqCount = 0, Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            if (DigitToCheck == Remainder)
            {
                FreqCount++;
            }
        }
        return FreqCount;
    }

    // 28. Prints the frequency of all digits in a number.
    /**
     * @brief Prints the frequency of each digit (0-9) in the given number.
     * @param number The integer whose digit frequencies are to be printed.
     */
    void printAllDigitFrequency(int number)
    {
        for (int i = 0; i < 10; i++)
        {
            int frequency = AtEngine::CountDigitFrequency(i, number);
            if (frequency > 0)
            {
                cout << "Digit " << i << " Frequency is " << frequency
                    << " " << (frequency == 1 ? "Time" : "Times") << ".\n";
            }
        }
    }

    // 29. Returns the number in its original order.
    /**
     * @brief Returns the digits of the number in the same order as they appear.
     * @param number The integer whose digits are to be returned in the original order.
     * @return The number with digits in the original order.
     */
    int getNumberInOrder(int number)
    {
        return AtEngine::reverseNumber(AtEngine::reverseNumber(number));
    }

    // 31. Check if a number is a palindrome (boolean)
    /**
     * @brief Determines if a number is a palindrome.
     * A palindrome is a number that reads the same forwards and backwards.
     * This function uses the palindromeNumberStatus function to check if the number is a palindrome.
     * @param number The number to check.
     * @return true if the number is a palindrome, false otherwise.
     * @note This function simply calls palindromeNumberStatus and compares the result
       to enPalindromeNumberStatus::PALINDROME to determine if the number is a palindrome.
     */
    bool IsPalindromeNumber(int number)
    {
        return AtEngineEnumFuncs::palindromeNumberStatus(number) == AtEngineEnums::enPalindromeNumberStatus::PALINDROME;
    }

    // 32. Checks if the number is positive and prints an error message if not.
    /**
     * @brief Checks if the given number is positive and prints an error message if the number is not positive.
     * @param number The number to be checked.
     * @return true if the number is positive, false otherwise.
     *
     * If the number is not positive, it prints an error message to the console.
     */
    bool isPositive(int number)
    {
        if (number > 0)
        {
            return true;
        }
        else
        {
            cout << "Error: The number " << number << " is not positive." << endl;
            return false;
        }
    }

    // 33. Function to print a pattern of symbols or numbers in either normal or inverted order.
    /**
     * Function to print a pattern of symbols or numbers in either normal or inverted order.
     *
     * @param number: The number of rows in the pattern (must be positive).
     * @param isNumber: If true, the pattern will display numbers; if false, it will display symbols (default is true).
     * @param symbol: The symbol to display in the pattern if isNumber is false (default is '*').
     * @param inverted: If true, an inverted pattern is printed, otherwise a normal pattern is printed (default is false).
     */
    void invertedPattern(int number, bool isNumber = true, char symbol = '*', bool isInverted = true)
    {
        if (!isPositive(number)) return;

        if (isInverted)
        {
            for (int i = number; i >= 1; i--) 
            {
                for (int j = i; j >= 1; j--)  
                {
                    // If isNumber is true, print the number, otherwise print the symbol
                    if (!isNumber)
                        cout << symbol;
                    else
                        cout << i;
                }
                cout << endl; 
            }
        }
        // Otherwise, print a regular (non-inverted) pattern
        else
        {
            for (int i = 1; i <= number; i++)  
            {
                for (int j = 1; j <= i; j++)  
                {
                    if (!isNumber)
                        cout << symbol;
                    else
                        cout << i;
                }
                cout << endl;  
            }
        }
    }

    // 34. Function to print an inverted pattern of uppercase letters based on the input number.
    /**
     * Function to print an inverted pattern of letters based on the input number.
     *
     * @param number: The number of letters to print (should be between 1 and 26).
     * @param isUpperCase: If true, prints uppercase letters; if false, prints lowercase letters.
     * @param isInverted: If true, prints the pattern in inverted order; if false, prints in normal order.
     */
    void invertedLetter(int number, bool isUpperCase = true, bool isInverted = true) {

        // Validate that the number is within the allowed range (1-26)
        if (!AtEngine::validateNumberInRange(number, 1, 26)) {
            cout << "Error: The number " << number << " must be between 1 and 26 to represent a valid letter." << endl;
            return;
        }

        // Define constants for ASCII values of uppercase and lowercase letters
        const short UPPER_CASE_START = 65;  // ASCII for 'A'
        const short LOWER_CASE_START = 97;  // ASCII for 'a'

        // Determine the ASCII starting point based on isUpperCase
        short AsciiCaseStart = isUpperCase ? UPPER_CASE_START : LOWER_CASE_START;

        if (isInverted) {
           
            for (int i = (AsciiCaseStart + number - 1); i >= AsciiCaseStart; i--) {
                
                for (int j = 1; j <= number - (AsciiCaseStart + number - 1 - i); j++) {
                    cout << char(i);  
                }
                cout << endl;  
            }
        }
        else {
       
            for (int i = AsciiCaseStart; i < AsciiCaseStart + number; i++) {
        
                for (int j = 1; j <= (i - AsciiCaseStart + 1); j++) {
                    cout << char(i); 
                }
                cout << endl; 
            }
        }
    }

    // 35. Gets text input from the user
    /**
     * @brief Prompts the user to enter text and returns the entered string.
     * @param prompt The message to display to the user.
     * @return The string entered by the user.
     */
    string getUserInputText(string prompt = "Please enter text:") {
        string inputText;  
        cout << prompt + "\n";  
        getline(cin, inputText);  
        return inputText;  
    }

    // 36. Encrypts a string using a given key
    /**
     * @brief Encrypts the provided text using the given encryption key.
     * @param text The text to be encrypted.
     * @param Encryptionkey The key used to modify each character in the string.
     * @return The encrypted text.
     */
    string encryption(string text, short encryptionkey) {

        for (int i = 0; i < text.length(); i++) {
            text[i] = char((int)text[i] + encryptionkey);  // Modify each character by adding the encryption key
        }

        return text;  // Return the encrypted string
    };

    // 37. Decrypts a string using a given key
    /**
     * @brief Decrypts the provided text using the given encryption key.
     * @param text The text to be decrypted.
     * @param Encryptionkey The key used to revert each character in the string to its original state.
     * @return The decrypted text.
     */
    string decryption(string text, short encryptionkey) {

        for (int i = 0; i < text.length(); i++) {
            text[i] = char((int)text[i] - encryptionkey);  // Modify each character by subtracting the encryption key
        }

        return text;  // Return the decrypted string
    };

    // 38. Validates a range with a simple check
    /**
     * @brief Checks if the to value is greater than or equal to the from value.
     * @param from The from value of the range.
     * @param to The to value of the range.
     * @return true if the range is valid; false otherwise.
     */
    bool simpleValidateRange(int from, int to) {
        // Validate the range
        if (to < from) {
            cout << "Error: The to value (" << to << ") must be greater than or equal to the from value (" << from << ")." << endl;
            return false;
        }
        return true; // Range is valid
    }

    // 39. Generates a random number within a specified range
    /**
     * @brief Generates a random number between the specified range [from, to].
     * @param from The lower bound of the range.
     * @param to The upper bound of the range.
     * @return A random integer between from and to, or -1 if the range is invalid.
     *
     * Note: Call srand((unsigned)time(NULL)); in main() to seed the random number generator
     * before using this function, ensuring different random numbers on each execution.
     *
     * Note: Include <cstdlib> to use this function as it is required for rand and srand.
     */
    int randomNumber(int from, int to) {

        // Validate the range
        if (!AtEngine::simpleValidateRange(from, to)) {
            cout << "Error: Invalid range. Ensure that 'to' is greater than or equal to 'from'." << endl;
            return -1;  // Return -1 to indicate an error
        }

        // Generate a random number between from and to
        int randomNum = rand() % (to - from + 1) + from;
        return randomNum;
    }

    // 40. Generates a random character based on the specified character type
     /**
      * @brief Generates a random character based on the specified character type.
      * @param charType The character type, can be LOWERCASE, UPPERCASE, SPECIAL_CHARACTER, or DIGIT.
      * @return A random character of the specified type.
      *
      * Note: The function generates characters within specific ASCII ranges:
      * LOWERCASE: 'a' to 'z' (ASCII 97-122)
      * UPPERCASE: 'A' to 'Z' (ASCII 65-90)
      * SPECIAL_CHARACTER: Symbols like !, @, # (ASCII 33-47)
      * DIGIT: '0' to '9' (ASCII 48-57)
      *
      * Note: Include <cstdlib> and ensure srand((unsigned)time(NULL)); is called to seed the random number generator before using this function.
      */
    char getRandomCharacter(AtEngineEnums::enCharType charType) {

        switch (charType)
        {
        case AtEngineEnums::enCharType::LOWERCASE:
            return char(AtEngine::randomNumber(97, 122));  // Generate a lowercase letter

        case AtEngineEnums::enCharType::UPPERCASE:
            return char(AtEngine::randomNumber(65, 90));   // Generate an uppercase letter

        case AtEngineEnums::enCharType::SPECIAL_CHARACTER:
            return char(AtEngine::randomNumber(33, 47));   // Generate a special character

        case AtEngineEnums::enCharType::DIGIT:
            return char(AtEngine::randomNumber(48, 57));   // Generate a digit

        case AtEngineEnums::enCharType::MIXED:
            // Generate a random choice between lowercase, uppercase, digit, or special character
            switch (AtEngine::randomNumber(1, 4)) {
            case 1:
                return char(AtEngine::randomNumber(97, 122));  // Lowercase letter
            case 2:
                return char(AtEngine::randomNumber(65, 90));   // Uppercase letter
            case 3:
                return char(AtEngine::randomNumber(48, 57));   // Digit
            case 4:
                return char(AtEngine::randomNumber(33, 47));   // Special character
            }

        default:
            cout << "Invalid character type specified.\n";
            return '\0';  // Return null character in case of an error
        }
    }

    // 41. Generates a random string of characters
    /**
     * @brief Generates a random string of characters based on the specified character type.
     * @param numOfCharacters The number of characters to generate.
     * @param charType The type of characters to include (lowercase, uppercase, digits, etc.).
     * @return A string containing the generated characters.
     * Note: Ensure that the numberOfCharacters is a positive integer; otherwise, an empty string will be returned.
     * Note: Include <cstdlib> and ensure srand((unsigned)time(NULL)); is called to seed the random number generator before using this function.
     */
    string generateCharacter(int numOfCharacters, AtEngineEnums::enCharType charType = AtEngineEnums::enCharType::MIXED)
    {
        if (!AtEngine::isPositive(numOfCharacters)) return "";

        string generatedString = "";
        for (int i = 0; i < numOfCharacters; i++)
        {
            generatedString += AtEngine::getRandomCharacter(charType);
        }
        return generatedString;
    }

    // 42. Reads elements into a traditional array
    /**
     * @brief Reads elements into a traditional array.
     * @param arr[] The traditional array to store the elements.
     * @param size The reference to the number of elements to read.
     */
    void inputArray(int arr[], int& size)
    {
        cout << "\nEnter number of elements (max 100):\n";
        cin >> size;

        if (size > 100)
        {
            cout << "Error: The maximum allowed size is 100.\n";
            return;
        }

        cout << "\nEnter array elements:\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Element [" << i + 1 << "] : ";
            cin >> arr[i];
        }
    }

    // 43. Reads elements into a std::vector
    /**
     * @brief Reads elements into a std::vector.
     * @param arr The std::vector to store the elements.
     */
    void inputArray(vector<int>& arr)
    {
        int size;
        cout << "\nEnter number of elements:\n";
        cin >> size;

        arr.resize(size);

        cout << "\nEnter array elements:\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Element [" << i + 1 << "] : ";
            cin >> arr[i];
        }
    }

    //// 44. Reads elements into a dynamically allocated array (pointer)
    ///**
    // * @brief Reads elements into a dynamically allocated array using pointers.
    // * @param arr The pointer to the array.
    // * @param size The reference to the number of elements to read.
    // */
    //void inputArray(int* arr, int& size)
    //{
    //    cout << "\nEnter number of elements:\n";
    //    cin >> size;

    //    cout << "\nEnter array elements:\n";
    //    for (int i = 0; i < size; i++)
    //    {
    //        cout << "Element [" << i + 1 << "] : ";
    //        cin >> arr[i];
    //    }
    //}

    // 45. Prints all elements of an array
    /**
     * @brief Prints all elements of an array.
     * @param arr[] The array of integers to print.
     * @param length The length of the array.
     */
    void printAllArray(int arr[], int length)
    {
        cout << "Original Array: ";

        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";  // Print each element followed by a space
        }
        cout << endl;  // Print a new line at the end
    }

    // 46. Counts how many times a specific number appears in an array
    /**
     * @brief Counts how many times a specific number appears in an array.
     * @param arr[] The array of integers.
     * @param length The length of the array.
     * @param numberCheck The number to check for in the array.
     * @return The count of occurrences of numberCheck in the array.
     */
    int TimesRepeated(int arr[], int length, int numberCheck)
    {
        int count = 0;  // Variable to store the count of occurrences
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == numberCheck)  // Check if the current element matches the number
            {
                count++;  // Increment count if there's a match
            }
        }

        if (count == 0) {
            cout << "The number " << numberCheck << " is not present in the array.\n";
        }

        return count;  // Return the total count of occurrences
    }

    // 47. Fills an array with random numbers
    /**
     * @brief Fills an array with random numbers within a specified range.
     * @param arr[] The array to fill with random numbers.
     * @param size The reference to the number of elements to fill.
     * @param from The lower bound of the random number range.
     * @param to The upper bound of the random number range.
     */
    void fillArrayWithRandomNumbers(int arr[], int& size, int from, int to) {
        cout << "\nEnter number of elements (max 100):\n";
        cin >> size;

        if (size > 100) {
            cout << "Error: The maximum allowed size is 100.\n";
            return;
        }

        if (from >= to) {
            cout << "Error: 'from' must be less than 'to'.\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            arr[i] = AtEngine::randomNumber(from, to);
        }
    }

    // 49. Finds the maximum value in an array
    /**
     * @brief Retrieves the maximum value in an integer array.
     * This function iterates through the provided array and returns the largest element.
     * @param arr The array to search for the maximum value.
     * @param size The size of the array.
     * @return The maximum value in the array.
     */
    int getMaxValueInArray(int arr[], int size) {
        int max = arr[0];

        for (int i = 1; i < size; ++i) {
            // 3. Update max if the current element is greater than max
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        return max;
    }

    // 50. Finds the minimum value in an array
    /**
     * @brief Retrieves the minimum value in an integer array.
     * This function iterates through the provided array and returns the smallest element.
     * @param arr The array to search for the minimum value.
     * @param size The size of the array.
     * @return The minimum value in the array.
     */
    int getMinValueInArray(int arr[], int size) {
        // 1. Initialize min to the first element in the array
        int min = arr[0];

        // 2. Iterate through the array starting from the second element
        for (int i = 1; i < size; ++i) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    // 51. Calculates the sum of elements in an array
    /**
     * @brief Calculates the sum of elements in an integer array.
     *
     * This function iterates through the array and returns the total sum of its elements.
     *
     * @param arr The array of integers to sum.
     * @param arrLength The number of elements in the array.
     * @return The sum of the elements in the array.
     */
    int getSumArray(const int arr[], int arrLength) {
        if (arr == nullptr || arrLength <= 0) {
            return 0; // Return 0 for empty or invalid array
        }

        int sum = 0; // Initialize sum
        for (int i = 0; i < arrLength; i++) {
            sum += arr[i]; // Accumulate the sum
        }
        return sum; 
    }

    // 52. Calculates the average of elements in an array
    /**
     * @brief Calculates the average of elements in an integer array.
     *
     * This function computes the sum of the elements in the array using the getSumArray function
     * and returns the average as a float. It checks for valid array and length to avoid division by zero.
     *
     * @param arr The array of integers to process.
     * @param arrLength The number of elements in the array.
     * @return The average of the elements as a float. Returns 0.0 if the array is empty or invalid.
     */
    float getAverageArray(const int arr[], int arrLength)
    {
        if (arr == nullptr || arrLength <= 0) {
            return 0.0f;  // Return 0 for invalid array or length
        }

        return static_cast<float>(AtEngine::getSumArray(arr, arrLength)) / arrLength;
    }

}
