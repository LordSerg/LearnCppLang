#include <iostream>

int fib(int n) 
{
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-2)+fib(n-1);
}

int main()
{
    int input = 5;
    std::cout<<"Fib(5) = "<<fib(input)<<"\n";
}