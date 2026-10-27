#include <iostream>
#include <vector>
#include <string>

void printGrid(std::vector<std::string> g)
{
    for(int i=0;i<g.size();++i)
    {
        std::cout<<g[i]<<std::endl;
    }
}

std::vector<std::string> createGrid(int m, int n)
{
    std::string tmp(n,'#');
    std::vector<std::string> answer(m,tmp);
    for(int i=0;i<m;++i)
    {
        answer[i][0]='.';
    }

    for(int i=0;i<n;++i)
    {
        answer[m-1][i]='.';
    }

    return answer;
}
int main()
{
    int m=10,n=20;
    printGrid(createGrid(m,n));
}