#include <iostream>
/*
Consider a three dimensional grid of cubes. An amoeba in cube (x, y, z) can divide itself into three amoebas to occupy the cubes
(x + 1, y, z), (x, y + 1, z) and (x, y, z + 1), provided these cubes are empty.
Originally there is only one amoeba in the cube (0, 0, 0). After N divisions there will be 2N+1 amoebas arranged in the grid.
An arrangement may be reached in several different ways but it is only counted once. Let D(N) be the number of different possible 
arrangements after N divisions.
For example, D(2) = 3, D(10) = 44499, D(20)=9204559704 and the last nine digits of D(100) are 780166455.
Find D(10000), enter the last nine digits as your answer.
*/
int main()
{
    long long int k{0};//num of amoebas
    long long int ans{};
//s(i)=i*(i+1)/2 = 1+2+3+4+5+6+...+i 
    auto s = [](int i){return i*(i+1)/2;};
    for(int i{1};i<10;++i)
    {
        int k2 =4*( (i/2)*((i/2)+1)*(2*(i/2)+1)/6);
        if(i%2==1)
            k2+=s(i);
        std::cout<<i<<": "<<k2<<" "<<k2-k<<std::endl;
        k=k2;
    }
    return 0;
}
//only for even n:
//k2 = s(1) + s(2) + s(3) + ... + s(2*n) =
// = (1*2 + 2*3 + 3*4 + ... + 2*n*(2*n+1))/2 =
// = ((1+3)*2 + (3+5)*4 + (5+7)*6 + ... + (2*n-1+2*n+1)*2*n)/2 =
// = (1+3)*1 + (3+5)*2 + (5+7)*3 + ... + (2*2*n)*n =
// = (2+2)*1 + (4+4)*2 + (6+6)*3 + ... + (2n+2n)*n =
// = 1*4 + 2*8 + 3*12 + 4*16 + 5*20 + ... + n*(4*n) =
// = (1^2)*4 + (2^2)*4 + (3^2)*4 + ... + (n^2)*4 =
// = 4*(1^2 + 2^2 + 3^2 + 4^2 + ... + n^2) =
// = 4 * (n*(n+1)*(2*n+1))/6

