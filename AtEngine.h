#pragma once

#include<iosfwd>
#include <string>
#include "AtEnginEnumFuncs.h"


using namespace std;

namespace AtEngin
{
    // 1. Reads a positive number from the user
    /**
     * @brief Reads a positive number from the user.
     * @param Message The message to display to the user.
     * @return The positive number entered by the user.
     */
    int readPositiveNumber(const string& Message) {
        int Number;
        cout << Message << endl;
        cin >> Number;
        while (Number < 0 || cin.fail()) {
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

    // 9. Prints a range of numbers in ascending or descending order with a specific number type
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

        // Validate input
        if (finish < start) {
            cout << "Invalid range: finish should be greater than or equal to start for ascending order, or vice versa for descending order.\n";
            return;
        }

        // Check if values are within valid integer range
        if (std::numeric_limits<int>::min() > start || start > std::numeric_limits<int>::max() ||
            std::numeric_limits<int>::min() > finish || finish > std::numeric_limits<int>::max()) {
            std::cout << "Input values are outside the valid range of integers.\n";
            return;
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
    
    // 10. Sums the odd numbers from 1 to N
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

    // 11. Sums the even numbers from 1 to N
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

    // 12. Calculates the factorial of N
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

    // 13. Calculates the power of a number raised to a specified exponent
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

    // 14. Reads an integer from user input within a specified range
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

    // 15. Reads a float from the user with a custom message
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

}