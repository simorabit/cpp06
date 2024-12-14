#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

bool isNumber(const std::string& str) {
    try {
        // Try to convert string to float
        std::stof(str);
        return true;
    } catch (const std::invalid_argument&) {
        // Invalid string format
        return false;
    } catch (const std::out_of_range&) {
        // The number is out of range for float
        return false;
    }
}

int main() {
    std::string str1 = "123.45";
    std::string str2 = "-456.78f";
    std::string str3 = "abc";
    std::string str4 = "123e4"; // Scientific notation
    int res = std::stof("0");
    std::cout << (char)res << std::endl;
    // std::cout << "Is \"" << str1 << "\" a number? " << (isNumber(str1) ? "Yes" : "No") << std::endl;
    // std::cout << "Is \"" << str2 << "\" a number? " << (isNumber(str2) ? "Yes" : "No") << std::endl;
    // std::cout << "Is \"" << str3 << "\" a number? " << (isNumber(str3) ? "Yes" : "No") << std::endl;
    // std::cout << "Is \"" << str4 << "\" a number? " << (isNumber(str4) ? "Yes" : "No") << std::endl;

    return 0;
}
