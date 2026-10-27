#include <iostream>
#include <string>

std::string reversePrefix(std::string word, char ch) 
{
    int k = 0;
    if((k = word.find(ch)) == std::string::npos)
        return word;
    for(int i=0;i<=k/2;++i)
    {
        char t = word[i];
        word[i] = word[k-i];
        word[k-i] = t;
    }
    return word;
}

int main()
{
    std::string input{"abcdefd"};
    char ch = 'd';
    std::cout<<"before: "<<input<<"\n";
    std::cout<<"after: "<<reversePrefix(input, ch)<<"\n";
}