#include <iostream>
#include <string>
/*Given an integer, convert it to a roman numeral.

I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

*/

void doShit(std::string &result, int k, std::string ones, std::string fifth, std::string tens)
{
    if(k==4)
        result+=ones+fifth;
    else if(k==9)
        result+=ones+tens;
    else
    {
        if(k>=5)
            result+=fifth;
        for(int i{};i<k%5;++i)
            result+=ones;
    }
}

std::string intToRoman(int num) 
{// 1<=num<=3999
    std::string result{};
    int k{};
    k=num/1000;
    if(k)
    {
        for(int i{};i<k;++i)
            result+="M";
    }
    k=(num/100)%10;
    if(k)
        doShit(result, k,"C","D","M");
    k=(num/10)%10;
    if(k)
        doShit(result, k,"X","L","C");
    k=num%10;
    if(k)
        doShit(result, k,"I","V","X");
   return result;
}

void test(int n)
{
    std::cout<<n<< " in roman notation is " << intToRoman(n)<<std::endl;
}
int main()
{
    for(int i{};i<100;++i)
        test(i);
    return 0;
}