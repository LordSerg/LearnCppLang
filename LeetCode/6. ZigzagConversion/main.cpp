#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
*/

std::string convert(std::string s, int numRows) 
{
    if(numRows<=1)
        return s;
    
    std::string s2{};
    int step1{numRows*2-2};
    int step2{};
    int i{};
    int k{};
    while(s2.length()<s.length())
    {
        if(i<s.length())
        {
            s2.push_back(s[i]);
            i+=step1;
            if((i-step1+step2)<s.length()&&k%(numRows-1)!=0)
                s2.push_back(s[i-step1+step2]);
        }
        else
        {
            ++k;
            step2 = (numRows-k)*2-2;
            i=k;
        }
    }
    return s2;
}

int main()
{
    /*
    std::string copy{"abob"};
    auto ptr=copy.begin();
    std::string spacesA(100,'1');
    std::generate(spacesA.begin(),spacesA.end(),
    [&]()->char{
            if(ptr==copy.end())
                ptr=copy.begin();
            return *ptr++;
    });
    std::cout<<spacesA;
    */

    std::cout<< convert("PAYPALISHIRING",4);

    /*
    std::string s{"123"};
    std::cout<<s.replace(1,1,"x");
    */
    
    return 0;
}