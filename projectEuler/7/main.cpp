#include <iostream>

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10001st prime number?
*/
//answer = 104743
bool is_prime(long long int n)
{
    for (long long int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    long long int a=2;
    int n=10001;
    for(int i=2;i<=n;i++)
    {
        a++;
        while(!is_prime(a))a++;
        
    }
    std::cout<< n <<"th prime = " << a<<"\n";
}