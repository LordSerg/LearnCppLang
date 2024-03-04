#include <iostream>
#include <string>
#include <vector>
#include <cmath>
/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
*/

bool isMatch(std::string s, std::string p)
{
    //4 variants:
    //1) p doesn't have neither '.' nor '*' in it
    //2) p have '.' in it, but don't have '*'
    //3) p have '*' in it, but don't have '.'
    //4) p has both '.' and '*' in it

return false;
}
bool isPrime(long long n)
{
    int f{};
    for(long long i{1};i<=n/2;++i)
    {
        if(n%i==0)
        {
            f+=2;
        }
    }
    return (f==2);
}
int main()
{
    std::vector<long long> a{1,4};
    long long k{3};
    long long factors{};
    long long n{1};
    while (n<50)
    {
        if(isPrime(n))
        {
            long long aboba=1;
            for(int i{};i<n-1;++i)
            {
                aboba*=2;
            }
            std::cout<<n<<" -> "<<aboba*3<<std::endl;
        }
        ++n;
    }
    return 0;
}