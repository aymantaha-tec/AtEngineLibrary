#pragma once

#include<iostream>
using namespace std;

namespace AtEngineEnums
{
    // 1. Days of the Week with Full Names
    /**
     * @brief Represents the days of the week with full names.
     */
    enum class enDayOfWeek
    {
        SUNDAY = 1,    ///< Sunday
        MONDAY,        ///< Monday
        TUESDAY,       ///< Tuesday
        WEDNESDAY,     ///< Wednesday
        THURSDAY,      ///< Thursday
        FRIDAY,        ///< Friday
        SATURDAY       ///< Saturday
    };

    // 2. Days of the Week with Short Names
    /**
     * @brief Represents the days of the week with short names (3-letter abbreviations).
     */
    enum class enDayOfWeekShort
    {
        SUN = 1,    ///< Sunday
        MON,        ///< Monday
        TUE,        ///< Tuesday
        WED,        ///< Wednesday
        THU,        ///< Thursday
        FRI,        ///< Friday
        SAT         ///< Saturday
    };

    // 3. Months of the Year with Full Names
    /**
     * @brief Represents the months of the year with full names.
     */
    enum class enMonthOfYear
    {
        JANUARY = 1,   ///< January
        FEBRUARY,      ///< February
        MARCH,         ///< March
        APRIL,         ///< April
        MAY,           ///< May
        JUNE,          ///< June
        JULY,          ///< July
        AUGUST,        ///< August
        SEPTEMBER,     ///< September
        OCTOBER,       ///< October
        NOVEMBER,      ///< November
        DECEMBER       ///< December
    };

    // 4. Months of the Year with Short Names
    /**
     * @brief Represents the months of the year with short names (3-letter abbreviations).
     */
    enum class enMonthOfYearShort
    {
        JAN = 1,   ///< January
        FEB,       ///< February
        MAR,       ///< March
        APR,       ///< April
        MAY,       ///< May
        JUN,       ///< June
        JUL,       ///< July
        AUG,       ///< August
        SEP,       ///< September
        OCT,       ///< October
        NOV,       ///< November
        DEC        ///< December
    };

    // 5. Positive and Negative Numbers
    /**
     * @brief Represents positive and negative numbers.
     */
    enum class enNumberSign
    {
        POSITIVE = 1, ///< Positive number
        NEGATIVE = -1 ///< Negative number
    };

    // 6. Number Types (Positive, Negative, Zero)
    /**
     * @brief Represents types of numbers (positive, negative, or zero).
     */
    enum class enNumberType
    {
        POSITIVE = 1, ///< Positive number
        NEGATIVE = -1, ///< Negative number
        ZERO = 0      ///< Zero
    };

    // 7. Even and Odd Numbers
    /**
     * @brief Represents even and odd numbers.
     */
    enum class enNumberParity
    {
        EVEN = 1,    ///< Even number
        ODD = 2,     ///< Odd number
    };

    // 8. Even Numbers, Odd Numbers, and All Numbers.
    /**
    * @brief Represents even numbers, odd numbers, and all numbers.
    */
    enum class enNumberParityIncludeAll
    {
        ALL = 0,     ///< All numbers
        EVEN = 1,    ///< Even number
        ODD = 2,     ///< Odd number
    };

    // 9. Prime and Non-Prime Numbers
    /**
     * @brief Represents prime and non-prime numbers.
     */
    enum class enNumberPrimeStatus
    {
        PRIME = 1,   ///< Prime number
        NON_PRIME = 2 ///< Non-prime number
    };

    // 10. Rock, Paper, Scissors Game Choices
    /**
     * @brief Represents the choices in the game Rock, Paper, Scissors.
     */
    enum class enRPSChoice
    {
        ROCK = 1,    ///< Rock
        PAPER,       ///< Paper
        SCISSORS     ///< Scissors
    };

    // 11. Weather Conditions
    /**
     * @brief Represents different weather conditions.
     */
    enum class enWeatherState
    {
        SUNNY = 1,   ///< Sunny weather
        CLOUDY,      ///< Cloudy weather
        RAINY,       ///< Rainy weather
        STORMY,      ///< Stormy weather
        SNOWY        ///< Snowy weather
    };

    // 12. Difficulty Levels
    /**
     * @brief Represents different difficulty levels in a game.
     */
    enum class enDifficultyLevel
    {
        EASY = 1,     ///< Easy difficulty
        MEDIUM,       ///< Medium difficulty
        HARD,         ///< Hard difficulty
        EXPERT        ///< Expert difficulty
    };

    // 13. Pass/Fail enumeration
    /**
     * @brief Represents pass or fail status.
     */
    enum class enPassFail
    {
        PASS = 1,    ///< Pass status
        FAIL = 2     ///< Fail status
    };

    // 14. Operation Types
    /**
     * @brief Represents different types of mathematical operations.
     */
    enum class enOperationType
    {
        ADD = '+',        ///< Addition operation
        SUBTRACT = '-',   ///< Subtraction operation
        MULTIPLY = '*',   ///< Multiplication operation
        DIVIDE = '/'      ///< Division operation
    };

    // 15. Seasons of the Year
     /**
     * @brief Represents the seasons of the year.
     */
    enum class enSeason
    {
        SPRING = 1, ///< Spring season
        SUMMER, ///< Summer season
        AUTUMN, ///< Autumn season
        WINTER  ///< Winter season
    };

     // 16. Time of Day
    /**
     * @brief Represents different times of the day.
     */
    enum class enTimeOfDay
    {
        MORNING = 1,    ///< Morning time (6 AM - 12 PM)
        NOON,       ///< Noon time (12 PM - 3 PM)
        AFTERNOON,  ///< Afternoon time (3 PM - 6 PM)
        EVENING,    ///< Evening time (6 PM - 9 PM)
        NIGHT       ///< Night time (9 PM - 6 AM)
    };

    // 17. Cardinal Directions
    /**
     * @brief Represents the four primary cardinal directions.
     */
    enum class enCardinalDirection {
        NORTH = 1, ///< North
        SOUTH, ///< South
        EAST,  ///< East
        WEST   ///< West
    };

    // 18. Intercardinal Directions
    /**
     * @brief Represents the intercardinal directions.
     */
    enum class enIntercardinalDirection {
        NORTH_EAST = 1,  ///< North-East
        NORTH_WEST,  ///< North-West
        SOUTH_EAST,  ///< South-East
        SOUTH_WEST   ///< South-West
    };

    // 19. All Directions
    /**
     * @brief Represents all possible directions, including cardinal and intercardinal directions.
     */
    enum class enAllDirections {
        NORTH = 1,        ///< North
        SOUTH,        ///< South
        EAST,         ///< East
        WEST,         ///< West
        NORTH_EAST,   ///< North-East
        NORTH_WEST,   ///< North-West
        SOUTH_EAST,   ///< South-East
        SOUTH_WEST    ///< South-West
    };

    // 20. Basic Directions
    /**
     * @brief Represents the basic cardinal directions (Up, Down, Left, Right).
     */
    enum class enBasicDirection {
        UP = 1,    ///< Up
        DOWN,  ///< Down
        LEFT,  ///< Left
        RIGHT  ///< Right
    };

    // 21. File Types
    /**
     * @brief Represents different types of files.
     */
    enum class enFileType {
        TEXT = 1,       ///< Text file
        IMAGE,      ///< Image file
        VIDEO,      ///< Video file
        AUDIO,      ///< Audio file
        COMPRESSED  ///< Compressed file
    };

    // 22. Device States
    /**
     * @brief Represents different states of a device.
     */
    enum class enDeviceState {
        RUNNING = 1,   ///< The device is currently running
        STOPPED,   ///< The device is currently stopped
        SLEEPING   ///< The device is currently in a sleeping mode
    };

    // 24. Gender
    /**
     * @brief Represents gender options.
     */
    enum class enGender {
        MALE = 1,   ///< Male gender
        FEMALE  ///< Female gender
    };

    // 25. Shapes
    /**
     * @brief Represents different geometric shapes.
     */
    enum class enShape {
        CIRCLE = 1,          ///< Circle shape
        SQUARE,          ///< Square shape
        RECTANGLE,       ///< Rectangle shape
        TRIANGLE,        ///< Triangle shape
        RHOMBUS,         ///< Rhombus shape
        PARALLELOGRAM,   ///< Parallelogram shape
        TRAPEZOID,       ///< Trapezoid shape
        POLYGON,         ///< Polygon shape
        ELLIPSE          ///< Ellipse shape
    };

    // 26. Perfect Number Status
    /**
     * @brief Represents whether a number is perfect or not.
     */
    enum class enPerfectNumberStatus
    {
        PERFECT = 1,    ///< Perfect number
        NOT_PERFECT  ///< Not a perfect number
    };
}

