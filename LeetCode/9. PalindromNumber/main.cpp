#include <iostream>
#include <string>
/*
Given an integer x, return true if x is a palindrome, and false otherwise.
*/

//my solution
/*
bool isPalindrome(int x) 
{
    std::string s = std::to_string(x);
    int i{};
    while(i<s.length()&&s[i]==(s[s.length()-1-i]))
        ++i;
    if(i==s.length())
        return true;
    return false;
}
*/

//fast solution

bool isPalindrome(int x) 
{
    if (x < 0) 
        return false;

    long long r = 0;
    long long t = x;

    while (t != 0) 
    {
        r = r * 10 + t%10;
        t /= 10;
    }

    return (r == x);
}


int main()
{
    std::cout<<isPalindrome(121)<<std::endl;
    std::cout<<isPalindrome(-121)<<std::endl;
    std::cout<<isPalindrome(10)<<std::endl;
    std::cout<<isPalindrome(11)<<std::endl;
    return 0;
}