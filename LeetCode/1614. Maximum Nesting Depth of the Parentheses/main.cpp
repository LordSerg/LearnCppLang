#include <iostream>
#include <string>

int maxDepth(std::string s) 
{
    int i=0, imax=0;
    for(char ch : s)
    {
        if(ch == '(')
        {
            i++;
            if(imax<i)
            {
                imax = i;
            }
        }
        if(ch == ')')
        {
            i--;
        }
    }
    return imax;
}

int main()
{
    std::string input{"()(())((()()))"};
    std::cout<<"the depth of parentheses '"<<input<<"' is "<<maxDepth(input)<<"\n";
}