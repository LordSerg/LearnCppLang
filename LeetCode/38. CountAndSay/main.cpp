#include <iostream>
#include <string>
#include <vector>

/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

 - countAndSay(1) = "1"
 - countAndSay(n) is the run-length encoding of countAndSay(n - 1).

Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical 
characters (repeated 2 or more times) with the concatenation of the character and the number marking 
the count of the characters (length of the run). For example, 
to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the n-th element of the count-and-say sequence.
*/

std::string countAndSay(int n)
{
    std::string result = "1";
    std::string tmp{};
    for(int j=1;j<n;j++)
    {
        tmp="";
        for(int i=0;i<result.size();i++)
        {
            char t = result[i];
            int k=1;
            while((i+1<result.size())&&(result[i]==result[i+1]))
            {
                k++;
                i++;
            }
            tmp += ('0'+k);
            tmp += t;
        }
        result = tmp;
    }
    return result;
}

int main()
{
    for(int i=1;i<5;++i)
        std::cout<<i<< " -> " <<countAndSay(i)<<"\n";
}