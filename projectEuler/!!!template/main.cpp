#include <iostream>

int main()
{
    auto result = (10 <=> 20) > 0;
    std::cout<< result;
    return 0;
}