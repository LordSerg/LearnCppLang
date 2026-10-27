#include <iostream>
#include <vector>
#include <string>

void reverse(std::vector<char>& s, int i)
{
    if(i<s.size()/2)
    {
        char t = s[i];
        s[i] = s[s.size()-1-i];
        s[s.size()-1-i] = t;
        i++;
        reverse(s,i);
    }
}

void reverseString(std::vector<char>& s)
{
    reverse(s, 0);
}

void printChars(std::vector<char>& s)
{
    for(char ch:s)
    {
        std::cout<<ch;
    }
}

int main()
{
    std::vector<char> input{'h','e','l','l','o'};
    printChars(input);
    std::cout<<" is a reverse of ";
    reverseString(input);
    printChars(input);
    std::cout<<"\n";
}