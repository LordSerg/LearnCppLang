#include <iostream>
#include <bits/stdc++.h>
//https://basecamp.eolymp.com/en/problems/8
int main()
{
    int n{};
    std::cin>>n;
    int min_square {static_cast<int>(std::sqrt(n))};
    int a = 2*(min_square*(min_square+1));//fill main square
    n-=min_square*min_square;
    if(n==0){}
    else if(n<=min_square)
        a+=n*2+1;
    else if(n>min_square)
        a+=n*2+2;
    
    std::cout<<a;
    return 0;
}