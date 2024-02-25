//#define HOHOHO
#define HAHAHA
#include "hohoho.h"
//#include "aboba.h"
#include "aboba.h"
#include <iostream>
//compiler error:
/*
void A(int k)
{
    std::cout<<k<<" ";
    k>0?(B(--k)):(k<0?B(++k):((void)(std::cout<<".")));
}
void B(int k)
{
    std::cout<<k<<" ";
    k>0?(A(--k)):(k<0?A(++k):((void)(std::cout<<".")));
}
*/

//should compile:
/*
void A(int);
void B(int);
void A(int k)
{
    std::cout<<k<<" "<<std::flush;
    k>0?(B(--k)):(k<0?B(++k):((void)(std::cout<<".")));
}
void B(int k)
{
    std::cout<<k<<" "<<std::flush;
    k>0?(A(--k)):(k<0?A(++k):((void)(std::cout<<".")));
}
*/
//works for definition in other files:
/*
void A(int);
void B(int);
*/
int getInteger();
int add(int,int);

int p{add(1,2)};

int main()
{
    /*
    //A(43190);
    //A(45000);
    A(5);
    */

    //qwestion 1, lesson 2.8
    /*
    int x{getInteger()};
    int y{getInteger()};
    std::cout<<x<<" + "<<y<< " is "<< add(x,y)<<std::endl;*/

    
    int a{5};
    int b{3};
    //std::cout<<a<<" + "<<b<<" = "<<math::add(a,b)<<std::endl;
    //std::cout<<a<<" - "<<b<<" = "<<math::sub(a,b)<<std::endl;
    //std::cout<<a<<" * "<<b<<" = "<<math::mult(a,b)<<std::endl;
    //std::cout<<a<<" / "<<b<<" = "<<math::div(a,b)<<std::endl;
    std::cout<<a<<" + "<<b<<" = "<<add(a,b)<<std::endl;
    std::cout<<"p = "<<p<<std::endl;

    hihi();
    hihi();

    kek();
    return 0;
}
