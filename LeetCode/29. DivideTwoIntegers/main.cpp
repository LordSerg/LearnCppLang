#include <iostream>
#include <cmath>
/*
Given two integers 'dividend' and 'divisor', divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. 
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.


Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0
*/
// a/b = e^(log(a))/e^(log(b)) = e^(log(a)-log(b))

int checkForExtreme(long long a)
{
    if(a<-2147483648)
        return -2147483648;
    if(a>2147483647) 
        return 2147483647;
    return static_cast<int>(a);
}
long long int myAbs(long long int a)
{
    if(a<0)
        return -a;
    return a;
}
int divide(int dividend, int divisor)
{
    long long int a=static_cast<long long int>(dividend);
    long long int b=static_cast<long long int>(divisor);

    if(a==0)
        return 0;
    int sign{(a<0)^(b<0)};
    a = myAbs(static_cast<long long int>(a));//use myAbs() because standart abs() - sucks
    b = myAbs(static_cast<long long int>(b));
    if(b==1)
        return checkForExtreme((sign==0)?(a):(-a));
    int ans {static_cast<int>(exp(log(a)-log(b))+0.0000000001)};
    return checkForExtreme((sign==0)?ans:(-ans));
}

int main()
{
    //long long int a = -2147483648;
    //std::cout<<a<<std::endl;
    //std::cout<<abs(a)<<std::endl;
    //std::cout<<myAbs(a)<<std::endl;
    std::cout<<divide(-2147483648,-1)<<std::endl;
    return 0;
}