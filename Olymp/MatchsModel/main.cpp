#include <iostream>
#include <bits/stdc++.h>
//https://www.eolymp.com/uk/problems/3
int main()
{
    int n{};
    std::cin>>n;
    int min_cube = static_cast<int>(std::pow(n,1.0/3.0));
    int a{min_cube*(min_cube+1)*(min_cube+1)*3};
    n-=min_cube*min_cube*min_cube;
    if(n==0){}
    else if(n<=min_cube*min_cube)
    {
        int min_square = static_cast<int>(std::sqrt(n));
        a+=(min_square+1)*(min_square+1)+(min_square+1)*min_square*2;
        n-=min_square*min_square;
        if(n>0)
        {
            if(n<=min_square)
            {
                a+=3*n+2;
            }
            else //if(n<min_square*min_square)
            {
                a+=3*n+4;
            }
        }
    }
    else //if (n<min_cube*min_cube*3+3*min_cube+1)
    {
        int k = n/(min_cube*min_cube);
        if(k>=3)
        {
            //3 sides + some
            //build 2 sides
            a+=2*((min_cube+1)*(min_cube+1) + (min_cube+1)*min_cube*2);
            n-=min_cube*min_cube*2;

            if(n==0){}
            else 
            {
                //build in-between sides
                if(n<min_cube)
                    a+=3*n+2;
                else if(n>=min_cube)
                    a+=3*min_cube+2;
                n-=min_cube;
                if(n>0)
                {//if there are still cubes - buld third side
                    if(n<min_cube*min_cube)
                    {
                        int min_square = static_cast<int>(std::sqrt(n));
                        a+=(min_square+1)*(min_square+1)+(min_square+1)*min_square*2;
                        n-=min_square*min_square;
                        if(n>0)
                        {
                            if(n<=min_square)
                            {
                                a+=3*n+2;
                            }
                            else //if(n<min_square*min_square)
                            {
                                a+=3*n+4;
                            }
                        }
                    }
                    else if(n>=min_cube*min_cube)
                    {
                        a+=1*((min_cube+1)*(min_cube+1) + (min_cube+1)*min_cube*2);
                        n-=min_cube*min_cube*1;
                        if(n>0)
                        {
                            k=n/(min_cube+1);
                            a+=3*n+2*(k+1);
                        }
                    }
                }
            }
        }
        else if(k==2)
        {
            //2 or 1 sides + some
            
            //build 2 sides
            a+=2*((min_cube+1)*(min_cube+1) + (min_cube+1)*min_cube*2);
            n-=min_cube*min_cube*2;

            if(n==0){}
            else 
            {
                //build in-between sides
                if(n<min_cube)
                    a+=3*n+2;
                else if(n>=min_cube)
                    a+=3*min_cube+2;
                n-=min_cube;
                if(n>0)
                {//if there are still cubes - buld third side
                    int min_square = static_cast<int>(std::sqrt(n));
                    a+=(min_square+1)*(min_square+1)+(min_square+1)*min_square*2;
                    n-=min_square*min_square;
                    if(n>0)
                    {
                        if(n<=min_square)
                        {
                            a+=3*n+2;
                        }
                        else //if(n<min_square*min_square)
                        {
                            a+=3*n+4;
                        }
                    }
                }
            }
        }
        else if(k==1)
        {
            a+=1*((min_cube+1)*(min_cube+1) + (min_cube+1)*min_cube*2);
            n-=min_cube*min_cube*1;

            int min_square = static_cast<int>(std::sqrt(n));
            a+=(min_square+1)*(min_square+1)+(min_square+1)*min_square*2;
            n-=min_square*min_square;
            if(n>0)
            {
                if(n<=min_square)
                {
                    a+=3*n+2;
                }
                else if(n<min_square*min_square)
                {
                    a+=3*n+4;
                }
            }
        }
    }
    std::cout<<a;
    return 0;
}