#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>>& m) 
{
    //double simmetry is a rotation
    int n = m.size();
    //second diagonal simmetry:
    for(int i=0;i<n-1;++i)
    {
        for(int j=0;j<n-i-1;++j)
        {
            //a=a+b;
            //b=a-b;
            //a=a-b;
            //swap m[i,j] and m[n-1-j,n-1-i]
            m[i][j]+=m[n-1-j][n-1-i];
            m[n-1-j][n-1-i]=m[i][j]-m[n-1-j][n-1-i];
            m[i][j]-=m[n-1-j][n-1-i];
        }
    }
    //horisontal simmetry
    for(int i=0;i<n/2;++i)
    {
        for(int j=0;j<n;++j)
        {
            //a=a+b;
            //b=a-b;
            //a=a-b;
            //swap m[i,j] and m[n-i,j]
            m[i][j]+=m[n-i-1][j];
            m[n-i-1][j]=m[i][j]-m[n-i-1][j];
            m[i][j]-=m[n-i-1][j];
        }
    }
}

void printMatrix(std::vector<std::vector<int>>& m)
{
    int n = m.size();
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
    std::vector<std::vector<int>> input{{1,2,3},{4,5,6},{7,8,9}};
    std::cout<<"matrix before rotation: \n";
    printMatrix(input);
    rotate(input);
    std::cout<<"matrix after rotation: \n";
    printMatrix(input);
}