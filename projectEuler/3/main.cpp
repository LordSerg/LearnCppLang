#include <iostream>
/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143?
*/
int main()
{
    long long int a{600851475143};
    long long int a_const{600851475143};
    long long int max{};

    for(long long int i{2};i<=a; ++i)
    {
        if(a%i==0)
        {
            std::cout<<i<<" rooms -> "<<(a_const/i)<<" warriors per room\n";
            if(max<i)max=i;
            a/=i;
            i--;
        }
    }
    std::cout<<max<<std::endl;//6857
    return 0;
}