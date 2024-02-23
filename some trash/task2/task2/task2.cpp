#include <iostream>
#include "constants.h"
double count(double a, char ch, double b)
{
    double result = a;
    if (ch == '+')result += b;
    if (ch == '-')result -= b;
    if (ch == '*')result *= b;
    if (ch == '/')result /= b;
    return result;
}
void fallingBallSecBySec(int seconds, double height)
{
    double h;
    for (int i = 0; i <= seconds; i++)
    {
        h = height - myConstants::gEarth * i * i / 2.0;
        if (h <= 0)
            std::cout << "At " << i << " seconds, the ball is on the ground" << std::endl;
        else
            std::cout << "At " << i << " seconds, the ball is at height : " << h << " meters" << std::endl;
    }
}
int main()
{/*
    std::cout << "bool:\t\t\t"<<sizeof(bool)<<std::endl;
    std::cout << "char:\t\t\t"<<sizeof(char)<<std::endl;
    std::cout << "wchar_t:\t\t"<<sizeof(wchar_t)<<std::endl;
    //std::cout << "char8_t:\t"<<sizeof(char8_t)<<std::endl;//?
    std::cout << "char16_t:\t\t"<<sizeof(char16_t)<<std::endl;
    std::cout << "char32_t:\t\t"<<sizeof(char32_t)<<std::endl;
    std::cout << "short:\t\t\t"<<sizeof(short)<<std::endl;
    std::cout << "int:\t\t\t"<<sizeof(int)<<std::endl;
    std::cout << "long:\t\t\t"<<sizeof(long)<<std::endl;
    std::cout << "long long:\t\t"<<sizeof(long long)<<std::endl;
    std::cout << "float:\t\t\t"<<sizeof(float)<<std::endl;
    std::cout << "double:\t\t\t"<<sizeof(double)<<std::endl;
    std::cout << "long double:\t\t"<<sizeof(long double)<<std::endl;
    std::cout << "long int:\t\t"<<sizeof(long int)<<std::endl;
    std::cout << "long float:\t\t"<<sizeof(long float)<<std::endl;
    std::cout << "std::string:\t\t"<<sizeof(std::string)<<" \tif x64 system: 40; if x86 system: 28" << std::endl;
    std::cout << "std::u16string:\t\t"<<sizeof(std::u16string)<<" \tif x64 system: 40; if x86 system: 28" << std::endl;
    std::cout << "std::u32string:\t\t"<<sizeof(std::u32string)<<" \tif x64 system: 40; if x86 system: 28" << std::endl;
    std::cout << "std::int8_t:\t\t"<<sizeof(std::int8_t)<<" " << std::endl;
    std::cout << "std::int16_t:\t\t"<<sizeof(std::int16_t)<<" " << std::endl;
    std::cout << "std::int32_t:\t\t"<<sizeof(std::int32_t)<<" " << std::endl;
    std::cout << "std::int64_t:\t\t"<<sizeof(std::int64_t)<<" " << std::endl;
    std::cout << "std::float_t:\t\t"<<sizeof(std::float_t)<<" " << std::endl;
    std::cout << "std::double_t:\t\t"<<sizeof(std::double_t)<<" " << std::endl;
    std::cout << "std::atomic_schar:\t"<<sizeof(std::atomic_schar)<<" " << std::endl;
    std::cout << "std::atomic_uchar:\t"<<sizeof(std::atomic_uchar)<<" " << std::endl;
    std::cout << "std::atomic_wchar_t:\t"<<sizeof(std::atomic_wchar_t)<<" " << std::endl;
    std::cout << "std::uint8_t:\t\t"<<sizeof(std::uint8_t)<<" " << std::endl;
    std::cout << "std::uint16_t:\t\t"<<sizeof(std::uint16_t)<<" " << std::endl;
    std::cout << "std::uint32_t:\t\t"<<sizeof(std::uint32_t)<<" " << std::endl;
    std::cout << "std::uint64_t:\t\t"<<sizeof(std::uint64_t)<<" " << std::endl;
    std::cout << "std::uintmax_t:\t\t"<<sizeof(std::uintmax_t)<<" " << std::endl;
    */
    /*
    std::cout << "\a";std::system("pause");
    std::cout << "\a";std::system("pause");
    std::cout << "\a";std::system("pause");
    std::cout << "\a";std::system("pause");
    std::cout << "\a";std::system("pause");
    std::cout << "\a";std::system("pause");
    */

    //std::string str = "wqerqwerqwer" " o o o o o " "ogo";
    //std::cout << "1234" "asdf" <<str;
    //task 2.3:
    /*
    double a, b;
    char action;
    std::cout << "Enter some number: ";
    std::cin >> a;
    std::cout << "Enter one of the following : +, -, *, or / : ";
    std::cin >> action;
    std::cout << "Enter some other number: ";
    std::cin >> b;
    if (action == '+' ||
        action == '-' ||
        action == '*' ||
        action == '/')
        std::cout << a << " " << action << " " << b << " = " << count(a, action, b) << std::endl;
    */
    //task 2.4:
    std::cout << "Enter the initial height of the tower in meters: ";
    int h;
    std::cin >> h;
    fallingBallSecBySec(5, h);
    std::system("pause");
}