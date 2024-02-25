#include <iostream>
#include <bits/stdc++.h>
#include <string>
std::string decimal_string(__int128_t bigBoi)
{
    std::string str;
    do {
        int digit = bigBoi % 10;
        str = std::to_string(digit) + str;
        bigBoi = (bigBoi - digit) / 10;
    } while (bigBoi != 0);
    return str;
}
int doubleNumber(int input)
{
    return input * 2;
}
int getNum()
{
    std::cout<<"enter integer : ";
    int n{};
    std::cin>>n;
    return n;
}
int k{-1};
int main()
{
    /*
    if(k < 0)
    {
        k = []()
        {
            std::cout<<"enter num of elements to input : ";
            int n{};
            std::cin>>n;
            return n;
        }();
        main();
    }
    else
    {
        std::cout<<(getNum()*2)<< " - is doubled input\n";
        return (--k) ? main() : k;
    }
    */
    //auto x{getNum};
    //std::cout<<"typeof(getNum) = "<<(typeid(getNum).name())<<std::endl;
    

    
    //2.4 -> question 4
    //Write a function called doubleNumber() that takes one integer parameter. 
    //The function should return double the value of the parameter.
    /*
    int a{3};
    std::cout<<"double of "<<a<<" is "<<doubleNumber(a)<<std::endl;
    */


    //2.4 -> question 5
    //Write a complete program that reads an integer from the user, 
    //doubles it using the doubleNumber() function you wrote in the previous quiz question, 
    //and then prints the doubled value out to the console.
    /*
    std::cout<<doubleNumber(getNum())<<" - is doubled number\n";
    */
    
    __int128_t suka1{111111111111111};
    __int128_t suka3{suka1*suka1};
    std::cout<<"sizeof(suka1) = "<<sizeof(suka3)<<std::endl;
    std::cout<<"suka1 = "<<decimal_string(suka3)<<std::endl;
    return 0;
}