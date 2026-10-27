#include <iostream>
#include <string>

int lengthOfLastWord(std::string s) 
{
    int i=s.size();
    while(s[--i]==' ');
    int counter=1;
    while(i>0&&s[--i]!=' ')
    {
        counter++;
    }
    return counter;
}

int main()
{
    std::string input {"Hello World"};
    std::cout<<"The length of the last word in '"<<input<<"' is "<<lengthOfLastWord(input)<<"\n";
}