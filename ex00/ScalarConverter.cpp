#include "ScalarConverter.hpp"

// Constructor
ScalarConverter::ScalarConverter()
{
    // Initialization
}

// Destructor
ScalarConverter::~ScalarConverter()
{
    // Cleanup
}

// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

// Assignment Operator Overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
    {
        // Free existing resources
        // Copy members from 'other'
    }
    return *this;
}
bool isNumber(const std::string &str)
{
    try
    {
        std::stoi(str);
        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}
bool isFloating(const std::string &str)
{
    try
    {
        std::stod(str);
        return true;
    }
    catch (const std::exception &)
    {
        return false;
    }
}
bool isChar(std::string &str)
{
    return (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]));
}

void printChar(char c)
{
    if (isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non displayable" << c << std::endl;
}

void ScalarConverter::displayTypes(short type, std::string &str)
{
    if (type == T_CHAR)
    {
        char res = str[0];

        std::cout << "char " << res << std::endl;
        std::cout << "int " << static_cast<int>(res)  << std::endl;
        std::cout << "float " << std::fixed << std::setprecision(1) << static_cast<float>(res) << "f" << std::endl;
        std::cout << "double " << std::fixed << std::setprecision(1) << static_cast<double>(res) << std::endl;
    }
    else if (type == T_FLOAT)
    {
        float res = std::stof(str);

        printChar((static_cast<char>(res)));
        std::cout << "int " << static_cast<int>(res) << std::endl;
        std::cout << "float " << res << std::endl;
        std::cout << "double " << std::fixed << std::setprecision(1) << static_cast<double>(res) << std::endl;
    }
    else if (type == T_DOUBLE)
    {
        double res = std::stod(str);

        printChar((static_cast<char>(res)));
        std::cout << "int " << static_cast<int>(res) << std::endl;
        std::cout << "float " << std::fixed << std::setprecision(1) << static_cast<float>(res) << "f" << std::endl;
        std::cout << "double " << res << std::endl;
    }
    else if (type == NOD)
    {
        double res = std::stod(str);

        std::cout << "char: Impossible" << std::endl;
        if (std::isnan(res) || std::isinf(res))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int " << static_cast<int>(res) << std::endl;
        std::cout << "float " << std::fixed << std::setprecision(1) << static_cast<float>(res) << "f" << std::endl;
        std::cout << "double " << res << std::endl;
    }
    else if (type == T_INT)
    {
        int res = std::stoi(str);
        printChar((static_cast<char>(res)));
        std::cout << "int " << res << std::endl;
        std::cout << "float " << std::fixed << std::setprecision(1) << static_cast<float>(res) << "f" << std::endl;
        std::cout << "double " << std::fixed << std::setprecision(1) << static_cast<double>(res) << std::endl;
    }
    else
        std::cout << "Please Enter Valid Input" << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    short types = -1;

    if (isChar(str))
        types = T_CHAR;
    else if (isFloating(str))
    {
        if (str.find('.') != std::string::npos && str.find("f") != std::string::npos)
            types = T_FLOAT;
        else if(str.find('.') != std::string::npos)
            types = T_DOUBLE;
        else if(!isNumber(str))
            types = NOD;
    }
    if (isNumber(str) && types != NOD)
        types = T_INT;
    displayTypes(types, str);
}