#include "io.h"
#include <iostream>
int readNumber()
{
    std::cout<<"input integer : ";
    int a{};
    std::cin>>a;
    return a;
}
void writeAnswer(int input)
{
    std::cout<<"answer is "<<input;
}