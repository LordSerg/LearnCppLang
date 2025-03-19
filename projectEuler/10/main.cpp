#include <iostream>
/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/
//answer = 142913828922
bool is_prime(long long int n)
{
    for (long long int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int a=2;
    int n=2000000;
    unsigned long long int sum=0;
    
    for(;a<n;a++)
    {
        if(is_prime(a))
            sum+=a;
        if(a%1000==0)
            std::cout<<a <<" : "<<sum<<"\n";
    }
    std::cout<< "sum of all primes below "<<n<<" = " << sum<<"\n";
}