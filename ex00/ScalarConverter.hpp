#pragma once
#include <iostream>
#include <iomanip>
#include <cmath> 
#include <sstream>
#include <climits>

class  ScalarConverter {
private:
    const static short T_CHAR = 0;
    const static short T_FLOAT = 1;
    const static short T_INT = 2;
    const static short T_DOUBLE = 3;
    const static short NOD = 4;
static void    displayTypes(short type, std::string &str);
public:
    // Constructor
     ScalarConverter();

    // Destructor
    ~ScalarConverter();

    // Copy Constructor
     ScalarConverter(const  ScalarConverter& other);

    // Assignment Operator Overload
     ScalarConverter& operator=(const  ScalarConverter& other);
     static void convert(std::string name);
};