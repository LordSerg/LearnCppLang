#include <iostream>
void B(int);
void A(int k)
{
    std::cout<<k<<" ";
    k>0?(B(--k)):(k<0?B(++k):((void)(std::cout<<".")));
}