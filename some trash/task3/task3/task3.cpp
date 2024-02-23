#include <iostream>

int main()
{
    std::cout << "Input a number in range [0;255]: \n";
    int a;
    std::cin >> a;
    //while (a>0)
    //{
    //    if (a % 2 == 1)
    //    {
    //        std::cout << "1";
    //    }
    //    else
    //    {
    //        std::cout << "0";
    //    }
    //    a /= 2;
    //}
    std::cout << std::endl << "binary representation of " << a << " : " << std::endl;
    for (int i = 128; i >= 1; i /= 2)
    {
        if (i == 8)
            std::cout << "'";
        if (a >= i)
        {
            std::cout<<"1";
            a -= i;
        }
        else
        {
            std::cout << "0";
        }
    }
}