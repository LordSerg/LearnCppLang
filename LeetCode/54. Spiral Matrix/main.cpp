#include <iostream>
#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& m) 
{
    int imin=0,imax=m.size(),jmin=-1,jmax=m[0].size();
    std::vector<int> answer{};
    int i=0, j=0;
    int idir=1;
    int jdir=1;

    int limit = imax*jmax;
    while(limit>0&&(jmax-jmin>1||imax-imin>1))
    {
        while(limit>0&&j+jdir<jmax&&j+jdir>jmin)
        {
            answer.push_back(m[i][j]);
            j+=jdir;
            limit--;
        }
        if(limit<0)
        {
            break;
        }
        if(j+jdir==jmax)
        {
            jmax--;
        }
        else if(j+jdir==jmin)
        {
            jmin++;
        }
        jdir*=-1;
        while(limit>0&&i+idir<imax&&i+idir>imin)
        {
            answer.push_back(m[i][j]);
            i+=idir;
            limit--;
        }
        if(i+idir==imax)
        {
            imax--;
        }
        else if(i+idir==imin)
        {
            imin++;
        }
        idir*=-1;
    }
    if(limit>0)
        answer.push_back(m[i][j]);
    return answer;
}

void printMatrix(std::vector<std::vector<int>>& m)
{
    for(auto v:m)
    {
        for(auto i:v)
        {
            std::cout<<i<<" ";
        }
        std::cout<<"\n";
    }
}

int main()
{
    std::vector<std::vector<int>> input = {{1,2,3},{4,5,6},{7,8,9}};
    std::cout<<"matrix view:\n";
    printMatrix(input);
    std::cout<<"spiral:\n";
    auto answer = spiralOrder(input);
    for(auto i:answer)
    {
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
}