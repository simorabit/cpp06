#include "ScalarConverter.hpp"

int main(int argc, char *arv[])
{
    if(argc >= 2)
    {
        ScalarConverter::convert(arv[1]);
    }
}