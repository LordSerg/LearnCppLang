#include <iostream>
#include <cstdint>
/*
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
*/

int reverse(int x)
{
    int a{};
    int sign{x>=0?1:-1};
    x=abs(x);
    while(x>0)
    {
        if((sign>0&&(a>INT_MAX/10||(a==INT_MAX/10&&(x%10)>7)))//check if more than 2147483647
        ||(sign<0&&(a>INT_MAX/10||(a==INT_MAX/10&&(x%10)>8))))//check if more than 2147483648
            return 0;
        a*=10;
        a+=x%10;
        x/=10;
    }
    return sign*a;
}
int main()
{
    int x{1534236469};
    std::cout<<x<<" -> "<<reverse(x)<<std::endl;
    return 0;
}