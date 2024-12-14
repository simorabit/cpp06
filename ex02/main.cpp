#include "Base.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int nbr = std::rand() % 3;
    if (nbr == 0)
        return new A();
    if (nbr == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Object A is Created" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Object B is Created" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Object C is Created" << std::endl;
    else
        std::cout << "Error !!!" << std::endl;
}

void identify(Base &p)
{
    try
    {
       A &a = dynamic_cast<A&>(p);
        std::cout << "Object A is Created" << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            std::cout << "Object B is Created" << std::endl;
        }
        catch (const std::bad_cast &e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                std::cout << "Object C is Created" << std::endl;
            }
            catch (const std::bad_cast &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
}

int main()
{
    std::srand(std::time(0));
    A bs = A();
    B bss = B();
    C bsx = C();
    Base *base = generate();
    identify(bsx);
}