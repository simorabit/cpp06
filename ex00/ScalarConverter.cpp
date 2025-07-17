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
    std::stringstream ss(str);
    int tmp;
    ss >> tmp;
    return !ss.fail() && ss.eof();
}

bool isFloat(const std::string &str)
{
    std::string copy = str;
    if (!copy.empty() && copy.back() == 'f')
        copy.pop_back();  // remove 'f'

    std::stringstream ss(copy);
    float tmp;
    ss >> tmp;
    return !ss.fail() && ss.eof();
}


float stringToFloat(const std::string &str)
{
    std::string copy = str;

    if(!copy.empty() && copy.back() == 'f')
        copy.pop_back();
    std::stringstream ss(copy);
    float result = 0.0f;
    ss >> result;
    return result;
}
int stringToNumber(const std::string &str)
{
    std::stringstream ss(str);
    int result = 0.0f;
    ss >> result;
    return result;
}
double stringToDouble(const std::string &str)
{
    std::stringstream ss(str);
    double result = 0.0f;
    ss >> result;
    return result;
}
bool isChar(std::string &str)
{
    return (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]));
}

void printChar(char c)
{
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::displayTypes(short type, std::string &str)
{
    if (type == T_CHAR)
    {
        char res = str[0];

        std::cout << "char " << res << std::endl;
        std::cout << "int " << static_cast<int>(res) << std::endl;
        std::cout << "float " << std::fixed << std::setprecision(1) << static_cast<float>(res) << "f" << std::endl;
        std::cout << "double " << std::fixed << std::setprecision(1) << static_cast<double>(res) << std::endl;
    }
    else if (type == T_FLOAT)
    {
        float res = stringToFloat(str);

        if(res >= 0 && res <= 255)
            printChar((static_cast<char>(res)));
        else
            std::cout << "char : Impossible" << std::endl;
        if (!std::isnan(res))
        {
            if (res > INT_MAX || res < INT_MIN)
                std::cout << "int : Impossible" << std::endl;
            else
                std::cout << "int : " << static_cast<int>(res) << std::endl;
        }
        std::cout << "float " << std::fixed << std::setprecision(1) << res << "f"  << std::endl;
        std::cout << "double " << std::fixed << std::setprecision(1) << static_cast<double>(res) << std::endl;
    }
    else if (type == T_DOUBLE)
    {
        double res = stringToDouble(str);

        if (!std::isnan(res))
        {
            if(res >= 0 && res <= 255)
                printChar((static_cast<char>(res)));
            else
                std::cout << "char : Impossible" << std::endl;
            if (res > INT_MAX || res < INT_MIN)
                std::cout << "int : Impossible" << std::endl;
            else
                std::cout << "int : " << static_cast<int>(res) << std::endl;
        }
        else
        {
            std::cout << "char : Impossible" << std::endl;
            std::cout << "int : Impossible" << std::endl;
        }
        std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(res) << "f" << std::endl;
        std::cout << "double : " << res << std::endl;
    }
    else if (type == T_INT)
    {
        int res = stringToNumber(str);
         if(res >= 0 && res <= 255)
                printChar((static_cast<char>(res)));
        else
                std::cout << "char : Impossible" << std::endl;
        std::cout << "int " << static_cast<int>(res) << std::endl;
        std::cout << "float " << std::fixed << std::setprecision(1) << static_cast<float>(res) << "f" << std::endl;
        std::cout << "double " << std::fixed << std::setprecision(1) << static_cast<double>(res) << std::endl;
    }
    else
    {

        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        if (str == "nan")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (str == "-inf")
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else if (str == "inf")
        {
            std::cout << "float: inff" << std::endl;
            std::cout << "double: inf" << std::endl;
        }
        else{
            std::cout << "float: Impossible" << std::endl;
            std::cout << "double: Impossible" << std::endl;
        }
    }
}

void ScalarConverter::convert(std::string str)
{
    short types = NOD;

    if (isChar(str))
        types = T_CHAR;
    else if (isNumber(str))
        types = T_INT;
    else if (isFloat(str))
    {
        if (str.find('f') != std::string::npos)
            types = T_FLOAT;
        else
            types = T_DOUBLE;
    }
    displayTypes(types, str);
}