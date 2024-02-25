#include <iostream>
void A(int);
void B(int k)
{
    std::cout<<k<<" ";
    k>0?(A(--k)):(k<0?A(++k):((void)(std::cout<<".")));
}